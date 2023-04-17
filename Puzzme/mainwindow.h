#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer.h"
#include "board.h"
#include "validator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();
    void on_importButton_clicked();
    void on_boardButton_clicked();
    void on_cellTypeButton_clicked();
private:
    Ui::MainWindow *ui;
    Timer *timer;
    Board *board;
    Validator<QString> *validator;
};
#endif // MAINWINDOW_H
