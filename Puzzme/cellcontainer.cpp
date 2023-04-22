#include "cellcontainer.h"
#include "gameutils.h"
#include "QObject"

void CellContainer::initializeCells(const unsigned short boardSize)
{
    this->clear();

    int counter = 1;
    for(int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            Cell *cell = new Cell(counter, i, j, QString::number(counter)); //wcześniej było z parentem (this) na końcu do boarda
            setCellStyles(cell);
            connect(cell, &Cell::cellClicked, this, &CellContainer::onCellClicked);
            this->append(cell);
            counter++;
        }
    }

    GameUtils::areNumberCellsActive = true;
}

//setBlankCell
void CellContainer::initializeBlankCell()
{
    blankCell = this->last();
    blankCell->setAsBlank();
    for(int i = 0; i < this->size(); i++) {
        Cell *temp = this->at(i);
        if(temp->getId() > blankCell->getId()) {
            temp->setId(temp->getId() - 1);
        }
    }
    blankCell->setId(this->size());
}

void CellContainer::setImagePixmapsToCells(QList<QPixmap*> *clippings)
{
    for(int i = 0; i < this->size(); i++) {
        this->at(i)->setImagePixmap(clippings->at(this->at(i)->getId()-1));
    }
}

void CellContainer::setImagePixmapsVisibleBesidesBlank()
{
    for(int i = 0; i < this->size(); i++) {
        if(!this->at(i)->isBlank()){
            this->at(i)->setPixmapAsImage();
        }
    }

    GameUtils::areNumberCellsActive = false;
}

void CellContainer::setCellStyles(Cell *cell)
{
    cell->setStyleSheet("border: 1px solid #F8F8F8; qproperty-alignment: AlignCenter; color: #F8F8F8; font-size: 24px;");
}

void CellContainer::setInitialPostions(const unsigned short boardSize)
{
    std::sort(begin(), end(), [](Cell* a, Cell* b) {
        return a->getId() < b->getId();
    });

    unsigned short counter = 0;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++){
            at(counter)->setX(j);
            at(counter)->setY(i);
        }
    }
}

bool CellContainer::changeToOppositeVisibilty()
{   
    for(int i = 0; i<this->size(); i++) {
        if(!this->at(i)->isBlank()) {
            if(GameUtils::areNumberCellsActive) {
                if(this->at(i)->isImageSet()) {
                    this->at(i)->setPixmapAsImage();
                } else {
                    return false;
                }
            } else {
                this->at(i)->setPixmapAsNumber();
            }
        }
    }
    return true;
}

void CellContainer::shuffle(unsigned short boardSize) {
    std::random_shuffle(this->begin(), this->end());
    int counter = 0;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            this->at(counter)->setX(j);
            this->at(counter)->setY(i);
            counter++;
        }
    }
}

//startGame
void CellContainer::resetBlankToNormalCell()
{
    blankCell->setBlank(false);
    if(GameUtils::areNumberCellsActive) {
        blankCell->setPixmapAsNumber();
    } else {
        blankCell->setPixmapAsImage();
    }
}

void CellContainer::swapCellAndBlankPosition(Cell *cell)
{
    int firstIndex = -1, secondIndex = -1;
    for(int i = 0; i < this->size(); i++) {
        if(this->at(i)->getId() == cell->getId()) {
            firstIndex = i;
        } else if(this->at(i)->isBlank()) {
            secondIndex = i;
        }
        if(firstIndex != -1 && secondIndex != -1) {
            break;
        }
    }
    int tempNumber = cell->getX();
    cell->setX(blankCell->getX());
    blankCell->setX(tempNumber);
    tempNumber = cell->getY();
    cell->setY(blankCell->getY());
    blankCell->setY(tempNumber);
    this->swapItemsAt(firstIndex, secondIndex);
}

bool CellContainer::isCellCloseToBlank(Cell *cell)
{
    return abs(cell->getX() - blankCell->getX()) <= 1
            && abs(cell->getY() - blankCell->getY()) <= 1
            && !(abs(cell->getY() - blankCell->getY()) == abs(cell->getX() - blankCell->getX()));
}

bool CellContainer::areIdsLinedUp()
{
    for(int i = 1; i <= this->size(); i++) {
        if(this->at(i-1)->getId() != i){
            return false;
        }
    }
    return true;
}

void CellContainer::onCellClicked(Cell *cell)
{
    if(cell->isBlank()) {
        return;
    }

    qDebug() << "Cell został kliknięty o id: " <<cell->getId();

    if(isCellCloseToBlank(cell)) {
        swapCellAndBlankPosition(cell);
    }

    if(areIdsLinedUp()) {
        resetBlankToNormalCell();
        emit cellsLinedUpSingal();
    }
    emit refreshBoardSignal();
}

int CellContainer::getCellsWidth()
{
    return this->size() > 0 ? this->at(0)->width() : 0;
}

int CellContainer::getCellsHeight()
{
    return this->size() > 0 ? this->at(0)->height() : 0;
}
