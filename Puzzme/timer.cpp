#include "timer.h"

Timer::Timer() {
    this->qTimer = new QTimer(this);
}

Timer::~Timer()
{
    delete qTimer;
}
