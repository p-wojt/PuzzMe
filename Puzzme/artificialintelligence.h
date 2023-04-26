#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H

#include "cellcontainer.h"

/*!
 * \brief Klasa abstrakcyjna symbolizująca Sztuczną inteligencję.
 */
class ArtificialIntelligence
{
public:
    /*!
     * \brief Metoda czysto wirtualna reprezentująca rozwiązanie - algorytm.
     */
    virtual void solve(CellContainer *cellContainer) = 0;
};

#endif // ARTIFICIALINTELLIGENCE_H
