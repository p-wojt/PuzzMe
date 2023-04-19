#include "boardsizeinput.h"
#include <QDialog>
#include <QIntValidator>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

BoardSizeInput::BoardSizeInput(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Board size"));
          m_lineEdit = new QLineEdit(this);
          m_lineEdit->setValidator(new QIntValidator(3, 6, this));
          m_okButton = new QPushButton(tr("OK"), this);
          m_cancelButton = new QPushButton(tr("Cancel"), this);
          connect(m_okButton, &QPushButton::clicked, this, &QDialog::accept);
          connect(m_cancelButton, &QPushButton::clicked, this, &QDialog::reject);
          QVBoxLayout *layout = new QVBoxLayout(this);
          layout->addWidget(m_lineEdit);
          QHBoxLayout *buttonLayout = new QHBoxLayout();
          buttonLayout->addWidget(m_okButton);
          buttonLayout->addWidget(m_cancelButton);
          layout->addLayout(buttonLayout);
}

unsigned short BoardSizeInput::getValue()
{
    short value = m_lineEdit->text().toShort();
    if(value >= 3 && value <= 9 ) {
        return value;
    } else {
        QMessageBox::information(this, "Puzzme", "Board size should be between 3 and 9! Board have been set to default size: 3");
        return 3;
    }
}
