#include "minutetimer.h"

MinuteTimer::MinuteTimer()
{
    this->hours = 0;
    this->seconds = 0;
    this->minutes = 0;
}

void MinuteTimer::start()
{
    qTimer.start();
}

void MinuteTimer::stop()
{
    qTimer.stop();
}

void MinuteTimer::reset()
{
    this->hours = 0;
    this->seconds = 0;
    this->minutes = 0;
}
