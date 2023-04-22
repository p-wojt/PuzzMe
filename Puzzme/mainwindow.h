#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *getUi();
private:
    Ui::MainWindow *ui;
    void setupStyles();
    void setupMainWindowStyle();
    void setupTimerStyle();
    void setupLayoutsStyle();
    void setupButtonsStyle();
protected:
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
