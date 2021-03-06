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

private:
    Ui::MainWindow *ui;
    void calculateHashOfBlock1();
    void calculateHashOfBlock2();
    void calculateHashOfBlock3();
    void calculateHashOfBlock4();
    void calculateHashOfBlock5();
    void calculateHashOfBlock6();
    void calculateHashOfBlock7();
    void calculateHashOfBlock8();
    void calculateHashOfBlock9();
};
#endif // MAINWINDOW_H
