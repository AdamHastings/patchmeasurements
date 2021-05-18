#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "DropBox.h"
#include "PowerMgmt.h"
#include "RegistryUtils.h"
#include <algorithm>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QProcess>
#include <QSettings>
#include <QDebug>
#include <QSslSocket>

#include "crypto.h"

using namespace std;


void MainWindow::enableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (closeFlag);
    setWindowFlags(flags);
    this->show();
}

void MainWindow::disableExitButton() {
//#ifdef QT_NO_DEBUG
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
    //setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | );
    this->show();
//#endif
}

void MainWindow::showStartNext() {
    if (ui.start->not_consent_btn->isChecked()) {
        showGoodbye();
    } else if (!PowerMgmt::runningAsAdmin()) {
        enableExitButton();
        ui.stackedWidget->setCurrentWidget(ui.noadmin);
    } else if (RegistryUtils::isCsEnabled()) {
        enableExitButton();
        ui.stackedWidget->setCurrentWidget(ui.mod);
    } else {
        ui.stackedWidget->setCurrentWidget(ui.monitor);
    }
}

void MainWindow::showModNext() {
    if (ui.mod->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        RegistryUtils::setRegKey("CsEnabled", 1);
        RegistryUtils::setCsEnabled(0);
        ui.stackedWidget->setCurrentWidget(ui.modmade);
    }
}

void MainWindow::showMonitorNext() {
    if (ui.monitor->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        ui.stackedWidget->setCurrentWidget(ui.primary);
    }
}

void MainWindow::showPrimaryNext() {
    if (ui.primary->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        ui.stackedWidget->setCurrentWidget(ui.internet);
    }
}

void MainWindow::showInternetNext() {
    if (ui.internet->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        showForm();
    }
}

void MainWindow::showGoodbye() {
    enableExitButton();
    PowerMgmt::restoreRegistry(); // Don't need to bother restoring other power plans...that's handled elsewhere
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void MainWindow::showTask1() {
    ui.task1->resetPage(QString::fromStdString(ui.form->uni_str));
    ui.stackedWidget->setCurrentWidget(ui.task1);
}

void MainWindow::showTask2() {
    ui.task2->resetPage(QString::fromStdString(ui.form->uni_str));
    ui.stackedWidget->setCurrentWidget(ui.task2);
}

void MainWindow::showTask3() {
    ui.task3->resetPage(QString::fromStdString(ui.form->uni_str));
    ui.stackedWidget->setCurrentWidget(ui.task3);
}

void MainWindow::pickThrottledTask() {
    throttled_task = rand() % 2 + 2;
    unthrottled_task = (throttled_task == 2) ? 3 : 2;
}

void MainWindow::showNotEligible() {
    enableExitButton();
    PowerMgmt::restoreDefaults();
    ui.noteligible->updateText();
    QString results = "worker-id," + QString::fromStdString(ui.form->uni_str) + "\n";
    results += "eligible?,no\n";
    results += "SLOWDOWN," + QString::number(SLOWDOWN) + "\n";
    results += "task1_freq," + QString::number(task1Freq) + "\n";
    results += "check_freq," + QString::number(checkFreq) + "\n";
    DropBox::upload(results, ui.form->uni_str);

    ui.stackedWidget->setCurrentWidget(ui.noteligible);
}

void MainWindow::showPatch0() {
    ui.stackedWidget->setCurrentWidget(ui.patch0);
    ui.stackedWidget->setCurrentWidget(ui.patch0);
    ui.stackedWidget->setCurrentWidget(ui.patch0);
    ui.stackedWidget->setCurrentWidget(ui.patch0);

    // Take a reading
    QProcess proc;
    QProcess cpuproc;
    QProcess ramproc;
    PowerMgmt::getCurrentClockFreqStart(proc);
    PowerMgmt::getCurrentCPUUtilizationStart(cpuproc);
    PowerMgmt::getCurrentRAMUtilizationStart(ramproc);
    ui.patch0->label->setText("We will now make some modifications to your computer. These modifications are only temporary and will end once this experiment concludes.");
    ui.patch0->fill1();
    
    preTasksFreq = PowerMgmt::getCurrentClockFreqRead(proc);
    baselineCPUUtilization = PowerMgmt::getCurrentCPUUtilizationRead(cpuproc);
    baselineRAMUtilization = PowerMgmt::getCurrentRAMUtilizationRead(ramproc);

    
    //if (preTasksFreq == -1) {
    //    PowerMgmt::restoreRegistry();
    //    showNotEligible();
    //} else {
        ui.patch0->fill2();
        PowerMgmt::getDefaultPowercfg();
        PowerMgmt::createCustomPowerPlan();
        PowerMgmt::removeFreqCap();

        PowerMgmt::setFreqCap(100 - SLOWDOWN);
        PowerMgmt::getCurrentClockFreqStart(proc);
        checkFreq = PowerMgmt::getCurrentClockFreqRead(proc);
        qDebug() << "checkFreq: " << checkFreq;
        PowerMgmt::removeFreqCap();


        // Take another reading
        
        PowerMgmt::getCurrentClockFreqStart(proc);
        task1Freq = PowerMgmt::getCurrentClockFreqRead(proc);
        qDebug() << "task1Freq: " << task1Freq;

        // TODO
        // if not slowed down enough
        // cause a failure
        double lowerBound = task1Freq * (100 - (double(SLOWDOWN) + 5))/100;
        double upperBound = task1Freq * (100 - (double(SLOWDOWN) - 5))/100;

        qDebug() << "upper bound: " << upperBound;
        qDebug() << "lower bound: " << lowerBound;

        if (checkFreq < upperBound && checkFreq > lowerBound) {
            eligible = true;
        }
        else {
            eligible = false;
        }
        ui.patch0->fill3();


        ui.patch0->done_label->setText("Done!");
        ui.patch0->continue_btn->setEnabled(true);
    //}
}

void MainWindow::patch0Next() {
    if (eligible) {
        showTask1();
    }
    else {
        showNotEligible();
    }
}

void MainWindow::showPatch1() {
    ui.stackedWidget->setCurrentWidget(ui.patch1);
    if (throttled_task == 2)
        PowerMgmt::setFreqCap(100 - SLOWDOWN);

    // Take a reading
    QProcess proc;
    PowerMgmt::getCurrentClockFreqStart(proc);
    ui.patch1->fillBar();
    task2Freq = PowerMgmt::getCurrentClockFreqRead(proc);

    ui.patch1->done_label->setText("Done!");
    ui.patch1->continue_btn->setEnabled(true);
}

void MainWindow::showPatch2() {
    ui.stackedWidget->setCurrentWidget(ui.patch2);
    if (throttled_task == 3)
        PowerMgmt::setFreqCap(100 - SLOWDOWN);
    else
        PowerMgmt::removeFreqCap();

    // Take a reading
    QProcess proc;
    PowerMgmt::getCurrentClockFreqStart(proc);
    ui.patch2->fillBar();
    task3Freq = PowerMgmt::getCurrentClockFreqRead(proc);

    ui.patch2->done_label->setText("Done!");
    ui.patch2->continue_btn->setEnabled(true);
}

void MainWindow::showPatch3() {
    ui.stackedWidget->setCurrentWidget(ui.patch3);
    PowerMgmt::restoreDefaults();

    // Take a reading
    QProcess proc;
    PowerMgmt::getCurrentClockFreqStart(proc);

    // Get system info
    QProcess proc2;
    PowerMgmt::getSystemConfigStart(proc2);

    ui.patch3->fillBar();
    postTasksFreq = PowerMgmt::getCurrentClockFreqRead(proc);
    system_info = PowerMgmt::getSystemConfigRead(proc2);
    qDebug() << "sysinfo:";
    qDebug() << system_info;

    ui.patch3->done_label->setText("Done!");
    ui.patch3->continue_btn->setEnabled(true);
}

void MainWindow::showRank() {
    ui.stackedWidget->setCurrentWidget(ui.rank);
}

void MainWindow::showAttention() {
    ui.stackedWidget->setCurrentWidget(ui.attention);
}

void MainWindow::showCompare() {
    //vui.compare->setLabels(ui.rank->listWidget);
    ui.stackedWidget->setCurrentWidget(ui.compare);
}

void MainWindow::showPreWTA() {
    ui.preWTA->setLabelText(throttled_task, unthrottled_task, SLOWDOWN);
    ui.stackedWidget->setCurrentWidget(ui.preWTA);
}

void MainWindow::showPostTasks() {
    ui.stackedWidget->setCurrentWidget(ui.posttasks);
}

void MainWindow::showWTA() {
    offer = 0;
    ui.wta->header->setText("Would you be willing to make this computer run " + QString::number(SLOWDOWN) + "% slower in exchange for ");
    ui.wta->updateOffer(offer);
    ui.stackedWidget->setCurrentWidget(ui.wta);
}

QString MainWindow::createResultsString() {
    QString s = "";
    s += "worker-id," + QString::fromStdString(ui.form->uni_str) + "\n";
    s += "attention-check," + QString::number(ui.attention->task2_slower->isChecked()) + "\n";
    s += "wta," + QString::number(offer) + "\n";
    s += "throttled_task," + QString::number(throttled_task) + "\n";
    s += "unthrottled_task," + QString::number(unthrottled_task) + "\n";
    s += "SLOWDOWN," + QString::number(SLOWDOWN) + "\n";
    // s += "fastest," + ui.rank->listWidget->item(0)->text() + "\n";
    // s += "middle," + ui.rank->listWidget->item(1)->text() + "\n";
    // s += "slowest," + ui.rank->listWidget->item(2)->text() + "\n";
    // s += "fastest_vs_middle," + QString::number(ui.compare->arr1->getClicked()) + "\n";
    // s += "middle_vs_slowest," + QString::number(ui.compare->arr2->getClicked()) + "\n";
    // s += "fastest_vs_slowest," + QString::number(ui.compare->arr3->getClicked()) + "\n";
    s += "ranking,";
    if (ui.rank->task2_slower->isChecked()) {
        s += "task2_slower\n";
    }
    else if (ui.rank->task3_slower->isChecked()) {
        s += "task3_slower\n";
    }
    else {
        s += "no_difference\n";
    }
    s += "pre_task_freq," + QString::number(preTasksFreq) + "\n";
    s += "task1_freq," + QString::number(task1Freq) + "\n";
    s += "task2_freq," + QString::number(task2Freq) + "\n";
    s += "task3_freq," + QString::number(task3Freq) + "\n";
    s += "post_task_freq," + QString::number(postTasksFreq) + "\n";
    s += "total_ram," + PowerMgmt::getTotalRAM() + "\n";
    s += "baseline_ram," + baselineRAMUtilization + "\n";
    s += "task1_ram," + ui.task1->ram_utilizations + "\n";
    s += "task2_ram," + ui.task2->ram_utilizations + "\n";
    s += "task3_ram," + ui.task3->ram_utilizations + "\n";
    s += "baseline_cpu," + baselineCPUUtilization + "\n";
    s += "task1_cpu," + ui.task1->cpu_utilizations + "\n";
    s += "task2_cpu," + ui.task2->cpu_utilizations + "\n";
    s += "task3_cpu," + ui.task3->cpu_utilizations + "\n";
    s += "gaming," + QString::number(ui.usage->gaming->isChecked()) + "\n";
    s += "word_processing," + QString::number(ui.usage->word_processing->isChecked()) + "\n";
    s += "spreadsheets," + QString::number(ui.usage->spreadsheets->isChecked()) + "\n";
    s += "programming," + QString::number(ui.usage->programming->isChecked()) + "\n";
    s += "streaming," + QString::number(ui.usage->streaming->isChecked()) + "\n";
    s += "video_editing," + QString::number(ui.usage->video_editing->isChecked()) + "\n";
    s += "animation," + QString::number(ui.usage->animation->isChecked()) + "\n";
    s += "design_tools," + QString::number(ui.usage->design_tools->isChecked()) + "\n";
    s += "web_searches," + QString::number(ui.usage->web_searches->isChecked()) + "\n";
    s += "email," + QString::number(ui.usage->email->isChecked()) + "\n";
    s += "e_reading," + QString::number(ui.usage->e_reading->isChecked()) + "\n";
    s += "social_media," + QString::number(ui.usage->social_media->isChecked()) + "\n";
    s += "video_calls," + QString::number(ui.usage->video_calls->isChecked()) + "\n";
    s += "crypto_mining," + QString::number(ui.usage->crypto_mining->isChecked()) + "\n";
    s += "photo_storage," + QString::number(ui.usage->photo_storage->isChecked()) + "\n";
    s += "shopping," + QString::number(ui.usage->shopping->isChecked()) + "\n";
    s += "other," + QString::number(ui.usage->other->isChecked()) + "\n";
    QString other_input = ui.usage->input->text();
    other_input.replace(",", ";");
    other_input.replace("\n", ";");
    s += "other_input," + other_input + "\n";
    s += "hours," + QString::number(ui.hours->spin->value()) + "\n";
    s += "CsEnabled_default," + QString::number(REBOOT_AT_END) + "\n";
    s += system_info;

    return s;
}

void MainWindow::showForm() {
    ui.stackedWidget->setCurrentWidget(ui.form);
}

void MainWindow::showUsage() {
    ui.stackedWidget->setCurrentWidget(ui.usage);
}

void MainWindow::showHours() {
    ui.stackedWidget->setCurrentWidget(ui.hours);
}

void MainWindow::showDebrief() {
    ui.debrief->setLabelText(throttled_task, SLOWDOWN);
    ui.stackedWidget->setCurrentWidget(ui.debrief);
}

void MainWindow::updateOffer_yes() {
    if (offer <= 4) {
        if (offer == 4) {
            offer = 3;
        }
        showUsage();
    }
    else if (!first_accept) {
        first_accept = true;
        upper = offer;
        lower = offer / 2;
        offer = (lower + upper) / 2;
        ui.wta->updateOffer(offer);
    }
    else {
        upper = offer;
        offer = (lower + upper) / 2;
        if (upper - lower <= 2) {
            showUsage();
        }
        else {
            ui.wta->updateOffer(offer);
        }
    }
}

void MainWindow::updateOffer_no() {
    if (!first_accept) {
        if (offer >= 16384) {
            showUsage();
        } else if (offer == 0) {
            offer = 1;
        }
        else {
            offer *= 2;
        }
        ui.wta->updateOffer(offer);
    }
    else {
        lower = offer;
        offer = (offer + upper) / 2;
        if (upper - lower <= 2) {
            showUsage();
        }
        else {
            ui.wta->updateOffer(offer);
        }
    }
}

void MainWindow::showWithdraw() {
    ui.stackedWidget->setCurrentWidget(ui.withdraw);
}

void MainWindow::showWithdrawNext() {
    if (ui.withdraw->withdraw_btn->isChecked()) {
        enableExitButton();
        ui.withdraw->Withdraw();
    }
    else {
        showDebrief();
    }
}



void MainWindow::tryUpload() {

    //ui.debrief->disableButtons();
    ui.upload->continue_btn->setEnabled(false);
    ui.upload->continue_btn->setVisible(false);
    ui.stackedWidget->setCurrentWidget(ui.upload);
    ui.upload->fillFirstHalf();

    QString results = createResultsString();

    
    bool success = false;
    for (int i = 0; i < 5; i++) {

        // try upload
        try {
            DropBox::upload(results, ui.form->uni_str);
        }
        catch(...) {
            qDebug() << "upload didn't work";
        }
        
        if (DropBox::uploadSuccessful(ui.form->uni_str)) {
            success = true;
            break;
        }
    }
    string filename = ".\\..\\" + ui.form->uni_str + "_results.txt";
    crypto::addFile(filename, results.toStdString(), "q49b0LfAlwP994jbqQf");
    ui.upload->fillSecondHalf();

    // if unsuccessful, make participant manually upload results
    if (success) {
        showFinal();
    }
    else {
        showFail();
    }
}

void MainWindow::showImprove() {
    ui.stackedWidget->setCurrentWidget(ui.improve);
}

void MainWindow::showDecrease() {
    ui.stackedWidget->setCurrentWidget(ui.decrease);
}

void MainWindow::showFail() {
    static int retries = 0;
    retries++;
    if (retries <= 3) {
        ui.stackedWidget->setCurrentWidget(ui.retry);
    }
    else {
        ui.stackedWidget->setCurrentWidget(ui.fail);
    }
}

void MainWindow::showFinal() {
    enableExitButton();
    ui.final->updateText(QString::fromStdString(ui.form->uni_str));
    ui.stackedWidget->setCurrentWidget(ui.final);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);    
    disableExitButton();

    pickThrottledTask();



    connect(ui.start->continue_btn, &QPushButton::clicked, this, &MainWindow::showStartNext);
    //connect(ui.mod->consent_btn, &QPushButton::clicked, this, &MainWindow::showPatch0);
    //connect(ui.mod->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.mod->continue_btn, &QPushButton::clicked, this, &MainWindow::showModNext);
    connect(ui.monitor->continue_btn, &QPushButton::clicked, this, &MainWindow::showMonitorNext);
    connect(ui.primary->continue_btn, &QPushButton::clicked, this, &MainWindow::showPrimaryNext);
    connect(ui.internet->continue_btn, &QPushButton::clicked, this, &MainWindow::showInternetNext);
    connect(ui.form->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch0);

    //connect(ui.patch0->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui.patch0->continue_btn, &QPushButton::clicked, this, &MainWindow::patch0Next);
    connect(ui.task1->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch1);
    connect(ui.patch1->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui.task2->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch2);
    connect(ui.patch2->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask3);
    connect(ui.task3->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch3);
    connect(ui.patch3->continue_btn, &QPushButton::clicked, this, &MainWindow::showPostTasks);
    connect(ui.posttasks->continue_btn, &QPushButton::clicked, this, &MainWindow::showRank);
    connect(ui.rank->continue_btn, &QPushButton::clicked, this, &MainWindow::showAttention);
    connect(ui.attention->continue_btn, &QPushButton::clicked, this, &MainWindow::showPreWTA);
    //connect(ui.compare->continue_btn, &QPushButton::clicked, this, &MainWindow::showPreWTA);
    connect(ui.preWTA->continue_btn, &QPushButton::clicked, this, &MainWindow::showWTA);
    connect(ui.wta->yes_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_yes);
    connect(ui.wta->no_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_no);
    connect(ui.usage->continue_btn, &QPushButton::clicked, this, &MainWindow::showHours);
    connect(ui.hours->continue_btn, &QPushButton::clicked, this, &MainWindow::showImprove);
    //connect(ui.form->continue_btn, &QPushButton::clicked, this, &MainWindow::showDebrief);
    connect(ui.improve->continue_btn, &QPushButton::clicked, this, &MainWindow::showDecrease);
    connect(ui.decrease->continue_btn, &QPushButton::clicked, this, &MainWindow::showDebrief);
    connect(ui.debrief->yes_btn, &QPushButton::clicked, this, &MainWindow::showWithdraw);
    connect(ui.debrief->no_btn, &QPushButton::clicked, this, &MainWindow::tryUpload);
    connect(ui.withdraw->continue_btn, &QPushButton::clicked, this, &MainWindow::showWithdrawNext);
    connect(ui.fail->continue_btn, &QPushButton::clicked, this, &MainWindow::showFinal);
    connect(ui.retry->continue_btn, &QPushButton::clicked, this, &MainWindow::tryUpload);
    

#ifdef QT_DEBUG
    //connect(ui.start->continue_btn, &QPushButton::clicked, this, &MainWindow::showPostTasks);
#endif

}
