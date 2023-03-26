#ifndef MINUTETIMER_H
#define MINUTETIMER_H

#include "timer.h"
#include "mainwindow.h"
#include <QLCDNumber>

class MinuteTimer : public Timer
{
public:
    MinuteTimer(Ui::MainWindow *ui);
    void start();
    void stop();
    void reset();
    void process();
    void updateLCD();
private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
    Ui::MainWindow *ui;
};

#endif // MINUTETIMER_H
