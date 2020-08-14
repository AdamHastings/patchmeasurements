#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
    #pragma comment(lib, "user32.lib")
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static void addNewTimestamp(int m);
    static std::vector<int> click_timestamps;


private:
    Ui::MainWindow *ui;
    int offer = 1;
    int upper = -1;
    int lower = -1;
    bool first_accept = false;

    

    void setFreq();
    void showGoodbye();
    void close();
    void showTask1();
    void showPatch();
    void showTask2();
    void showQ1();
    void q1Response();
    void showQ1Next();
    void showQ3();
    void showQ4();
    void updateOffer_no();
    void updateOffer_yes();
    void showWTA();
    void conclude();
    void task1Continue();
    void task2Continue();
    // LRESULT MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
};

#endif // MAINWINDOW_H
