#include "extendedtimer.h"
#include "textutils.h"
#include "ui_mainwindow.h"

ExtenedTimer::ExtenedTimer(Ui::MainWindow *ui) : Timer()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->ui = ui;

    connect(qTimer, &QTimer::timeout, this, &ExtenedTimer::process);
}

ExtenedTimer::~ExtenedTimer()
{
    delete ui;
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
    ExtenedTimer::updateView();
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
   ExtenedTimer::updateView();
}

void ExtenedTimer::updateView() {
    this->ui->timer->setText(
                TextUtils::getTimeDigitsFormatFrom(hours)
                +":"
                +TextUtils::getTimeDigitsFormatFrom(minutes)
                +":"
                +TextUtils::getTimeDigitsFormatFrom(seconds));
}
