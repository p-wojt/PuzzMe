#include "board.h"
#include <QLabel>
#include <QList>
#include <iostream>
#include <QImage>

Board::Board(Ui::MainWindow *ui)
{
    this->ui = ui;
    this->size = 3;
    this->cells = new QList<QLabel*>();
}

void Board::setup() {
    this->initializeNumberCells();
    this->displayCells();
}

void Board::initializeNumberCells() {
    this->cells->clear();

    for(int i = 1; i <= size*size; i++){
        QLabel *label = new QLabel(QString::number(i));
        label->setStyleSheet("border: 1px solid red; qproperty-alignment: AlignCenter;");
        cells->append(label);
    }
}


void Board::initializeImageCells(QImage *image) {
    this->cells->clear();

    int w = this->ui->board->maximumSize().width(), h = this->ui->board->maximumSize().height();

    QPixmap pixmap = QPixmap::fromImage(image->scaled(300, 300, Qt::KeepAspectRatio));
    int cellWidthSize = w/(this->size*this->size);
    int cellHeightSize = h/(this->size*this->size);
    QRect rect(cellHeightSize, cellWidthSize, cellHeightSize, cellWidthSize);
    for (int i = 1 ; i <= this->size ; i++) {
        for( int j = 1; j <= this->size; j++) {
            rect.setX(cellWidthSize*j);
            QPixmap cell = pixmap.copy(rect);
            QLabel *label = new QLabel();
            label->setPixmap(cell);
            cells->append(label);
        }
        rect.setY(cellHeightSize*i);
    }
//    for(int i = 1; i <= size*size; i++){

//    }
}


void Board::displayCells() {
    int counter = 0;
    for(int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++, counter++) {
            this->ui->board->addWidget(this->cells->at(counter), i, j);
        }
    }
}
