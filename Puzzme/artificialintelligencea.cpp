#include "artificialintelligencea.h"
#include "gameutils.h"

#include <QRandomGenerator>
#include <chrono>
#include <thread>


void ArtificialIntelligenceA::solve(CellContainer *cellContainer)
{
    QRandomGenerator generator;
    int boardSize = std::sqrt(cellContainer->size());
    while(!cellContainer->areIdsLinedUp() && GameUtils::isAiSolvingGame) {
            // Wybierz losową pozycję i losowo klinij północ, wschód, południe, zachód
            int randomIndex = generator.bounded(cellContainer->size());
            int rowIndex = randomIndex / boardSize;
            int columnIndex = randomIndex % boardSize;
            std::random_shuffle(moveFunctions.begin(), moveFunctions.end());
            for(auto function : moveFunctions) {
                (this->*function)(cellContainer, boardSize, rowIndex, columnIndex);
            }
    }
}

void ArtificialIntelligenceA::moveNorth(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex)
{
    // Przejście na północ
    if(rowIndex > 0) {
        cellClick(cellContainer, (rowIndex - 1) * boardSize + columnIndex);
    }
}

void ArtificialIntelligenceA::moveEast(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex)
{
    // Przejście na wschód
    if(columnIndex < boardSize - 1) {
        cellClick(cellContainer, rowIndex * boardSize + columnIndex + 1);
    }
}

void ArtificialIntelligenceA::moveSouth(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex)
{
    // Przejście na południe
    if(rowIndex < boardSize - 1) {
        cellClick(cellContainer, (rowIndex + 1) * boardSize + columnIndex);
    }
}

void ArtificialIntelligenceA::moveWest(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex)
{
    // Przejście na zachód
    if(columnIndex > 0) {
        cellClick(cellContainer, rowIndex * boardSize + columnIndex - 1);
    }
}

void ArtificialIntelligenceA::cellClick(CellContainer *cellContainer, int index)
{
    Cell *clickedCell = cellContainer->at(index);
    if(cellContainer->isCellCloseToBlank(clickedCell)){
        cellContainer->onCellClicked(clickedCell);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
