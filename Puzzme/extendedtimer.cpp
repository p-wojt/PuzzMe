#include "extendedtimer.h"
#include "ui_mainwindow.h"
#include "textutils.h"

ExtenedTimer::ExtenedTimer(Ui::MainWindow *ui) : Timer()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->ui = ui;
    this->ui->timer->

    connect(qTimer, &QTimer::timeout, this, &ExtenedTimer::process);
}

void ExtenedTimer::start()
{
    ExtenedTimer::reset();
    qTimer->start(1000);
}

void ExtenedTimer::stop()
{
    qTimer->stop();
}

void ExtenedTimer::reset()
{
    ExtenedTimer::stop();
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    ExtenedTimer::updateLCD();
}

void ExtenedTimer::process()
{
    if(++seconds >= 60) {
        this->seconds = 0;
        if(++minutes >= 60) {
            this->minutes=0;
            if(++hours >= 100) {
                ExtenedTimer::reset();
            }
        }
    }
   ExtenedTimer::updateLCD();
}

void ExtenedTimer::updateLCD() {
    this->ui->timer->setText(
                TextUtils::getTimeDigitsFormatFrom(hours)
                +":"
                +TextUtils::getTimeDigitsFormatFrom(minutes)
                +":"
                +TextUtils::getTimeDigitsFormatFrom(seconds));
}
