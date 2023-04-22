#include "croppedimage.h"

CroppedImage::CroppedImage(QString fileName, QSize boardFrameSize)
    : QImage(fileName),
      clippings(new QList<QPixmap*>()),
      pixmap(QPixmap::fromImage(this->scaled(boardFrameSize.width(), boardFrameSize.height())))
{}

CroppedImage::~CroppedImage()
{
    delete clippings;
}

void CroppedImage::clipImage(
        const unsigned short boardSize,
        const unsigned short cellWidth,
        const unsigned short cellHeight)
{
    if(clippings->size() != 0) {
        clippings->clear();
    }

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            const QPoint *topleft = new QPoint(j*cellWidth, i*cellHeight);
            const QPoint *bottomright = new QPoint(((j+1)*cellWidth), (i+1)*cellHeight);
            this->clippings->append(new QPixmap(pixmap.copy(*new QRect(*topleft, *bottomright))));
            delete topleft;
            delete bottomright;
        }
    }
}

QList<QPixmap *> *CroppedImage::getClippings()
{
    return clippings;
}
