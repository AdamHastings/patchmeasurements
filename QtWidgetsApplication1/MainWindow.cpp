#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <qsettings.h>
#include <qprocess.h>
#include <sstream>


using namespace std;


vector<int> parsePowercfgOutput(string s) {
    // gets last two valuesand returns in vector
    vector<string> tokens;

    istringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        tokens.push_back(tmp);
        cout << tmp << endl;
    }

    cout << tokens[tokens.size()-1] << endl;
    cout << tokens[tokens.size()-7] << endl;

    vector<int> retvec{0, 0};
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


//void MainWindow::showModPage() {
//
//}


bool isCsEnabled() {
    QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
    return (bool)reg.value("CsEnabled").toInt();
}

void MainWindow::showStartNext() {
    if (isCsEnabled()) {
        ui->stackedWidget->setCurrentWidget(ui->reg_page);
    } else {
        getDefaultPowercfg();
        ui->stackedWidget->setCurrentWidget(ui->mod_page);
    }
}

void MainWindow::showRestartLabel() {

    QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
    reg.setValue("CsEnabled", 0);
    cout << reg.value("CsEnabled").toInt() << endl;

    // Update app
    ui->reg_ok_btn->setDisabled(true);
    ui->reg_notok_btn->setDisabled(true);
    ui->reg_done_label->setText("Your computer's configuration has been changed. You will need to reboot your computer for the changes to take place. Please restart your computer and re-run this program.");
}

void MainWindow::close() {
    QApplication::quit();
}

void MainWindow::showTask1() {
    //setFreq(100);
    ui->stackedWidget->setCurrentWidget(ui->task1_page);
}

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

void MainWindow::restoreSettings() {

}

void MainWindow::showQ1() {
    //setFreq(100);
    restoreSettings();
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
    connect(ui->mod_not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui->mod_consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
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

    //connect(ui->task1a, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1b, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1c, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1d, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1e, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1f, &QPushButton::clicked, this, &MainWindow::task1Continue);
    //connect(ui->task1g, &QPushButton::clicked, this, &MainWindow::task1Continue);

    connect(ui->task1a, &QPushButton::clicked, ui->task1b, &QCheckBox::setEnabled);
    connect(ui->task1b, &QPushButton::clicked, ui->task1c, &QCheckBox::setEnabled);
    connect(ui->task1c, &QPushButton::clicked, ui->task1d, &QCheckBox::setEnabled);
    connect(ui->task1d, &QPushButton::clicked, ui->task1e, &QCheckBox::setEnabled);
    connect(ui->task1e, &QPushButton::clicked, ui->task1f, &QCheckBox::setEnabled);
    connect(ui->task1f, &QPushButton::clicked, ui->task1g, &QCheckBox::setEnabled);
    connect(ui->task1g, &QPushButton::clicked, ui->task1h, &QCheckBox::setEnabled);
    connect(ui->task1h, &QPushButton::clicked, ui->task1i, &QCheckBox::setEnabled);
    connect(ui->task1i, &QPushButton::clicked, ui->task1j, &QCheckBox::setEnabled);
    connect(ui->task1j, &QPushButton::clicked, ui->task1_continue_btn, &QPushButton::setEnabled);

    connect(ui->task1a, &QPushButton::clicked, ui->task1a, &QCheckBox::setDisabled);
    connect(ui->task1b, &QPushButton::clicked, ui->task1b, &QCheckBox::setDisabled);
    connect(ui->task1c, &QPushButton::clicked, ui->task1c, &QCheckBox::setDisabled);
    connect(ui->task1d, &QPushButton::clicked, ui->task1d, &QCheckBox::setDisabled);
    connect(ui->task1e, &QPushButton::clicked, ui->task1e, &QCheckBox::setDisabled);
    connect(ui->task1f, &QPushButton::clicked, ui->task1f, &QCheckBox::setDisabled);
    connect(ui->task1g, &QPushButton::clicked, ui->task1g, &QCheckBox::setDisabled);
    connect(ui->task1h, &QPushButton::clicked, ui->task1h, &QCheckBox::setDisabled);
    connect(ui->task1i, &QPushButton::clicked, ui->task1i, &QCheckBox::setDisabled);
    connect(ui->task1j, &QPushButton::clicked, ui->task1j, &QCheckBox::setDisabled);

    connect(ui->task2a, &QPushButton::clicked, ui->task2b, &QCheckBox::setEnabled);
    connect(ui->task2b, &QPushButton::clicked, ui->task2c, &QCheckBox::setEnabled);
    connect(ui->task2c, &QPushButton::clicked, ui->task2d, &QCheckBox::setEnabled);
    connect(ui->task2d, &QPushButton::clicked, ui->task2e, &QCheckBox::setEnabled);
    connect(ui->task2e, &QPushButton::clicked, ui->task2f, &QCheckBox::setEnabled);
    connect(ui->task2f, &QPushButton::clicked, ui->task2g, &QCheckBox::setEnabled);
    connect(ui->task2g, &QPushButton::clicked, ui->task2h, &QCheckBox::setEnabled);
    connect(ui->task2h, &QPushButton::clicked, ui->task2i, &QCheckBox::setEnabled);
    connect(ui->task2i, &QPushButton::clicked, ui->task2j, &QCheckBox::setEnabled);
    connect(ui->task2j, &QPushButton::clicked, ui->task2_continue_btn, &QPushButton::setEnabled);
    
    connect(ui->task2a, &QPushButton::clicked, ui->task2a, &QCheckBox::setDisabled);
    connect(ui->task2b, &QPushButton::clicked, ui->task2b, &QCheckBox::setDisabled);
    connect(ui->task2c, &QPushButton::clicked, ui->task2c, &QCheckBox::setDisabled);
    connect(ui->task2d, &QPushButton::clicked, ui->task2d, &QCheckBox::setDisabled);
    connect(ui->task2e, &QPushButton::clicked, ui->task2e, &QCheckBox::setDisabled);
    connect(ui->task2f, &QPushButton::clicked, ui->task2f, &QCheckBox::setDisabled);
    connect(ui->task2g, &QPushButton::clicked, ui->task2g, &QCheckBox::setDisabled);
    connect(ui->task2h, &QPushButton::clicked, ui->task2h, &QCheckBox::setDisabled);
    connect(ui->task2i, &QPushButton::clicked, ui->task2i, &QCheckBox::setDisabled);
    connect(ui->task2j, &QPushButton::clicked, ui->task2j, &QCheckBox::setDisabled);

    connect(ui->task3a, &QPushButton::clicked, ui->task3b, &QCheckBox::setEnabled);
    connect(ui->task3b, &QPushButton::clicked, ui->task3c, &QCheckBox::setEnabled);
    connect(ui->task3c, &QPushButton::clicked, ui->task3d, &QCheckBox::setEnabled);
    connect(ui->task3d, &QPushButton::clicked, ui->task3e, &QCheckBox::setEnabled);
    connect(ui->task3e, &QPushButton::clicked, ui->task3f, &QCheckBox::setEnabled);
    connect(ui->task3f, &QPushButton::clicked, ui->task3g, &QCheckBox::setEnabled);
    connect(ui->task3g, &QPushButton::clicked, ui->task3h, &QCheckBox::setEnabled);
    connect(ui->task3h, &QPushButton::clicked, ui->task3i, &QCheckBox::setEnabled);
    connect(ui->task3i, &QPushButton::clicked, ui->task3j, &QCheckBox::setEnabled);
    connect(ui->task3j, &QPushButton::clicked, ui->task3_continue_btn, &QPushButton::setEnabled);
    
    connect(ui->task3a, &QPushButton::clicked, ui->task3a, &QCheckBox::setDisabled);
    connect(ui->task3b, &QPushButton::clicked, ui->task3b, &QCheckBox::setDisabled);
    connect(ui->task3c, &QPushButton::clicked, ui->task3c, &QCheckBox::setDisabled);
    connect(ui->task3d, &QPushButton::clicked, ui->task3d, &QCheckBox::setDisabled);
    connect(ui->task3e, &QPushButton::clicked, ui->task3e, &QCheckBox::setDisabled);
    connect(ui->task3f, &QPushButton::clicked, ui->task3f, &QCheckBox::setDisabled);
    connect(ui->task3g, &QPushButton::clicked, ui->task3g, &QCheckBox::setDisabled);
    connect(ui->task3h, &QPushButton::clicked, ui->task3h, &QCheckBox::setDisabled);
    connect(ui->task3i, &QPushButton::clicked, ui->task3i, &QCheckBox::setDisabled);
    connect(ui->task3j, &QPushButton::clicked, ui->task3j, &QCheckBox::setDisabled);



    //connect(ui->task2a, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2b, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2c, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2d, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2e, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2f, &QPushButton::clicked, this, &MainWindow::task2Continue);
    //connect(ui->task2g, &QPushButton::clicked, this, &MainWindow::task2Continue);

    //connect(ui->task3a, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3b, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3c, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3d, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3e, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3f, &QPushButton::clicked, this, &MainWindow::task3Continue);
    //connect(ui->task3g, &QPushButton::clicked, this, &MainWindow::task3Continue);
}

MainWindow::~MainWindow() {
    delete ui;
}

