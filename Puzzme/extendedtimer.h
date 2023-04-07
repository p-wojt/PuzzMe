#ifndef MINUTETIMER_H
#define MINUTETIMER_H

#include "timer.h"
#include "mainwindow.h"
#include <QLCDNumber>

class ExtenedTimer : public Timer
{
public:
    ExtenedTimer(Ui::MainWindow *ui);
    void start();
    void stop();
    void reset();
    void process();
    void updateLCD();
private slots:
    void on_cellTypeButton_clicked();

private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
    Ui::MainWindow *ui;
};

#endif // MINUTETIMER_H