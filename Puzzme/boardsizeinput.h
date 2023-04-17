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
private:
    QLineEdit *m_lineEdit;
    QPushButton *m_okButton;
    QPushButton *m_cancelButton;
};

#endif // BOARDSIZEINPUT_H
