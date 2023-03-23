#ifndef MINUTETIMER_H
#define MINUTETIMER_H

#include "timer.h"



class MinuteTimer : public Timer
{
public:
    MinuteTimer();
    void start();
    void stop();
    void reset();
    void process();
private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
};

#endif // MINUTETIMER_H
