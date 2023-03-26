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

    QPixmap pixmap = QPixmap::fromImage(image->scaled(300, 300, Qt::KeepAspectRatio));
    QRect rect(33, 33, 33, 33);
    QPixmap cell = pixmap.copy(rect);
    for(int i = 1; i <= size*size; i++){
        QLabel *label = new QLabel();
        label->setPixmap(cell);
        cells->append(label);
    }
}


void Board::displayCells() {
    int counter = 0;
    for(int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++, counter++) {
            this->ui->board->addWidget(this->cells->at(counter), i, j);
        }
    }
}
