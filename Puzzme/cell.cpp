#include "cell.h"
#include "board.h"


//sprawdzic setVisible na false
Cell::Cell(unsigned short id, unsigned short x, unsigned short y, const QString &text, QWidget* parent, Qt::WindowFlags f)
    : QLabel(text, parent) {
    connect(this, SIGNAL(clicked()), this, SLOT(cellClicked()));
    this->id = id;
    this->x = x;
    this->y = y;
    this->blank = false;
    this->imagePixmap = nullptr;
}

Cell::Cell() {
//    connect(this, SIGNAL(clicked()), this, SLOT(cellClicked()));
    this->blank = false;
    this->imagePixmap = nullptr;
}

Cell::~Cell() {

}

unsigned short Cell::getId()
{
    return this->id;
}

void Cell::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

QPixmap *Cell::getImagePixmap() const
{
    return imagePixmap;
}

void Cell::setImagePixmap(QPixmap *newImagePixmap)
{
    imagePixmap = newImagePixmap;
}

void Cell::setPixmapAsNumber()
{
    this->setText(QString::number(this->id));
}

void Cell::setPixmapAsImage()
{
    qDebug() << *this->imagePixmap;
    this->setPixmap(*this->imagePixmap);
}

void Cell::setAsBlank()
{
    //https://stackoverflow.com/questions/23724515/qt-setting-text-to-a-qlabel-with-a-pixmap-and-back
    //Here is written that setting text to QLabel clears any previous content.
    this->setText("asd");
    this->setBlank(true);
}

bool Cell::isBlank() const
{
    return blank;
}

void Cell::cellClicked() {
    qDebug() << "Mouse event";
    qDebug() << this->id << " x=" <<x<<" y="<<y<<" isBlank: "<<isBlank()<<" pixmap: "<<this->pixmap()<<" iamgePixmap: "<<this->imagePixmap;
    if(!this->isBlank()) {

    }
}

unsigned short int Cell::getX() {
    return this->x;
}

unsigned short int Cell::getY() {
    return this->y;
}

void Cell::setX(unsigned short x) {
    this->x = x;
}

void Cell::setY(unsigned short y) {
    this->y = y;
}

void Cell::setBlank(bool isBlank)
{
    this->blank = isBlank;
}
