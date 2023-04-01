#include "extendedtimer.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QFileDialog>

ExtenedTimer::ExtenedTimer(Ui::MainWindow *ui) : Timer()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->ui = ui;

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
    this->ui->Seconds->display(this->seconds);
    this->ui->Minutes->display(this->minutes);
    this->ui->Hours->display(this->hours);
}
