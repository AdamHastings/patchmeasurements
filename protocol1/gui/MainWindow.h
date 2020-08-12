#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    // void setFreq();
    void showGoodbye(bool b);
    // void close();
    // void showTask1();
    // void showPatch();
    // void showTask2();
    // void showQ1();
    // void q1Response();
    // void showQ1Next();
    // void showQ3();
    // void q3Response();
    // void showQ4();
    // void showWTA();
    // void updateOffer_yes();
    // void updateOffer_no();
    // void conclude();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
