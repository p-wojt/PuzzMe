#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "colorutils.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    setupStyles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStyles()
{
    setupMainWindowStyle();
    setupTimerStyle();
    setupLayoutsStyle();
    setupButtonsStyle();
}

void MainWindow::setupMainWindowStyle()
{
    QPalette backgroundPalette = this->palette();
    backgroundPalette.setColor(QPalette::Window, ColorUtils::black());
    this->setPalette(backgroundPalette);
    ui->setupUi(this);
}

void MainWindow::setupTimerStyle()
{
    ui->timer->setStyleSheet("qproperty-alignment: AlignCenter; color: #F8F8F8; font-size: 48px;");
}

void MainWindow::setupLayoutsStyle()
{
    ui->horizontalLayout->setAlignment(Qt::AlignCenter);
    ui->horizontalLayout->setSpacing(10);
}

void MainWindow::setupButtonsStyle()
{
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    for (auto button : buttons) {
        ColorUtils::setEnabledStyle(button);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->mainGameLayout->setGeometry(rect());
}

Ui::MainWindow *MainWindow::getUi()
{
    return ui;
}
