#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <QColor>
#include <qpushbutton.h>

class ColorUtils
{
public:
    static QColor black() { return QColor(22, 22, 22); }
    static QColor white() { return QColor(248, 248, 248); }
    static QColor blue() { return QColor(14, 76, 146); }
    static void setEnabledStyle(QPushButton *button) {
        button->setStyleSheet("border: 1px solid black; background-color: #0E4C92; color: #F8F8F8; font-family: \"Inter\"; font-size: 16pt; width: 200px; height: 50px;");
    };
    static void setDisabledStyle(QPushButton *button) {
        button->setStyleSheet("border: 1px solid black; background-color: rgba(14, 76, 146, 50); color: #F8F8F8; font-family: \"Inter\"; font-size: 16pt; width: 200px; height: 50px;");
    };
};

#endif // COLORUTILS_H
