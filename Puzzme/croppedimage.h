#ifndef CROPPEDIMAGE_H
#define CROPPEDIMAGE_H

#include <qimage.h>
#include <qpixmap.h>

/*!
 * \brief Klasa przedstawiająca pocięty obrazek.
 */
class CroppedImage : public QImage
{
private:
    QList<QPixmap*> *clippings;
    QPixmap pixmap;
public:
    CroppedImage(QString fileName, QSize boardFrameSize);
    ~CroppedImage();
    /*!
     * \brief Tnie zdefiniowany obrazek na części/kawałki - clippings.
     * \param boardSize - rozmiar planszy.
     * \param cellWidth - szerokość komórki.
     * \param cellHeight - wysokość komórki.
     */
    void clipImage(const unsigned short boardSize,
                   const unsigned short cellWidth,
                   const unsigned short cellHeight);
    /*!
     * \brief Zwraca kawałki obrazka.
     * \return Lista pociętych obrazków.
     */
    QList<QPixmap *> *getClippings();
};

#endif // CROPPEDIMAGE_H
