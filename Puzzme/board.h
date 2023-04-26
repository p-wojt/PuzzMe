#ifndef BOARD_H
#define BOARD_H

#include "./ui_mainwindow.h"
#include "artificialintelligence.h"
#include "cellcontainer.h"
#include "croppedimage.h"
#include "validator.h"

/*!
 * \brief Klasa symbolizująca plansze.
 *
 * Klasa Board zawiera funkcjonalności, które mogą zostać zastosowane
 * na stworzonej planszy.
 */
class Board : public QWidget
{
public:
    Board(Ui::MainWindow *ui);

    /*!
     * \brief Resetuje ustawia wszystkie komórki na lokacje początkowe wraz
     * z ustawieniem komórki "blank" na normalną.
     */
    void resetCellsToInitialPositions();
    /*!
     * \brief Pozwala ustawić obrazek, który ma być wykorzystany na planszy.
     * \return Zwraca boola symbolizującego, czy udało się wykonać powyszą metodę.
     */
    bool setupCroppedImage();
    /*!
     * \brief Ustawia wszystkim komórkom pocięte obrazki.
     */
    void setupCellsImage();
    /*!
     * \brief Odświeża planszę, dzięki niej widać zastosowane zmiany.
     */
    void refreshBoardView();
    /*!
     * \brief Zmiana widoczności komórek na przeciwne z numerków na obrazki i vice wersa.
     */
    void changeCellsToOppositeVisibility();
    /*!
     * \brief Inicjalizacja poszczególnych komórek.
     */
    void initializeCells();
    /*!
     * \brief Ustawia początkowe wartości planszy.
     */
    void setup();
    /*!
     * \brief Ustawia wartości początkowe dla planszy po wystartowaniu rozgrywki.
     */
    void startGame();
    /*!
     * \brief Czyści widok komórek na planszy.
     */
    void clearBoard();
    /*!
     * \brief Ustawia rozmiar planszy.
     * \param size rozmiar planszy.
     */
    void setSize(unsigned short size);
    /*!
     * \brief Rozwiązuje komórki na planszy według ustalonego algorytmu.
     * \param ai typ algorytmu.
     */
    void solve(ArtificialIntelligence *ai);
    /*!
     * \brief Blokuje wszystkie przyciski.
     */
    void blockButtonsDisallowedDurningAlgorithm();
    /*!
     * \brief Odblokowuje wszystkie przyciski.
     */
    void unlockButtonsDisallowedDurningAlgorithm();

private:
    Ui::MainWindow *ui;
    unsigned short size;
    CellContainer *cellContainer;
    CroppedImage *croppedImage;
    Validator<QString> *imageValidator;
public slots:
    /*!
     * \brief Slot symbolizujący ułożenie komórek w prawidłowej kolejności.
     */
    void onCellsLinedUp();
    /*!
     * \brief Slot symbolizujący odświeżenie planszy.
     */
    void onRefreshBoard();
    /*!
     * \brief Slot symbolizujący zakończenie pracy AlgorithmWorkera
     */
    void onAlgorithmWorkerFinish();
};

#endif // BOARD_H
