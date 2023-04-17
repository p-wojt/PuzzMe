#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QList>
#include "cell.h"

class Board : public QWidget
{
public:
    Board(Ui::MainWindow *ui);
    void initializeNumberCells();
    void setImageToCells();
    void setImage(QImage *image);
    void displayCells();
    void setBlankCell();
    void setup();
    void shuffle();
    void startGame();
    void clearBoard();
    void setScaledPixmap(QSize size);
    void swapCells(Cell *cell);
    void setSize(short unsigned int size)
    {
        this->size = size;
    }
    void changeState();
    bool getAreNumberCells() const;

private:
    Ui::MainWindow *ui;
    short unsigned int size;
    QList<Cell*> *cells;
    Cell* blankCell;
    QImage *image;
    bool areNumberCells;
    QPixmap *scaledPixmap;
public slots:
    void onCellClicked(const unsigned int id);


};

#endif // BOARD_H
