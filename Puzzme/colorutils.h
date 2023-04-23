#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <QColor>
#include <qpushbutton.h>

/*!
 * \brief Klasa użyteczna zachowująca statyczne funkcje dotycząca stylów.
 */
class ColorUtils
{
public:
    /*!
     * \brief Kolor czarny.
     * \return Zwraca wartość rgb dla koloru czarnego.
     */
    static QColor black() { return QColor(22, 22, 22); }
    /*!
     * \brief Kolor biały.
     * \return Zwraca wartość rgb dla koloru białego.
     */
    static QColor white() { return QColor(248, 248, 248); }
    /*!
     * \brief Kolor niebieski.
     * \return Zwraca wartość rgb dla koloru niebieskiego.
     */
    static QColor blue() { return QColor(14, 76, 146); }
    /*!
     * \brief Ustawia standardowe style dla przycisku, który nie jest wyłączony.
     */
    static void setEnabledStyle(QPushButton *button) {
        button->setStyleSheet("border: 1px solid black; background-color: #0E4C92; color: #F8F8F8; font-family: \"Inter\"; font-size: 16pt; width: 200px; height: 50px;");
    };
    /*!
     * \brief Ustawia standardowe style dla przycisku, który jest wyłączony.
     */
    static void setDisabledStyle(QPushButton *button) {
        button->setStyleSheet("border: 1px solid black; background-color: rgba(14, 76, 146, 50); color: #F8F8F8; font-family: \"Inter\"; font-size: 16pt; width: 200px; height: 50px;");
    };
};

#endif // COLORUTILS_H
