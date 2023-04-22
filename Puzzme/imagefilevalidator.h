#ifndef IMAGEFILEVALIDATOR_H
#define IMAGEFILEVALIDATOR_H

#include <QFileInfo>
#include "validator.h"

class ImageFileValidator : public Validator<QString>
{
public:
    ImageFileValidator() : Validator<QString>() {};
    bool validate(QString toValidate);
};

#endif // VALIDATORIMAGEFILE_H
