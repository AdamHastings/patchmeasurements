#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

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

    #ifdef _WIN32
    static void addNewTimestamp(int m);
    static void incKeystrokes();
    static std::vector<long long> click_timestamps;
    static int keystrokes;
    #endif

    int WTA;
    /* Encoding 
    *   0 = The speeds of Tasks 2 and 3 felt the same
    *   2 = Task 2 felt faster
    *   3 = Task 3 felt faster
    */
    std::string faster;
    int speedup_guess;


private:
    Ui::MainWindow *ui;    
    int offer = 0;
    int upper = -1;
    int lower = -1;
    bool first_accept = false;

    int slowdown = 30;
    int throttled_task = -1;
    int unthrottled_task = -1;

    

    void setFreq(int p);
    void showGoodbye();
    void close();
    void showStartNext();
    void showRegPage();
    void showRestartLabel();
    void showTask1();
    //void fillBar(QProgressBar *pb);
    void showPatch();
    void showPatch2();
    void showPatch3();
    void showTask2();
    void showTask3();
    void showQ1();
    void q1Response();
    void showQ1Next();
    void showQ3();
    void showQ4();
    void updateOffer_no();
    void updateOffer_yes();
    void showPreWTA();
    void showWTA();
    void conclude();
    void task1Continue();
    void task2Continue();
    void task3Continue();
    void pickThrottledTask();
    // LRESULT MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
};

#endif // MAINWINDOW_H
