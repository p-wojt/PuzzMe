#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QList>
#include <QLabel>

class Board : public QObject
{
    Q_OBJECT
public:
    Board(Ui::MainWindow *ui);
    void initializeNumberCells();
    void initializeImageCells(QImage *image);
    void displayCells();
    void setup();
private:
    Ui::MainWindow *ui;
    short unsigned int size;
    QList<QLabel*> *cells;
};

#endif // BOARD_H
