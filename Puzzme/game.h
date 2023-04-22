#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "timer.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(Ui::MainWindow *ui);
    ~Game();
    void initializeGame();
private:
    Board *board;
    Timer *timer;
private slots:
    void on_imageNumberButton_clicked();
    void on_boardButton_clicked();
    void on_startButton_clicked();
    void on_resetButton_clicked();
    void on_importButton_clicked();
    void on_solveButton_clicked();
};

#endif // GAME_H
