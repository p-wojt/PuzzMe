#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <QPalette>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Puzzme");
    QPalette pal = w.palette();
    QColor customColor;
    customColor.setRgb(0x161616);
    pal.setColor(QPalette::Window, customColor);
    w.setPalette(pal);

    w.show();
    return a.exec();
}
