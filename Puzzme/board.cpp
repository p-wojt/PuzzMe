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
    this->size = 4;
    this->cells = new QList<Cell*>();
    this->areNumberCells = true;
    this->image = nullptr;
    this->scaledPixmap = nullptr;
//    connect(this, SIGNAL(clicked()), this, SLOT(boardClicked()));

    this->ui->boardFrame->connect(this, SIGNAL(clicked()), this, SLOT(boardClicked()));
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
    QPixmap pixmap = QPixmap::fromImage(this->image->scaled(size.width(), size.height()));

    int counter = 0;
    int cellEdgeHeight = this->cells->at(0)->height();
    int cellEdgeWidth = this->cells->at(0)->width();
    for (int i = 0 ; i < this->size ; i++) {
        for( int j = 0; j < this->size; j++) {
            const QPoint *topleft = new QPoint(j*cellEdgeWidth, i*cellEdgeHeight);
            const QPoint *bottomright = new QPoint(((j+1)*cellEdgeWidth), (i+1)*cellEdgeHeight);
            QRect rect(*topleft, *bottomright);
            QPixmap cellPixmap = pixmap.copy(rect);

            this->cells->at(counter)->setImagePixmap(&cellPixmap);
            if(!this->cells->at(counter)->isBlank()){
                this->cells->at(counter)->setPixmapAsImage();
            }
//            qDebug() << "i=" << i << " " << "j=" <<j;
//            qDebug() << "[" << topleft->x() << "," << topleft->y() << "]" << "===" << "[" << bottomright->x() << "," << bottomright->y() << "]";
            counter++;
        }
    }
}

void Board::setImage(QImage *image)
{
    this->image = image;
}


void Board::displayCells() {
    qDebug() << ui->board->count();
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
//    Cell *temp = this->cells->last();
//    QPixmap *placeholder = new QPixmap();
//    temp->setPixmap(*placeholder);
//    temp->setBlank(true);
//    this->cells->replace(this->cells->size()-1, temp);
    this->cells->last()->setAsBlank();
}

void Board::startGame() {
    //reset blankCell
    for(int k = 0 ; k < this->cells->size(); k++) {
        Cell *cell = this->cells->at(k);
        if(cell->isBlank()){
            cell->setBlank(false);
            if(this->areNumberCells) {
                cell->setPixmapAsNumber();
            } else {
                cell->setPixmapAsImage();
            }
            break;
        }
    }
    //set new BlankCell
    this->setBlankCell();
    this->shuffle();
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

void Board::boardClicked()
{
    qDebug() << "test";
}

void Board::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "test";
    emit clicked();
}
