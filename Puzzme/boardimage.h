#ifndef BOARDIMAGE_H
#define BOARDIMAGE_H

#include "board.h"

class BoardImage : public Board
{
public:
    BoardImage(Ui::MainWindow *ui);
    // Board interface
public:
    void initializeCells();
};

#endif // BOARDIMAGE_H
