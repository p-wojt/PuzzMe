#include "game.h"
#include "extendedtimer.h"
#include "boardsizeinput.h"
#include "gameutils.h"

Game::Game(Ui::MainWindow *ui)
    : board(new Board(ui)),
      timer(new ExtenedTimer(ui))
{
    connect(ui->boardButton, &QPushButton::clicked, this, &Game::on_boardButton_clicked);
    connect(ui->imageNumberButton, &QPushButton::clicked, this, &Game::on_imageNumberButton_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &Game::on_startButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &Game::on_resetButton_clicked);
    connect(ui->importButton, &QPushButton::clicked, this, &Game::on_importButton_clicked);
    connect(ui->solveButton, &QPushButton::clicked, this, &Game::on_solveButton_clicked);
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

void Game::on_solveButton_clicked()
{
    if(GameUtils::isGameStarted) {
        timer->stop();
        board->resetCellsToInitialPositions();
        board->refreshBoardView();
        board->onCellsLinedUp();
    }
}

