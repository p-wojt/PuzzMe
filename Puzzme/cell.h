#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QPixmap>

class Cell : public QLabel
{
     Q_OBJECT
public:
    explicit Cell(unsigned short id, unsigned short x, unsigned short y, const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    Cell();
    ~Cell();
    void setBlank(bool isBlank);
    void setImagePixmap(QPixmap *newImagePixmap);
    void setAsBlank();
    void setPixmapAsNumber();
    void setPixmapAsImage();
    void setId(unsigned short id);
    void setX(unsigned short x);
    void setY(unsigned short y);
    unsigned short getId();
    unsigned short getX();
    unsigned short getY();
    bool isImageSet();
    bool isBlank();
    QPixmap *getImagePixmap();
signals:
    void cellClicked(Cell *cell);
public:
    void mousePressEvent(QMouseEvent* event);
private:
    unsigned short id, x, y;
    bool blank;
    QPixmap *imagePixmap;
};

#endif // CELL_H
