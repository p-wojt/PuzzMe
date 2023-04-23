#ifndef IMAGEFILEVALIDATOR_H
#define IMAGEFILEVALIDATOR_H

#include <QFileInfo>
#include "validator.h"

/*!
 * \brief Rozszerzenie klasy Validator do sprawdzenia typów roszerzeń pliku obrazka.
 */
class ImageFileValidator : public Validator<QString>
{
public:
    ImageFileValidator() : Validator<QString>() {};
    /*!
     * \brief Walidacja pliku - rozszerzenie jpg lub png.
     * \param toValidate nazwa pliku do walidacji.
     * \return Zwraca czy podany plik jest możliwy do importu.
     */
    bool validate(QString toValidate);
};

#endif // VALIDATORIMAGEFILE_H
