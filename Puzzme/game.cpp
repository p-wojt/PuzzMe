#include "game.h"
#include "board.h"
#include "extendedtimer.h"
#include "boardsizeinput.h"
#include "gameutils.h"

#include <qfiledialog.h>

Game::Game(Ui::MainWindow *ui)
    : board(new Board(ui)),
      timer(new ExtenedTimer(ui))
{
    connect(ui->boardButton, &QPushButton::clicked, this, &Game::on_boardButton_clicked);
    connect(ui->imageNumberButton, &QPushButton::clicked, this, &Game::on_imageNumberButton_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &Game::on_startButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &Game::on_resetButton_clicked);
    connect(ui->importButton, &QPushButton::clicked, this, &Game::on_importButton_clicked);
}

void Game::initializeGame()
{
    board->setup();
}

void Game::on_imageNumberButton_clicked()
{
    board->changeCellsToOppositeVisibility();
    board->refreshBoardView();

}

void Game::on_boardButton_clicked()
{

    BoardSizeInput dialog(board);
        if (dialog.exec() == QDialog::Accepted)
        {
            GameUtils::isGameStarted = false;
            GameUtils::areNumberCellsActive = true;
            board->setSize(dialog.getValue());
            board->clearBoard();
            board->initializeCells();
            board->refreshBoardView();
        }
}

void Game::on_startButton_clicked()
{
    GameUtils::isGameStarted = true;
    board->startGame();
    timer->start();
}


void Game::on_resetButton_clicked()
{
    // tutaj ejszcze nie wiem
    GameUtils::isGameStarted = false;
    timer->reset();
    board->clearBoard();
    board->initializeCells();
    board->refreshBoardView();
}


void Game::on_importButton_clicked()
{
    if(board->setupCroppedImage()){
        timer->reset();
        board->setupCellsImage();
        board->resetCellsToInitialPositions();
        board->refreshBoardView();
    }
}

