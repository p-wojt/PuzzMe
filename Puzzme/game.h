#ifndef GAME_H
#define GAME_H

#include "artificialintelligence.h"
#include "board.h"
#include "timer.h"

/*!
 * \brief Główna klasa - główny kontener. Symbolizuje
 */
class Game : public QObject
{
    Q_OBJECT
public:
    Game(Ui::MainWindow *ui);
    ~Game();
    /*!
     * \brief Inicjalizuje grę - ustawia planszę.
     */
    void initializeGame();
private:
    Board *board;
    Timer *timer;
    ArtificialIntelligence *ai;
private slots:
    void imageNumberButton_clicked();
    void boardButton_clicked();
    void startButton_clicked();
    void resetButton_clicked();
    void importButton_clicked();
    void solveButton_clicked();
    void algorithmAButton_clicked();
    void algorithmBButton_clicked();
};

#endif // GAME_H
