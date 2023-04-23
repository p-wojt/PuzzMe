#include "game.h"
#include "extendedtimer.h"
#include "boardsizeinput.h"
#include "gameutils.h"

Game::Game(Ui::MainWindow *ui)
    : board(new Board(ui)),
      timer(new ExtenedTimer(ui))
{
    connect(ui->boardButton, &QPushButton::clicked, this, &Game::boardButton_clicked);
    connect(ui->imageNumberButton, &QPushButton::clicked, this, &Game::imageNumberButton_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &Game::startButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &Game::resetButton_clicked);
    connect(ui->importButton, &QPushButton::clicked, this, &Game::importButton_clicked);
    connect(ui->solveButton, &QPushButton::clicked, this, &Game::solveButton_clicked);
}

Game::~Game()
{
    delete board;
    delete timer;
}

void Game::initializeGame()
{
    board->setup();
}

void Game::imageNumberButton_clicked()
{
    board->changeCellsToOppositeVisibility();
    board->refreshBoardView();
}

void Game::boardButton_clicked()
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

void Game::startButton_clicked()
{
    GameUtils::isGameStarted = true;
    board->startGame();
    timer->start();
}


void Game::resetButton_clicked()
{
    GameUtils::isGameStarted = false;
    timer->reset();
    board->clearBoard();
    board->initializeCells();
    board->refreshBoardView();
}


void Game::importButton_clicked()
{
    if(board->setupCroppedImage()){
        timer->reset();
        board->setupCellsImage();
        board->resetCellsToInitialPositions();
        board->refreshBoardView();
    }
}

void Game::solveButton_clicked()
{
    if(GameUtils::isGameStarted) {
        timer->stop();
        board->resetCellsToInitialPositions();
        board->refreshBoardView();
        board->onCellsLinedUp();
    }
}

