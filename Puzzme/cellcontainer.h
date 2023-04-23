#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include "cell.h"

/*!
 * \brief Klasa symbolizująca kontener komórek.
 */
class CellContainer : public QObject, public QList<Cell*>
{
    Q_OBJECT
public:
    CellContainer() {};
    ~CellContainer();
    /*!
     * \brief Inicializuje kontener komórkami.
     * \param boardSize rozmiar planszy.
     */
    void initializeCells(const unsigned short boardSize);
    /*!
     * \brief Inicializuje komórkę "blank" - ustawia.
     */
    void initializeBlankCell();
    /*!
     * \brief Ustawia pixmapy komórek, na przekazaną listę pixmapów.
     * \param clippings - wycinki obrazków, lista pixmap wycinków.
     */
    void setImagePixmapsToCells(QList<QPixmap*> *clippings);
    /*!
     * \brief Zmienia widoczność na numerki bądź obrazki komórek bez komórki "blank".
     */
    void setImagePixmapsVisibleBesidesBlank();
    /*!
     * \brief Ustawia zdefiniowane style dla określonej komórki.
     * \param cell - komórka, która będzie miała zmieniony styl.
     */
    void setCellStyles(Cell *cell);
    /*!
     * \brief Resetuje ustawia wszystkie komórki na lokacje początkowe względem id komórek.
     * \param boardSize - rozmiar planszy.
     */
    void setInitialPostions(const unsigned short boardSize);
    /*!
     * \brief Zmiana widoczności kontenerze na numerki bądź obrazki.
     * \return Zwraca wartość bool czy operacja zmiany widoczności się powiodła.
     */
    bool changeToOppositeVisibilty();
    /*!
     * \brief Zamienia pozycje komórek losowo.
     * \param boardSize - rozmiar planszy.
     */
    void shuffle(unsigned short boardSize);
    /*!
     * \brief Ustawia komórkę "blank" na normalną komórkę.
     */
    void resetBlankToNormalCell();
    /*!
     * \brief Jeżeli to możliwe to zamienia pozycję blanka z pozycją komórki podanej w parametrze.
     * \param cell - komórka do zmiany pozycji.
     */
    void swapCellAndBlankPosition(Cell *cell);
    /*!
     * \brief Zamiana komórek po ich indeksach.
     * \param firstIndex - indeks pierwszej komórki.
     * \param secondIndex - indeks drugiej komórki.
     */
    void swapCellsByIndex(int firstIndex, int secondIndex);
    /*!
     * \brief Sprawdza czy komórka podana w parametrze jest obok komórki "blank".
     * \param cell - komórka do sprawdzenia.
     * \return Zwraca wartość bool czy podana komórka jest obok komórki "blank".
     */
    bool isCellCloseToBlank(Cell *cell);
    /*!
     * \brief Sprawdza czy komórki są w kolejności względem id rosnąco.
     * \return Zwraca wartość bool mówiącą czy komórki są w kolejności względem id rosnąco.
     */
    bool areIdsLinedUp();
    /*!
     * \brief Zwraca wartość mówiącą o szerokości definiującej komórki.
     * \return Wartość symbolizująca szerokość komórki.
     */
    int getCellsWidth();
    /*!
     * \brief Zwraca wartość mówiącą o wyskości definiującej komórki.
     * \return Wartość symbolizująca wysokość komórki.
     */
    int getCellsHeight();
signals:
    /*!
     * \brief Sygnał informujący o odpowiedniej kolejności komórek.
     */
    void cellsLinedUpSingal();
    /*!
     * \brief Sygnał mówiący o odświerzeniu planszy.
     */
    void refreshBoardSignal();
private:
    Cell* blankCell;
public slots:
    /*!
     * \brief Slot definiujący zachowanie po kliknięciu komórki podanej w parametrze.
     * \param cell - kliknięta komórka.
     */
    void onCellClicked(Cell *cell);
};

#endif // CELLCONTAINER_H
