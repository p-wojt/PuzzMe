#include "board.h"
#include <QLabel>
#include <QList>
#include <iostream>
#include <QImage>
#include "cell.h"
#include <QSize>

Board::Board(Ui::MainWindow *ui)
{
    this->ui = ui;
    this->size = 3;
    this->cells = new QList<Cell*>();
    this->areNumberCells = true;
    this->image = nullptr;
    this->scaledPixmap = nullptr;
}

void Board::setup() {
    this->initializeNumberCells();
    this->displayCells();
}

void Board::initializeNumberCells() {
    this->cells->clear();
    this->areNumberCells = true;

    int counter = 1;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Cell *cell = new Cell(counter, i, j, QString::number(counter));
            cell->setStyleSheet("border: 1px solid red; qproperty-alignment: AlignCenter;");
            this->cells->append(cell);
            counter++;
        }
    }
}


void Board::setImageToCells() {
    this->areNumberCells = false;

    QSize size = this->ui->boardFrame->frameSize();
    qDebug() << size.width();
    qDebug() << size.height();
    qDebug() << "Czy jest obrazek do skalowania? " << this->image;
    QPixmap pixmap = QPixmap::fromImage(this->image->scaled(size.width(), size.height()));
    //lista obrazków albo pobieram obrazki i ustawiam dla określonych id

//    for (int i = 0; i < this->cells->size(); i++) {
//        Cell *cell = this->cells->at(i);
//    }
    int counter = 1;
    int cellEdgeHeight = this->cells->at(0)->height();
    int cellEdgeWidth = this->cells->at(0)->width();
    for (int i = 0 ; i < this->size ; i++) {
        for( int j = 0; j < this->size; j++) {

            const QPoint *topleft = new QPoint(j*cellEdgeWidth, i*cellEdgeHeight);
            const QPoint *bottomright = new QPoint(((j+1)*cellEdgeWidth), (i+1)*cellEdgeHeight);

            QRect rect(*topleft, *bottomright);
//            rect.setX(cellWidthSize*j);
            qDebug() << "przed copy";
            QPixmap cellPixmap = pixmap.copy(rect);
            this->cells->at(counter-1)->setImagePixmap(&cellPixmap);
            if(!this->cells->at(counter-1)->isBlank()){
                this->cells->at(counter-1)->setPixmapAsImage();
            }
            qDebug() << "i=" << i << " " << "j=" <<j;
            qDebug() << "[" << topleft->x() << "," << topleft->y() << "]" << "===" << "[" << bottomright->x() << "," << bottomright->y() << "]";
//            if(this->cells->at(counter-1)->getId() == counter && !this->cells->at(counter-1)->isBlank()) {

//            }
//            for(int k = 0; k < this->cells->size(); k++) {
//                if(this->cells->at(k)->getId() == counter && !this->cells->at(k)->isBlank()) {
//                    cells->at(k)->setPixmap(cell);
//                    break;
//                }
//            }
            counter++;
        }
    }
//    for(int i = 1; i <= size*size; i++){

    //    }
}

void Board::setImage(QImage *image)
{
    this->image = image;
}


void Board::displayCells() {
    int counter = 0;
    for(int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++, counter++) {
            this->ui->board->addWidget(this->cells->at(counter), i, j);
        }
    }
}

void Board::shuffle() {
    std::random_shuffle(this->cells->begin(), this->cells->end());
    int counter = 0;
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size; j++) {
            this->cells->at(counter)->setX(j);
            this->cells->at(counter)->setY(i);
            counter++;
        }
    }
}

void Board::setBlankCell() {
    Cell *temp = this->cells->last();
    QPixmap *placeholder = new QPixmap();
    temp->setPixmap(*placeholder);
    temp->setBlank(true);
    this->cells->replace(this->cells->size()-1, temp);
}

void Board::startGame() {
//    this->cells->clear();
//    this->clearBoard();
//    this->initializeNumberCells();
    for(int k = 0 ; k < this->cells->size(); k++) {
        if(this->cells->at(k)->isBlank()){
            this->cells->at(k)->setBlank(false);
            if(this->image == nullptr) {
                this->cells->at(k)->setText(QString::number(this->cells->at(k)->getId()));
            } else {
                QSize size = this->ui->boardFrame->frameSize();
                QPixmap pixmap = QPixmap::fromImage(this->image->scaled(size.width(), size.height()));
                int cellEdgeHeight = this->cells->at(0)->height();
                int cellEdgeWidth = this->cells->at(0)->width();
                const QPoint *topleft = new QPoint(this->cells->at(k)->getX()*cellEdgeWidth, this->cells->at(k)->getY()*cellEdgeHeight);
                const QPoint *bottomright = new QPoint(((this->cells->at(k)->getX()+1)*cellEdgeWidth), (this->cells->at(k)->getY()+1)*cellEdgeHeight);
                QRect rect(*topleft, *bottomright);
                QPixmap cell = pixmap.copy(rect);
                cells->at(k)->setPixmap(cell);
                qDebug() << " ZAMIENILEM";
            }

            break;
        }
    }
    this->setBlankCell();
    this->shuffle();
    if(this->image != nullptr) {
        qDebug() << "Obrazek: " << this->image;
//        this->setImageToCells();
    } else {
        qDebug() << "Nie ma: " << this->image;
    }
//    this->setImageToCells();
//    this->initializeNumberCells();
    qDebug() << "To SHUFFLE";
    this->displayCells();
}

void Board::clearBoard() {
    qDebug() << "liczba dzieci: " << this->ui->board->count();
    while(this->ui->board->count()){
        QLayoutItem *child = this->ui->board->takeAt(0);
        if(child != nullptr) {
            delete child->widget();
        }
    }
//    for(int i = 0; i < ui->board->)
    //    this->ui->board->removeWidget()
}

void Board::setScaledPixmap(QSize size)
{
    if(this->image) {
        QPixmap pixmap = QPixmap::fromImage(this->image->scaled(size.width(), size.height()));
        qDebug() << "scalujemy image";
        this->scaledPixmap = &pixmap;
        qDebug() << this->scaledPixmap;
    }

}
