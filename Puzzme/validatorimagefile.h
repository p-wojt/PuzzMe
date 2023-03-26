#ifndef VALIDATORIMAGEFILE_H
#define VALIDATORIMAGEFILE_H

#include "validator.h"
#include <QFileInfo>

class ValidatorImageFile : public Validator<QString>
{
public:
    ValidatorImageFile();
    bool validate(QString toValidate);
};

#endif // VALIDATORIMAGEFILE_H
