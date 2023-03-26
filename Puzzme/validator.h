#ifndef VALIDATOR_H
#define VALIDATOR_H

template < class T >
class Validator
{
public:
    Validator()
    {

    }
    virtual bool validate(T toValidate) = 0;
};

#endif // VALIDATOR_H
