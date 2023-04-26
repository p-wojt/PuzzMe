#ifndef ARTIFICIALINTELLIGENCEB_H
#define ARTIFICIALINTELLIGENCEB_H

#include "artificialintelligence.h"

/*!
 * \brief Klasa reprezentująca Algorytm B implementująca metodę solve z ArtificialIntelligence.
 */
class ArtificialIntelligenceB : public ArtificialIntelligence
{
public:
    ArtificialIntelligenceB() {};
    ~ArtificialIntelligenceB() {};
    /*!
     * \brief Implementacja Algorytmu A.
     * Polega na wyborze losowej pozycji następnie podąża zawsze na wschód.
     */
    void solve(CellContainer *cellContainer);
};

#endif // ARTIFICIALINTELLIGENCEB_H
