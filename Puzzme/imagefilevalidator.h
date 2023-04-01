#ifndef IMAGEFILEVALIDATOR_H
#define IMAGEFILEVALIDATOR_H

#include "validator.h"
#include <QFileInfo>

class ImageFileValidator : public Validator<QString>
{
public:
    ImageFileValidator();
    bool validate(QString toValidate);
};

#endif // VALIDATORIMAGEFILE_H
