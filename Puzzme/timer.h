#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
public:
    Timer();
    ~Timer();
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
protected:
    QTimer *qTimer;
};

#endif // TIMER_H
