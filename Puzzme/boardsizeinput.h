#ifndef BOARDSIZEINPUT_H
#define BOARDSIZEINPUT_H

#include <QDialog>
#include <qlineedit.h>

class BoardSizeInput : public QDialog
{
public:
    BoardSizeInput(QWidget *parent = nullptr);
    unsigned short getValue();
private:
    QLineEdit *inputLine;
    QPushButton *okButton;
    QPushButton *cancelButton;
    int cursorPosition;
};

#endif // BOARDSIZEINPUT_H
