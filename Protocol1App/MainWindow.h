#pragma once

#include <QtWidgets/QMainWindow>
#include <QProgressBar>
#include <string>
#include "ui_MainWindow.h"

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "user32.lib")
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindow ui;

    int throttled_task = -1;
    int unthrottled_task = -1;
    // int slowdown = 30;

    int offer = 0;
    int upper = -1;
    int lower = -1;
    bool first_accept = false;

private:
    double preTasksFreq = -1;
    QString baselineCPUUtilization = "";
    QString baselineRAMUtilization = "";
    double task1Freq = -1;
    double task2Freq = -1;
    double task3Freq = -1;
    double postTasksFreq = -1;
    QString system_info;

    void showStartNext();
    void showModNext();
    void showMonitorNext();
    void showPrimaryNext();
    void showInternetNext();
    void showGoodbye();
    void showTask1();
    void showTask2();
    void showTask3();
    void pickThrottledTask();
    void showPatch0();
    void showPatch1();
    void showPatch2();
    void showPatch3();
    void showPostTasks();
    void showRank();
    void showCompare();
    void showPreWTA();
    void showWTA();
    void updateOffer_no();
    void updateOffer_yes();
    void showUsage();
    void showHours();
    void showImprove();
    void showDecrease();
    void showForm();
    void showDebrief();
    void showWithdraw();
    void showWithdrawNext();
    void tryUpload();
    void showFail();
    void showFinal();
    //void showNotEligible();

    //std::string createResultsString();
    QString createResultsString();

    void disableExitButton();
    void enableExitButton();

};
