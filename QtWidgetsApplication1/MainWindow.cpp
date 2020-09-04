#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>


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


    #ifdef _WIN23
    for (auto i: MainWindow::click_timestamps) {
        cout << i << " ";
    }
    cout << endl;
    #endif

    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}

bool isCsEnabled() {
    HKEY hKey = HKEY_CURRENT_USER;
    LPCWSTR subKey = L"SYSTEM\\CurrentControlSet\\Control\\Power";
    DWORD options = 0;
    REGSAM samDesired = KEY_READ;// | KEY_WRITE - need ?;

    HKEY OpenResult;

    LPCWSTR pValue = L"CsEnabled";
    DWORD flags = RRF_RT_ANY;

    //Allocationg memory for a DWORD value.
    DWORD dataType;

    DWORD datalength = 255;
    unique_ptr<char[]> buffer;

    bool CsEnabled = RegGetValue(hKey, subKey, pValue, 0, nullptr, buffer.get(), &datalength);
    return CsEnabled;
}

void MainWindow::showStartNext() {
    if (isCsEnabled()) {
        ui->stackedWidget->setCurrentWidget(ui->reg_page);
    } else {
        ui->stackedWidget->setCurrentWidget(ui->task1_page);
    }
}

void MainWindow::showRestartLabel() {
    ui->reg_ok_btn->setDisabled(true);
    ui->reg_notok_btn->setDisabled(true);
    ui->reg_done_label->setText("Your computer's configuration has been changed. You will need to restart your computer for the changes to take place. Please restart your computer now.");
}

//void MainWindow::showRegPage() {
//    ui->stackedWidget->setCurrentWidget(ui->reg_page);
//}

void MainWindow::close() {
    QApplication::quit();
}

//void MainWindow::showTask1() {
//    setFreq(100);
//    ui->stackedWidget->setCurrentWidget(ui->task1_page);
//}

void fillBar(QProgressBar *pb) {
#if QT_NO_DEBUG
    int MAGIC_THRES = 45;

    for (int i = 0; i < MAGIC_THRES; i++) {
        pb->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i = MAGIC_THRES; i <= 100; i++) {
        pb->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
#endif
}

void MainWindow::showPatch() {
    setFreq(50);
    ui->stackedWidget->setCurrentWidget(ui->patch_page);
    fillBar(ui->patch_progress_bar);
    ui->patch_done_label->setText(QApplication::translate("MainWindow", "Done!", Q_NULLPTR));
    ui->patch_continue_btn->setEnabled(true);
}

void MainWindow::showPatch2() {
    ui->stackedWidget->setCurrentWidget(ui->patch2_page);
    // TODO apply or de-apply throttling
    fillBar(ui->patch2_progress_bar);
    ui->patch2_done_label->setText("Done!");
    ui->patch2_continue_btn->setEnabled(true);
}

void MainWindow::showPatch3() {
    ui->stackedWidget->setCurrentWidget(ui->patch3_page);
    // Undo all patches
    // TODO
    fillBar(ui->patch3_progress_bar);
    ui->patch3_done_label->setText("Done! All temporary modifications made to your computer have been undone.");
    ui->patch3_continue_btn->setEnabled(true);
}

void MainWindow::pickThrottledTask() {
    srand( (unsigned)time(NULL) );
    throttled_task = rand() % 2 + 2;
    unthrottled_task = (throttled_task == 2)? 3 : 2;
}

void MainWindow::showTask2() {
    pickThrottledTask();
    if (throttled_task == 2) {
        setFreq(100 - slowdown);
    } else {
        setFreq(100);
    }
    ui->stackedWidget->setCurrentWidget(ui->task2_page);
}

void MainWindow::showTask3() {
    if (throttled_task == 3) {
        setFreq(100 - slowdown);
    } else {
        setFreq(100);
    }
    ui->stackedWidget->setCurrentWidget(ui->task3_page);
}

void MainWindow::showQ1() {
    setFreq(100);
    ui->stackedWidget->setCurrentWidget(ui->q1_page);
}

void MainWindow::q1Response() {
    ui->q1_continue_btn->setEnabled(true);
    if (ui->q1_same_btn->isCheckable()) {
        faster = "same";
    }
    else if (ui->q1_t2faster_btn->isCheckable()) {
        faster = "task2";
    }
    else if (ui->q1_t3faster_btn->isCheckable()) {
        faster = "task3";
    }
}

void MainWindow::showQ1Next() {
    if (ui->q1_t2faster_btn->isChecked()) {
        ui->q2_label->setText("How much faster did your computer feel in Task 2 compared to Task 3?");
        ui->stackedWidget->setCurrentWidget(ui->q2_page);
    } else if (ui->q1_t3faster_btn->isChecked()) {
        ui->q2_label->setText("How much faster did your computer feel in Task 3 compared to Task 2?");
        ui->stackedWidget->setCurrentWidget(ui->q2_page);
    } else{
        showPreWTA();
    }
}

void MainWindow::showPreWTA() {

    speedup_guess = ui->q2_input->value();

    std::string pre_wta_text = "In this experiment, we slowed down Task "  + to_string(throttled_task) + " by " + to_string(slowdown) + "%. In the next section, you will be asked a series of yes/no questions that aim to estimate how much you value a performance loss of " + to_string(slowdown) + "%.";
    ui->pre_wta_label->setText(pre_wta_text.c_str());
    ui->stackedWidget->setCurrentWidget(ui->pre_wta_page);
}

void MainWindow::showWTA() {
    std::string offerstring = "$" + std::to_string(offer) + "?";
    ui->wta_offer->setText(offerstring.c_str());
    std::string offer_text = "Would you be willing to accept a permanent " + to_string(slowdown) + "% on your own computer in exchange for:";
    ui->wta_label->setText(offer_text.c_str());
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
        if (offer == 0) {
            offer = 1;
        } else {
            offer *= 2;
        }
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

void MainWindow::task1Continue() {
#if QT_NO_DEBUG

    if (ui->task1a->isChecked() && 
        ui->task1b->isChecked() && 
        ui->task1c->isChecked() && 
        ui->task1d->isChecked() && 
        ui->task1e->isChecked() && 
        ui->task1f->isChecked() && 
        ui->task1g->isChecked()) 
    {
        ui->task1_continue_btn->setDisabled(false);
    } else {
        ui->task1_continue_btn->setDisabled(true);
    }
#endif
}

void MainWindow::task2Continue() {
    #if QT_NO_DEBUG
    if (ui->task2a->isChecked() && 
        ui->task2b->isChecked() && 
        ui->task2c->isChecked() && 
        ui->task2d->isChecked() && 
        ui->task2e->isChecked() && 
        ui->task2f->isChecked() && 
        ui->task2g->isChecked()) 
    {
        ui->task2_continue_btn->setDisabled(false);
    } else {
        ui->task3_continue_btn->setDisabled(true);
    }
    #endif
}

void MainWindow::task3Continue() {
    #if QT_NO_DEBUG
    if (ui->task3a->isChecked() && 
        ui->task3b->isChecked() && 
        ui->task3c->isChecked() && 
        ui->task3d->isChecked() && 
        ui->task3e->isChecked() && 
        ui->task3f->isChecked() && 
        ui->task3g->isChecked()) 
    {
        ui->task3_continue_btn->setDisabled(false);
    } else {
        ui->task3_continue_btn->setDisabled(true);
    }
    #endif
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    // connect(ui->goodbye_btn, &QPushButton::clicked, this, &MainWindow::close);
    //connect(ui->consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui->consent_btn, &QPushButton::clicked, this, &MainWindow::showStartNext);
    connect(ui->reg_ok_btn, &QPushButton::clicked, this, &MainWindow::showRestartLabel);
    connect(ui->reg_notok_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui->task1_continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch);
    connect(ui->patch_continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui->task2_continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch2);
    connect(ui->patch2_continue_btn, &QPushButton::clicked, this, &MainWindow::showTask3);
    connect(ui->task3_continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch3);
    connect(ui->patch3_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ1);


    
    connect(ui->q1_t2faster_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_t3faster_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_same_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ1Next);
    connect(ui->q2_input, QOverload<int>::of(&QSpinBox::valueChanged), ui->q2_continue_btn, &QPushButton::setEnabled);
    connect(ui->q2_continue_btn, &QPushButton::clicked, this, &MainWindow::showPreWTA);
    connect(ui->pre_wta_continue_btn, &QPushButton::clicked, this, &MainWindow::showWTA);
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

    connect(ui->task3a, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3b, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3c, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3d, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3e, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3f, &QPushButton::clicked, this, &MainWindow::task3Continue);
    connect(ui->task3g, &QPushButton::clicked, this, &MainWindow::task3Continue);


}

MainWindow::~MainWindow()
{
    QApplication::quit();
    delete ui;
}

