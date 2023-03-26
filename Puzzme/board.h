#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "./ui_mainwindow.h"

class Board : public QObject
{
    Q_OBJECT
public:
    Board(Ui::MainWindow *ui);
private slots:
    void on_boardButton_clicked();

    void on_importButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // BOARD_H
