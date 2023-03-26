#ifndef IMAGEMAP_H
#define IMAGEMAP_H

#include <QImage>

class ImageMap
{
public:
    ImageMap(QImage *image);
private:
    QImage *image;

};

#endif // IMAGEMAP_H
