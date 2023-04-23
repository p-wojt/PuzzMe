#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Klasa głownego okna, zawierająca ustawienia widoku okien.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief Zawraca ui odpowiadający MainWindow.
     * \return ui MainWindow.
     */
    Ui::MainWindow *getUi();
private:
    Ui::MainWindow *ui;
    /*!
     * \brief Ustawia wszystkie style.
     */
    void setupStyles();
    /*!
     * \brief Ustawia style głównego okna.
     */
    void setupMainWindowStyle();
    /*!
     * \brief Ustawia style czasomierza.
     */
    void setupTimerStyle();
    /*!
     * \brief Ustawia style layoutów.
     */
    void setupLayoutsStyle();
    /*!
     * \brief Ustawia style przycisków.
     */
    void setupButtonsStyle();
protected:
    /*!
     * \brief Wykonuje się w trakcie zmiany wielkości okna.
     * \param event zmiany rozmiaru okna.
     */
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
