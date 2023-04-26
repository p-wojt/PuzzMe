#include "artificialintelligenceb.h"
#include "gameutils.h"

#include <chrono>
#include <qrandom.h>
#include <thread>

void ArtificialIntelligenceB::solve(CellContainer *cellContainer)
{
    QRandomGenerator generator;
    int boardSize = std::sqrt(cellContainer->size());
    while(!cellContainer->areIdsLinedUp() && GameUtils::isAiSolvingGame) {
        // Wybierz losową pozycję i od niej klikaj na wschód
        for(int i = generator.bounded(cellContainer->size()) ; (i + 1) % boardSize != 0; i++) {
            Cell *clickedCell = cellContainer->at(i);
            if(cellContainer->isCellCloseToBlank(clickedCell)){
                cellContainer->onCellClicked(clickedCell);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }

}
