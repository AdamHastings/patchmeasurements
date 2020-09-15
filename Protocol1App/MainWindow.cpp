#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "DropBox.h"

#include <thread>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <QProcess>
using namespace std;

void MainWindow::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void MainWindow::showTask1() {
    ui.stackedWidget->setCurrentWidget(ui.task1);
}

void MainWindow::showTask2() {
    ui.stackedWidget->setCurrentWidget(ui.task2);
}

void MainWindow::showTask3() {
    ui.stackedWidget->setCurrentWidget(ui.task3);
}

vector<int> parsePowercfgOutput(string s) {
    // gets last two valuesand returns in vector
    vector<string> tokens;

    istringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        tokens.push_back(tmp);
        cout << tmp << endl;
    }

    cout << tokens[tokens.size() - 1] << endl;
    cout << tokens[tokens.size() - 7] << endl;

    vector<int> retvec{ 0, 0 };
    return retvec;
}

void MainWindow::getDefaultPowercfg() {
    string get_max_default = "powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX";
    string get_min_default = "powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN";

    QProcess process;
    process.start("powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX");
    process.waitForFinished(-1);

    //string output = process.readAllStandardOutput().toStdString();
    vector<int> maxs = parsePowercfgOutput(process.readAllStandardOutput().toStdString());

    process.start("powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN");
    process.waitForFinished(-1);

    //output = process.readAllStandardOutput().toStdString();
    vector<int> mins = parsePowercfgOutput(process.readAllStandardOutput().toStdString());


    default_ACProcThrottleMin = mins[0];
    default_DCProcThrottleMin = mins[1];
    default_ACProcThrottleMax = maxs[0];
    default_DCProcThrottleMax = maxs[1];

}

void MainWindow::setFreq(int p) {
#if QT_NO_DEBUG
#ifdef _WIN32

    std::string min_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(p);
    std::string min_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(p);
    std::string max_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + std::to_string(p);
    std::string max_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + std::to_string(p);

    WinExec(min_ac_str.c_str(), SW_HIDE);
    WinExec(min_dc_str.c_str(), SW_HIDE);
    WinExec(max_ac_str.c_str(), SW_HIDE);
    WinExec(max_dc_str.c_str(), SW_HIDE);

#endif
#endif
}

void MainWindow::pickThrottledTask() {
    srand((unsigned)time(NULL));
    throttled_task = rand() % 2 + 2;
    unthrottled_task = (throttled_task == 2) ? 3 : 2;
}

void MainWindow::showPatch1() {
    ui.stackedWidget->setCurrentWidget(ui.patch1);
    pickThrottledTask();
    ui.patch1->fillBar();
    if (throttled_task == 2) {
        setFreq(100 - slowdown);
    }
    else {
        setFreq(100);
    }
    ui.patch1->done_label->setText("Done!");
    ui.patch1->continue_btn->setEnabled(true);
}

void MainWindow::showPatch2() {
    ui.stackedWidget->setCurrentWidget(ui.patch2);
    ui.patch2->fillBar();
    ui.patch2->done_label->setText("Done!");
    ui.patch2->continue_btn->setEnabled(true);
}

void MainWindow::showPatch3() {
    ui.stackedWidget->setCurrentWidget(ui.patch3);
    ui.patch3->fillBar();
    ui.patch3->done_label->setText("Done!");
    ui.patch3->continue_btn->setEnabled(true);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //DropBox::upload("Protocol1App");

    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.start->consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui.task1->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch1);
    connect(ui.patch1->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui.task2->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch2);
    connect(ui.patch2->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask3);
    connect(ui.task3->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch3);

}
