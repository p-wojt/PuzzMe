#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "minutetimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      timer(new MinuteTimer(ui)),
      board(new Board(ui))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    this->timer->start();
}


void MainWindow::on_resetButton_clicked()
{
    this->timer->reset();
}

void MainWindow::on_
