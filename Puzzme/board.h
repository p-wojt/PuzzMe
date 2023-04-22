#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QList>
#include "cell.h"
#include "cellcontainer.h"
#include "croppedimage.h"
#include "validator.h"

class Board : public QWidget
{
public:
    Board(Ui::MainWindow *ui);
    void setImageToCells();
    void resetCellsToInitialPositions();
    bool setupCroppedImage();
    void setupCellsImage();
    void refreshBoardView();
    void changeCellsToOppositeVisibility();
    void initializeCells();
//    void setBlankCell();
    void setup();
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
    unsigned short size;
    CellContainer *cellContainer;
    CroppedImage *croppedImage;
    Validator<QString> *imageValidator;
//    QList<Cell*> *cells;
//    Cell* blankCell;
//    QImage *image;
//    bool areNumberCells;
//    QPixmap *scaledPixmap;
public slots:
    void onCellsLinedUp();
    void onRefreshBoard();
};

#endif // BOARD_H
