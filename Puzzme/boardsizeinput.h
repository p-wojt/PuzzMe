#ifndef BOARDSIZEINPUT_H
#define BOARDSIZEINPUT_H

#include <QDialog>
#include <qlineedit.h>

/*!
 * \brief Klasa reprezentująca okno dialogowe służące do wpisania
 * rozmiariu planszy.
 */
class BoardSizeInput : public QDialog
{
public:
    BoardSizeInput(QWidget *parent = nullptr);
    /*!
     * \brief Pobiera wartość wpisaną w polu sprawdzając czy spełnia określony warunek walidacji.
     * \return rozmiar planszy.
     */
    unsigned short getValue();
private:
    QLineEdit *inputLine;
    QPushButton *okButton;
    QPushButton *cancelButton;
    int cursorPosition;
};

#endif // BOARDSIZEINPUT_H
