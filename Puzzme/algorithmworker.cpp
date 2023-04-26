#include "algorithmworker.h"

#include "gameutils.h"

void AlgorithmWorker::run() {
    ai->solve(cellContainer);
    GameUtils::isAiSolvingGame = false;
    emit finished();
}
