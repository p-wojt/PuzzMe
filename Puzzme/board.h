#ifndef BOARD_H
#define BOARD_H

#include "./ui_mainwindow.h"
#include "cellcontainer.h"
#include "croppedimage.h"
#include "validator.h"

class Board : public QWidget
{
public:
    Board(Ui::MainWindow *ui);
    void resetCellsToInitialPositions();
    bool setupCroppedImage();
    void setupCellsImage();
    void refreshBoardView();
    void changeCellsToOppositeVisibility();
    void initializeCells();
    void setup();
    void startGame();
    void clearBoard();
    void setSize(unsigned short size);
private:
    Ui::MainWindow *ui;
    unsigned short size;
    CellContainer *cellContainer;
    CroppedImage *croppedImage;
    Validator<QString> *imageValidator;
public slots:
    void onCellsLinedUp();
    void onRefreshBoard();
};

#endif // BOARD_H
