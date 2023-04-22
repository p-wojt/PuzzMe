#include "cell.h"
#include "QWidget"
#include "gameutils.h"

Cell::Cell(unsigned short id, unsigned short x, unsigned short y, const QString &text, QWidget* parent, Qt::WindowFlags f)
    : QLabel(text, parent) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->blank = false;
    this->imagePixmap = nullptr;
}

Cell::Cell() {
    this->blank = false;
    this->imagePixmap = nullptr;
}

Cell::~Cell() {
    delete imagePixmap;
}

unsigned short Cell::getId()
{
    return this->id;
}

void Cell::setId(unsigned short id)
{
    this->id = id;
}

void Cell::mousePressEvent(QMouseEvent* event) {
    if(GameUtils::isGameStarted) {
        emit cellClicked(this);
    }
}

QPixmap *Cell::getImagePixmap()
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

void Cell::setAsBlank()
{
    this->setPixmapAsNumber();
    this->setText("");
    this->setBlank(true);
}

bool Cell::isBlank()
{
    return blank;
}

unsigned short int Cell::getX() {
    return this->x;
}

unsigned short int Cell::getY() {
    return this->y;
}

bool Cell::isImageSet()
{
    return this->imagePixmap != nullptr;
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
