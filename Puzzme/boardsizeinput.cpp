#include "boardsizeinput.h"
#include <QDialog>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

BoardSizeInput::BoardSizeInput(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Input Value"));
          m_lineEdit = new QLineEdit(this);
          QIntValidator *validator = new QIntValidator(3, 6, this);
          m_lineEdit->setValidator(validator);
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
    return m_lineEdit->text().toShort();
}
