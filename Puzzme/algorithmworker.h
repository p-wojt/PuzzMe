#ifndef WORKER_H
#define WORKER_H

#include "artificialintelligence.h"

#include <qobject.h>
#include <thread>

/*!
 * \brief Klasa symbolizująca osobny thread w celu pozwolenia osobnego procesowania eventów głównej pętli od GUI.
 */
class AlgorithmWorker : public QObject
{
    Q_OBJECT
public:
    AlgorithmWorker(ArtificialIntelligence *ai, CellContainer *cellContainer)
        : ai(ai), cellContainer(cellContainer) {}

public slots:
    void run();

signals:
    /*!
     * \brief Sygnał uświadamiający zakończenie pracy
     */
    void finished();

private:
    ArtificialIntelligence *ai;
    CellContainer *cellContainer;
};

#endif // WORKER_H
