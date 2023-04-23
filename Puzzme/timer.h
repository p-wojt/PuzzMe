#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

/*!
 * \brief Klasa abstrakcyjna zawierająca opis zwykłego czasomierza.
 */
class Timer : public QObject
{
    Q_OBJECT
public:
    Timer();
    ~Timer();
    /*!
     * \brief Metoda czysto wirtualna reprezentująca start czasomierza.
     */
    virtual void start() = 0;
    /*!
     * \brief Metoda czysto wirtualna reprezentująca zatrzymanie czasomierza.
     */
    virtual void stop() = 0;
    /*!
     * \brief Metoda czysto wirtualna reprezentująca zresetowanie czasomierza.
     */
    virtual void reset() = 0;
protected:
    QTimer *qTimer;
};

#endif // TIMER_H
