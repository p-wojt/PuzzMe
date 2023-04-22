#include "mainwindow.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    new Game(mainWindow.getUi());
    mainWindow.setWindowTitle("Puzzme");
    mainWindow.show();
    return a.exec();
}
