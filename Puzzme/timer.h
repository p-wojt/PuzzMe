#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

class Timer
{
public:
    Timer();
    virtual void start();
    virtual void stop();
    virtual void reset();
protected:
    QTimer qTimer;
};

#endif // TIMER_H
