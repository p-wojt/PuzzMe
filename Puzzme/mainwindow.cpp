#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "extendedtimer.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QLabel>
#include <QFileInfo>
#include <QRect>
#include "boardsizeinput.h"
#include "imagefilevalidator.h"
#include <QResizeEvent>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      timer(new ExtenedTimer(ui)),
      board(new Board(ui)),
      validator(new ImageFileValidator())
{
    ui->setupUi(this);
    board->setup();

    ui->horizontalLayout->setAlignment(Qt::AlignCenter);
    ui->horizontalLayout->setSpacing(10);

    ui->timer->setStyleSheet("qproperty-alignment: AlignCenter; color: #F8F8F8; font-size: 48px;");
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    for (auto button : buttons) {
        button->setStyleSheet("border: 1px solid black; background-color: #0E4C92; color: #F8F8F8; font-family: \"Inter\"; font-size: 16pt; width: 200px; height: 50px;");

    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete board;
    delete timer;
}

void MainWindow::on_startButton_clicked()
{
    this->timer->start();
    this->board->startGame();
}


void MainWindow::on_resetButton_clicked()
{
    this->timer->reset();
}


void MainWindow::on_importButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "Image (*.jpg, *.png)");

   if (validator->validate(fileName)) {

       QImage image(fileName);
       board->setImage(&image);
       board->setImageToCells();
       board->displayCells();
   }

}

void MainWindow::on_boardButton_clicked()
{

    BoardSizeInput dialog(this);
        if (dialog.exec() == QDialog::Accepted)
        {
            unsigned short value = dialog.getValue();
            this->board->setSize(value);
            this->board->clearBoard();
            this->board->setup();
            this->timer->reset();
            // do something with value
        }
}


void MainWindow::on_imageNumberButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr)
    {
        button->setText(board->getAreNumberCells() ? "Numbers" : "Images");
    }
    this->board->changeState();
    this->board->displayCells();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->mainLayout_2->setGeometry(rect());
    QMainWindow::resizeEvent(event);
}


