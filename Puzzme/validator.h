#ifndef VALIDATOR_H
#define VALIDATOR_H

/*!
 * \brief Klasa abstrakcyjna walidatora.
 */
template < class T >
class Validator
{
public:
    /*!
     * \brief Waliduje podany typ.
     * \param toValidate element do walidacji.
     * \return Zwraca wartość logiczną mówiącą czy spełnia on walidację.
     */
    virtual bool validate(T toValidate) = 0;
};

#endif // VALIDATOR_H
