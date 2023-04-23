#ifndef MINUTETIMER_H
#define MINUTETIMER_H

#include "timer.h"
#include "mainwindow.h"
#include <QLCDNumber>

/*!
 * \brief Klasa przedstawiający rozszerzony czasomierz do obecnego przypadku.
 */
class ExtenedTimer : public Timer
{
public:
    ExtenedTimer(Ui::MainWindow *ui);
    ~ExtenedTimer();
    /*!
     * \brief Startuje czasomierz.
     */
    void start();
    /*!
     * \brief Zatrzymuje czasomierz.
     */
    void stop();
    /*!
     * \brief Resetuje czasomierz.
     */
    void reset();
    /*!
     * \brief Przedstawia działanie czasomierza sekundę.
     */
    void process();
    /*!
     * \brief Odświeża widok czasomierza.
     */
    void updateView();
private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
    Ui::MainWindow *ui;
};

#endif // MINUTETIMER_H
