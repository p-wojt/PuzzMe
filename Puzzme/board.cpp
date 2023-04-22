#include "board.h"
#include "gameutils.h"
#include "imagefilevalidator.h"
#include "colorutils.h"

#include <qfiledialog.h>
#include <qmessagebox.h>

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
            qDebug() << this->cellContainer->at(counter);
            this->ui->board->addWidget(this->cellContainer->at(counter), i, j);
        }
    }
    if(GameUtils::isGameStarted) {
        ColorUtils::setDisabledStyle(ui->startButton);
        ui->startButton->setDisabled(true);
    } else {
        ColorUtils::setEnabledStyle(ui->startButton);
        ui->startButton->setDisabled(false);
    }
    ui->imageNumberButton->setText(GameUtils::areNumberCellsActive ? "Numbers" : "Images");
}

void Board::changeCellsToOppositeVisibility()
{
    if (cellContainer->changeToOppositeVisibilty()){
        GameUtils::areNumberCellsActive = !GameUtils::areNumberCellsActive;
//        ui->imageNumberButton->setText(GameUtils::areNumberCellsActive ? "Numbers" : "Images");
    } else {
        QMessageBox::information(this, "Puzzme", "To change visibility import an image!");
    }
}

void Board::initializeCells()
{
    cellContainer->initializeCells(size);
//    ui->imageNumberButton->setText(GameUtils::areNumberCellsActive ? "Numbers" : "Images");
}


//void Board::startGame() {
//    this->setBlankCell();
//    this->shuffle();
//    this->displayCells();
//}

void Board::clearBoard() {
    qDebug() << "liczba dzieci: " << this->ui->board->count();
    while(this->ui->board->count()){
        QLayoutItem *child = this->ui->board->takeAt(0);
        if(child != nullptr) {
            delete child->widget();
        }
    }
}


void Board::onCellsLinedUp()
{
    qDebug() << "onCellsLinedUp";
    GameUtils::isGameStarted = false;
    QMessageBox::information(this, "Puzzme", "You win!");
    refreshBoardView();
}

void Board::onRefreshBoard()
{
    qDebug() << "onRefreshBoard";
    Board::refreshBoardView();
}

