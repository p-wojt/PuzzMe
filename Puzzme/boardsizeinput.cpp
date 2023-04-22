#include "boardsizeinput.h"
#include "gameutils.h"

#include <QIntValidator>
#include <qboxlayout.h>
#include <qmessagebox.h>
#include <qpushbutton.h>

BoardSizeInput::BoardSizeInput(QWidget *parent)
    : QDialog(parent),
      cursorPosition(0)
{
    setWindowTitle("Board size");
          inputLine = new QLineEdit(this);
          inputLine->setValidator(new QIntValidator(GameUtils::MIN_BOARD_SIZE, GameUtils::MAX_BOARD_SIZE, this));
          okButton = new QPushButton("OK", this);
          cancelButton = new QPushButton("Cancel", this);
          connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
          connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
          QVBoxLayout *layout = new QVBoxLayout(this);
          layout->addWidget(inputLine);
          QHBoxLayout *buttonLayout = new QHBoxLayout();
          buttonLayout->addWidget(okButton);
          buttonLayout->addWidget(cancelButton);
          layout->addLayout(buttonLayout);
}

unsigned short BoardSizeInput::getValue()
{
    QString strValue = inputLine->text();
    QValidator::State state = inputLine->validator()->validate(strValue, cursorPosition);
    if(state == QValidator::Acceptable) {
        return strValue.toShort();
    } else {
        QMessageBox::information(this, "Puzzme", "Board size should be between 3 and 9! Board have been set to default size: 3");
        return GameUtils::MIN_BOARD_SIZE;
    }
}
