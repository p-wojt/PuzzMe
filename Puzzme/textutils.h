#ifndef TEXTUTILS_H
#define TEXTUTILS_H

#include <QString>
#include <type_traits>

/*!
 * \brief Klasa użyteczna pozwalająca transformację numeru na text dodając
 * w przypadku jednej cryfry zero wiodące.
 */
class TextUtils
{
public:
    /*!
     * \brief Dodaje zero wiodące do podanego numeru w parametrze.
     * \param number - typ numeryczny.
     * \return Zwraca łańcuch znaków z możliwym dodanym zerem wiodącym w przypadku
     * jednej cyfry.
     */
    template<typename T>
    static typename std::enable_if<std::is_arithmetic<T>::value, QString>::type
    getTimeDigitsFormatFrom(T number) {
        return number/10 == 0 ? "0" + QString::number(number) : QString::number(number);
    }
};

#endif // TEXTUTILS_H
