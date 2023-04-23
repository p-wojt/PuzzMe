#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QPixmap>

/*!
 * \brief Klasa przedstawia opis "Komórki" czyli pojedńczej kratki w planszy.
 */
class Cell : public QLabel
{
     Q_OBJECT
public:
    explicit Cell(unsigned short id, unsigned short x, unsigned short y, const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    Cell();
    ~Cell();
    /*!
     * \brief Ustawia komórkę jako "blank" - pustą w zależności od podanego parametru.
     * \param isBlank wartość bool czy dana komórka jest pusta.
     */
    void setBlank(bool isBlank);
    /*!
     * \brief Ustawia Pixmapę poszczególnego obrazka dla komórki.
     * \param newImagePixmap nowa Pixmapa.
     */
    void setImagePixmap(QPixmap *newImagePixmap);
    /*!
     * \brief Ustawia komórkę jako "blank"
     */
    void setAsBlank();
    /*!
     * \brief Ustawia widoczność komórki jako numer.
     */
    void setPixmapAsNumber();
    /*!
     * \brief Ustawia widocznosć komórki jako obrazek.
     */
    void setPixmapAsImage();
    /*!
     * \brief Ustawia id komórki.
     * \param id - identyfikator komórki.
     */
    void setId(unsigned short id);
    /*!
     * \brief Ustawia pozycję X komórki.
     * \param Pozycja x.
     */
    void setX(unsigned short x);
    /*!
     * \brief Ustawia pozycję Y komórki.
     * \param Pozycja Y komórki.
     */
    void setY(unsigned short y);
    /*!
     * \brief Zwraca id komórki.
     * \return id komórki.
     */
    unsigned short getId();
    /*!
     * \brief Zwraca pozycję X komórki.
     * \return Zwraca x.
     */
    unsigned short getX();
    /*!
     * \brief Zwraca pozycję Y komórki.
     * \return Zwraca y.
     */
    unsigned short getY();
    /*!
     * \brief sprawdza czy dana komórka ma ustawiony obrazek.
     * \return Zwraca wartość bool czy dana komórka ma ustawiony obrazek.
     */
    bool isImageSet();
    /*!
     * \brief sprawdza czy dana komórka jest "blank".
     * \return Zwraca wartość bool czy dana komórka jest "blank".
     */
    bool isBlank();
    /*!
     * \brief Zwraca pixmapę komórki.
     * \return Pixmapa komórki.
     */
    QPixmap *getImagePixmap();
signals:
    /*!
     * \brief Sygnał symbolizujący kliknięcie komórki.
     * \param Przekazanie wskaźnika na klikniętą komórkę.
     */
    void cellClicked(Cell *cell);
public:
    void mousePressEvent(QMouseEvent* event);
private:
    unsigned short id, x, y;
    bool blank;
    QPixmap *imagePixmap;
};

#endif // CELL_H
