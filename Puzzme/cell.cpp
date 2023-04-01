#include "cell.h"

Cell::Cell(unsigned short id, unsigned short x, unsigned short y, const QString &text, QWidget* parent, Qt::WindowFlags f)
    : QLabel(text, parent) {
    connect(this, SIGNAL(clicked()), this, SLOT(cellClicked()));
    this->id = id;
    this->x = x;
    this->y = y;
    this->blank = false;
}

Cell::Cell() {
    connect(this, SIGNAL(clicked()), this, SLOT(cellClicked()));
    this->blank = false;
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
    this->setPixmap(*this->imagePixmap);
}

void Cell::setPixmapAsBlank()
{
    this->setText("powinien pusty");
    this->setBlank(true);
}

bool Cell::isBlank() const
{
    return blank;
}

void Cell::cellClicked() {
    qDebug() << "Mouse event";
    qDebug() << this->id << " x=" <<x<<" y="<<y;
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
