#ifndef CROPPEDIMAGE_H
#define CROPPEDIMAGE_H

#include <qimage.h>
#include <qpixmap.h>

class CroppedImage : public QImage
{
private:
    QList<QPixmap*> *clippings;
    QPixmap pixmap;
public:
    CroppedImage(QString fileName, QSize boardFrameSize);
    ~CroppedImage();
    void clipImage(const unsigned short boardSize,
                   const unsigned short cellWidth,
                   const unsigned short cellHeight);
    QList<QPixmap *> *getClippings();
};

#endif // CROPPEDIMAGE_H
