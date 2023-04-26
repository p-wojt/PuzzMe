#ifndef ARTIFICIALINTELLIGENCEA_H
#define ARTIFICIALINTELLIGENCEA_H

#include "artificialintelligence.h"

/*!
 * \brief Klasa reprezentująca Algorytm A implementująca metodę solve z ArtificialIntelligence.
 */
class ArtificialIntelligenceA : public ArtificialIntelligence
{
public:
    ArtificialIntelligenceA() :
        moveFunctions{&ArtificialIntelligenceA::moveNorth,
                      &ArtificialIntelligenceA::moveEast,
                      &ArtificialIntelligenceA::moveSouth,
                      &ArtificialIntelligenceA::moveWest} {}
    ~ArtificialIntelligenceA() {};
    /*!
     * \brief Implementacja Algorytmu A.
     * Polega na wyborze losowej pozycji, następnie kliknięciu północnej, wschodniej, południowej, zachodniej komórki.
     */
    void solve(CellContainer *cellContainer);
private:
    /*!
     * \brief Wektor funkcji symbolizujących poruszanie na północ, wschód, południe, zachód
     */
    std::vector<void (ArtificialIntelligenceA::*)(CellContainer*, int, int, int)> moveFunctions;
    /*!
     * \brief Sprawdza czy jest możliwość kliknięca na północną komórkę i klika.
     * \param cellContainer kontener komórek.
     * \param boardSize rozmiar planszy.
     * \param rowIndex indeks wiersza wylosowanej pozycji.
     * \param columnIndex indeks kolumny wylosowanej pozycji.
     */
    void moveNorth(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex);
    /*!
     * \brief Sprawdza czy jest możliwość kliknięca na wschodnią komórkę i klika.
     * \param boardSize rozmiar planszy.
     * \param rowIndex indeks wiersza wylosowanej pozycji.
     * \param columnIndex indeks kolumny wylosowanej pozycji.
     */
    void moveEast(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex);
    /*!
     * \brief Sprawdza czy jest możliwość kliknięca na południową komórkę i klika.
     * \param boardSize rozmiar planszy.
     * \param rowIndex indeks wiersza wylosowanej pozycji.
     * \param columnIndex indeks kolumny wylosowanej pozycji.
     */
    void moveSouth(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex);
    /*!
     * \brief Sprawdza czy jest możliwość kliknięca na zachodnią komórkę i klika.
     * \param boardSize rozmiar planszy.
     * \param rowIndex indeks wiersza wylosowanej pozycji.
     * \param columnIndex indeks kolumny wylosowanej pozycji.
     */
    void moveWest(CellContainer *cellContainer, int boardSize, int rowIndex, int columnIndex);
    /*!
     * \brief Wybiera komórkę w danym kontenerze o podanym indeksie oraz ją przemieszcza jeżeli sepłnia warunki przemieszczenia.
     * \param boardSize rozmiar planszy.
     * \param rowIndex indeks wiersza wylosowanej pozycji.
     * \param columnIndex indeks kolumny wylosowanej pozycji.
     */
    void cellClick(CellContainer *cellContainer, int index);
};

#endif // ARTIFICIALINTELLIGENCEA_H
