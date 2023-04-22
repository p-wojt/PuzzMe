#ifndef TEXTUTILS_H
#define TEXTUTILS_H


#include <QString>
#include <type_traits>
class TextUtils
{
public:
    template<typename T>
    static typename std::enable_if<std::is_arithmetic<T>::value, QString>::type
    getTimeDigitsFormatFrom(T number) {
        return number/10 == 0 ? "0" + QString::number(number) : QString::number(number);
    }
};

#endif // TEXTUTILS_H
