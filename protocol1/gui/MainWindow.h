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
    void setFreq(bool b);
    void showGoodbye(bool b);
    void close(bool b);
    void showTask1(bool b);
    void showPatch(bool b);
    void showTask2(bool b);
    void showQ1(bool b);
    void q1Response(bool b);
    void showQ1Next(bool b);
    void showQ3(bool b);
    void showQ4(bool b);
    void updateOffer_yes(bool b);
    void updateOffer_no(bool b);
    void showWTA();
    void conclude();

private:
    Ui::MainWindow *ui;
    int offer = 1;
    int upper = -1;
    int lower = -1;
    bool first_accept = false;
};

#endif // MAINWINDOW_H
