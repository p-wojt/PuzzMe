#ifndef BOARDNUMBER_H
#define BOARDNUMBER_H

#include "board.h"

class BoardNumber : public Board {
public:
    BoardNumber(Ui::MainWindow *ui);
    // Board interface
public:
    void initializeCells();
};

#endif // BOARDNUMBER_H
