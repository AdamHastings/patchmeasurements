#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <iostream>




using namespace std;

void MainWindow::setFreq(int p) {

    #ifdef _WIN32

    string min_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + to_string(p);
    string min_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + to_string(p);
    string max_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + to_string(p);
    string max_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + to_string(p);

    WinExec(min_ac_str.c_str(), SW_HIDE);
    WinExec(min_dc_str.c_str(), SW_HIDE);
    WinExec(max_ac_str.c_str(), SW_HIDE);
    WinExec(max_dc_str.c_str(), SW_HIDE);

    #endif

    return;
}

void MainWindow::showGoodbye() {
   cout << "---\n";


    for (auto i: MainWindow::click_timestamps) {
        cout << i << " ";
    }
    cout << endl;

    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}

void MainWindow::close() {
    QApplication::quit();
}

void MainWindow::showTask1() {
    setFreq(100);
    ui->stackedWidget->setCurrentWidget(ui->task1_page);
}

void MainWindow::showPatch() {
    setFreq(50);
    ui->stackedWidget->setCurrentWidget(ui->patch_page);

    int MAGIC_THRES = 24;

    for (int i=0; i<MAGIC_THRES; i++) {
        ui->patch_progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i=MAGIC_THRES; i<=100; i++) {
        ui->patch_progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ui->patch_continue_btn->setEnabled(true);
    ui->patch_continue_btn->setDisabled(false);

    ui->patch_done_label->setText(QApplication::translate("MainWindow", "Done!", Q_NULLPTR));
}

void MainWindow::showTask2() {
    ui->stackedWidget->setCurrentWidget(ui->task2_page);
}

void MainWindow::showQ1() {
    setFreq(100);
    ui->stackedWidget->setCurrentWidget(ui->q1_page);
}

void MainWindow::q1Response() {
    ui->q1_continue_btn->setEnabled(true);
}

void MainWindow::showQ1Next() {
    if (ui->q1_yes_btn->isChecked()) {
        ui->stackedWidget->setCurrentWidget(ui->q2_page);
    } else{
        ui->stackedWidget->setCurrentWidget(ui->q3_page);
    }
}

void MainWindow::showQ3() {
    ui->stackedWidget->setCurrentWidget(ui->q3_page);
}

void MainWindow::showQ4() {
    ui->stackedWidget->setCurrentWidget(ui->q4_page);
}

void MainWindow::showWTA() {
    std::string offerstring = "$" + std::to_string(offer) + "?";
    char chrarr[offerstring.length() + 1];
    strcpy(chrarr, offerstring.c_str());
    ui->wta_offer->setText(chrarr);
    ui->stackedWidget->setCurrentWidget(ui->wta_page);
}

void MainWindow::updateOffer_yes() {
    if (offer < 4) {
        conclude();
    } else if (!first_accept) {
        first_accept = true;
        upper = offer;
        lower = offer/2;
        offer = (lower + upper)/2;
        showWTA();
    } else {
        upper = offer;
        offer = (lower + upper)/2;
        if (upper - lower <= 2) {
            conclude();
        } else {
            showWTA();
        }
    }
}

void MainWindow::updateOffer_no() {
    if (!first_accept) {
        offer *= 2;
        showWTA();
    } else {
        lower = offer;
        offer = (offer + upper)/2;
        if (upper - lower <= 2) {
            conclude();
        } else {
            showWTA();
        }
    }
}

vector<int> MainWindow::click_timestamps;

void MainWindow::conclude() {
 

    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}

void MainWindow::task1Continue() {
    if (ui->task1a->isChecked() && 
        ui->task1b->isChecked() && 
        ui->task1c->isChecked() && 
        ui->task1d->isChecked() && 
        ui->task1e->isChecked() && 
        ui->task1f->isChecked() && 
        ui->task1g->isChecked()) 
    {
        ui->task1_continue_btn->setDisabled(false);
    }
}

void MainWindow::task2Continue() {
    if (ui->task2a->isChecked() && 
        ui->task2b->isChecked() && 
        ui->task2c->isChecked() && 
        ui->task2d->isChecked() && 
        ui->task2e->isChecked() && 
        ui->task2f->isChecked() && 
        ui->task2g->isChecked()) 
    {
        ui->task2_continue_btn->setDisabled(false);
    }
}


void MainWindow::addNewTimestamp(int m) {
    cout << "adding " + to_string(m) << endl;
    click_timestamps.push_back(m);
    return;
}

#ifdef _WIN32


HHOOK hHook = NULL;

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {   
    
    switch( wParam ) {
        case WM_LBUTTONDOWN:  
            const auto p1 = std::chrono::system_clock::now();
            // const auto m std::chrono::duration_cast<std::chrono::milliseconds>(
                //    p1.time_since_epoch()).count() << '\n';
            // click_timestamps.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(p1.time_since_epoch()).count());
            int m = chrono::duration_cast<chrono::milliseconds>(p1.time_since_epoch()).count();
            cout << m << endl;
            MainWindow::addNewTimestamp(m);

    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

#endif


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    #ifdef _WIN32
    hHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
    if (hHook == NULL) {
        cout << "Hook failed" << endl;
    }
    #endif

    ui->setupUi(this);

    connect(ui->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui->goodbye_btn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui->task1_continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch);
    connect(ui->patch_continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui->task2_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ1);
    connect(ui->q1_yes_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_no_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ1Next);
    connect(ui->q2_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ3);
    connect(ui->q3_yes_btn, &QPushButton::clicked, ui->q3_continue_btn, &QPushButton::setEnabled);
    connect(ui->q3_no_btn, &QPushButton::clicked, ui->q3_continue_btn, &QPushButton::setEnabled);
    connect(ui->q3_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ4);
    connect(ui->q4_continue_btn, &QPushButton::clicked, this, &MainWindow::showWTA);
    connect(ui->wta_yes_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_yes);
    connect(ui->wta_no_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_no);

    connect(ui->task1a, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1b, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1c, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1d, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1e, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1f, &QPushButton::clicked, this, &MainWindow::task1Continue);
    connect(ui->task1g, &QPushButton::clicked, this, &MainWindow::task1Continue);

    connect(ui->task2a, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2b, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2c, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2d, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2e, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2f, &QPushButton::clicked, this, &MainWindow::task2Continue);
    connect(ui->task2g, &QPushButton::clicked, this, &MainWindow::task2Continue);


}

MainWindow::~MainWindow()
{
    delete ui;
}
