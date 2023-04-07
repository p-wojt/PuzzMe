#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QList>
#include "cell.h"

class Board : public QObject
{
    Q_OBJECT
public:
    Board(Ui::MainWindow *ui);
    void initializeNumberCells();
    void setImageToCells();
    void setImage(QImage *image);
    void displayCells();
    void setBlankCell();
    void setup();
    void shuffle();
    void startGame();
    void clearBoard();
    void setScaledPixmap(QSize size);
private:
    Ui::MainWindow *ui;
    short unsigned int size;
    QList<Cell*> *cells;
    QImage *image;
    bool areNumberCells;
    QPixmap *scaledPixmap;
public slots:
    void boardClicked();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // BOARD_H
