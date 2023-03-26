#include "minutetimer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>

MinuteTimer::MinuteTimer(Ui::MainWindow *ui) : Timer()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->ui = ui;

    connect(qTimer, &QTimer::timeout, this, &MinuteTimer::process);
}

void MinuteTimer::start()
{
    MinuteTimer::reset();
    qTimer->start(1000);
}

void MinuteTimer::stop()
{
    qTimer->stop();
}

void MinuteTimer::reset()
{
    MinuteTimer::stop();
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    MinuteTimer::updateLCD();
}

void MinuteTimer::process()
{
    if(++seconds >= 60) {
        this->seconds = 0;
        if(++minutes >= 60) {
            this->minutes=0;
            if(++hours >= 100) {
                MinuteTimer::reset();
            }
        }
    }
   MinuteTimer::updateLCD();
}

void MinuteTimer::updateLCD() {
    this->ui->Seconds->display(this->seconds);
    this->ui->Minutes->display(this->minutes);
    this->ui->Hours->display(this->hours);
}
