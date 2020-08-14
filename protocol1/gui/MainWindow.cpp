#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
#include <string>
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #pragma comment(lib, "user32.lib")
#endif


using namespace std;

void MainWindow::setFreq() {
    return;
}

void MainWindow::showGoodbye() {
    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}

void MainWindow::close() {
    QApplication::quit();
}

void MainWindow::showTask1() {
    ui->stackedWidget->setCurrentWidget(ui->task1_page);
}

void MainWindow::showPatch() {
    ui->stackedWidget->setCurrentWidget(ui->patch_page);

    int MAGIC_THRES = 24;

    for (int i=0; i<MAGIC_THRES; i++) {
        ui->patch_progress_bar->setValue(i);
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i=MAGIC_THRES; i<=100; i++) {
        ui->patch_progress_bar->setValue(i);
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ui->patch_continue_btn->setEnabled(true);
    ui->patch_continue_btn->setDisabled(false);

    ui->patch_done_label->setText(QApplication::translate("MainWindow", "Done!", Q_NULLPTR));
}

void MainWindow::showTask2() {
    ui->stackedWidget->setCurrentWidget(ui->task2_page);
}

void MainWindow::showQ1() {
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

void MainWindow::conclude() {
    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}


#ifdef _WIN32

HHOOK hHook = NULL;

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {   
    
    switch( wParam )
    {
      case WM_LBUTTONDOWN:  cout << "Left click" << endl; // Left click
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


}

MainWindow::~MainWindow()
{
    delete ui;
}
