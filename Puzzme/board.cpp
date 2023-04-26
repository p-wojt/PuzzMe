#include "board.h"
#include "gameutils.h"
#include "imagefilevalidator.h"
#include "colorutils.h"
#include "artificialintelligence.h"
#include "algorithmworker.h"

#include <qfiledialog.h>
#include <qmessagebox.h>
#include <chrono>
#include <thread>
#include <qtimer.h>
#include <qthread.h>


Board::Board(Ui::MainWindow *ui)
    : ui(ui),
      size(GameUtils::MIN_BOARD_SIZE),
      cellContainer(new CellContainer()),
      imageValidator(new ImageFileValidator())
{
    setup();
}

void Board::resetCellsToInitialPositions()
{
    if(GameUtils::isGameStarted) {
        GameUtils::isGameStarted = false;
        ui->startButton->setDisabled(false);
        cellContainer->resetBlankToNormalCell();
        cellContainer->setInitialPostions(size);
    }
}

bool Board::setupCroppedImage()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "Image (*.jpg, *.png)");
    if (imageValidator->validate(filename)) {
        if(croppedImage != nullptr){
            delete croppedImage;
        }
        croppedImage = new CroppedImage(filename, ui->boardFrame->size());
        croppedImage->clipImage(size, cellContainer->getCellsWidth(), cellContainer->getCellsHeight());
        return true;
    }
    return false;
}

void Board::setupCellsImage()
{
   cellContainer->setImagePixmapsToCells(croppedImage->getClippings());
   cellContainer->setImagePixmapsVisibleBesidesBlank();
   ui->imageNumberButton->setText(GameUtils::areNumberCellsActive ? "Numbers" : "Images");
}

void Board::setup() {
    connect(cellContainer, &CellContainer::cellsLinedUpSingal, this, &Board::onCellsLinedUp);
    connect(cellContainer, &CellContainer::refreshBoardSignal, this, &Board::refreshBoardView);
    initializeCells();
    refreshBoardView();
}

void Board::startGame()
{
    cellContainer->initializeBlankCell();
    cellContainer->shuffle(size);
    refreshBoardView();
}

void Board::refreshBoardView() {
    int counter = 0;
    for(int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++, counter++) {
            this->ui->board->addWidget(this->cellContainer->at(counter), i, j);
        }
    }
    if(GameUtils::isGameStarted) {
        ColorUtils::setDisabledStyle(ui->startButton);
        ColorUtils::setEnabledStyle(ui->solveButton);
        ui->startButton->setDisabled(true);
        ui->solveButton->setDisabled(false);
    } else {
        ColorUtils::setEnabledStyle(ui->startButton);
        ColorUtils::setDisabledStyle(ui->solveButton);
        ui->startButton->setDisabled(false);
        ui->solveButton->setDisabled(true);
    }
    ui->imageNumberButton->setText(GameUtils::areNumberCellsActive ? "Numbers" : "Images");
}

void Board::changeCellsToOppositeVisibility()
{
    if (cellContainer->changeToOppositeVisibilty()){
        GameUtils::areNumberCellsActive = !GameUtils::areNumberCellsActive;
    } else {
        QMessageBox::information(this, "Puzzme", "To change visibility import an image!");
    }
}

void Board::initializeCells()
{
    cellContainer->initializeCells(size);
}

void Board::clearBoard() {
    while(this->ui->board->count()){
        QLayoutItem *child = this->ui->board->takeAt(0);
        if(child != nullptr) {
            delete child->widget();
        }
    }
}

void Board::setSize(unsigned short size)
{
    this->size = size;
}

void Board::solve(ArtificialIntelligence *ai)
{
    if(GameUtils::isGameStarted) {
        GameUtils::isAiSolvingGame = true;
        blockButtonsDisallowedDurningAlgorithm();

        AlgorithmWorker *worker = new AlgorithmWorker(ai, cellContainer);
        QThread *thread = new QThread();
        worker->moveToThread(thread);

        connect(thread, &QThread::started, worker, &AlgorithmWorker::run);
        connect(worker, &AlgorithmWorker::finished, thread, &QThread::quit);
        connect(worker, &AlgorithmWorker::finished, this, &Board::onAlgorithmWorkerFinish);
        connect(worker, &AlgorithmWorker::finished, worker, &AlgorithmWorker::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    } else {
         QMessageBox::information(this, "Puzzme", "First you have to start the game!");
    }

}

void Board::blockButtonsDisallowedDurningAlgorithm()
{
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    for (auto button : buttons) {
        if(button == ui->imageNumberButton || button == ui->solveButton)
            continue;
        button->setDisabled(true);
        ColorUtils::setDisabledStyle(button);
    }
}

void Board::unlockButtonsDisallowedDurningAlgorithm()
{
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    for (auto button : buttons) {
        if(button == ui->solveButton)
            continue;
        button->setDisabled(false);
        ColorUtils::setEnabledStyle(button);
    }
}

void Board::onCellsLinedUp()
{
    GameUtils::isGameStarted = false;
    QMessageBox::information(this, "Puzzme", "Well done!");
    refreshBoardView();
}

void Board::onRefreshBoard()
{
    Board::refreshBoardView();
}

void Board::onAlgorithmWorkerFinish()
{
    resetCellsToInitialPositions();
    refreshBoardView();
    onCellsLinedUp();
    unlockButtonsDisallowedDurningAlgorithm();
}

