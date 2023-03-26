#include "boardnumber.h"
#include <QLabel>

BoardNumber::BoardNumber(Ui::MainWindow *ui) : Board(ui)
{

}

void BoardNumber::initializeCells() {
    for(int i = 0; i < this->size; i++){
        this->cells->append(new QLabel(QString::number(i)));
    }
}
