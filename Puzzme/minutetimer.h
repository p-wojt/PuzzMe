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
private slots:
    void on_importButton_clicked();

    void on_solveButton_clicked();

private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
    Ui::MainWindow *ui;
};

#endif // MINUTETIMER_H
