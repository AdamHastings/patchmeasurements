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
#include <sstream>
#include <iostream>
#include <QProcess>
#include <QSettings>
#include <QDebug>
using namespace std;


void MainWindow::enableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (closeFlag);
    setWindowFlags(flags);
    this->show();
}

void MainWindow::disableExitButton() {
#ifdef QT_NO_DEBUG
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
    this->show();
#endif
}


void MainWindow::showStartNext() {
    if (!PowerMgmt::runningAsAdmin()) {
        ui.stackedWidget->setCurrentWidget(ui.noadmin);
    } else if (RegistryUtils::isCsEnabled()) {
        ui.stackedWidget->setCurrentWidget(ui.regedit);
    } else {
        ui.stackedWidget->setCurrentWidget(ui.mod);
    }
}

void MainWindow::showGoodbye() {
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void MainWindow::showTask1() {
    disableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.task1);
}

void MainWindow::showTask2() {
    ui.stackedWidget->setCurrentWidget(ui.task2);
}

void MainWindow::showTask3() {
    ui.stackedWidget->setCurrentWidget(ui.task3);
}

void MainWindow::pickThrottledTask() {
    srand((unsigned)time(NULL));
    throttled_task = rand() % 2 + 2;
    unthrottled_task = (throttled_task == 2) ? 3 : 2;
}

void MainWindow::showPatch0() {
    ui.stackedWidget->setCurrentWidget(ui.patch0);

    // Take a reading
    QProcess proc;
    PowerMgmt::getCurrentClockFreqStart(proc);
    ui.patch0->fillBar();
    preTasksFreq = PowerMgmt::getCurrentClockFreqRead(proc);

    PowerMgmt::getDefaultPowercfg();
    PowerMgmt::createCustomPowerPlan();
    PowerMgmt::removeFreqCap();
    
    // Take another reading
    PowerMgmt::getCurrentClockFreqStart(proc);
    ui.patch0->fillBar();
    task1Freq = PowerMgmt::getCurrentClockFreqRead(proc);

    ui.patch0->done_label->setText("Done!");
    ui.patch0->continue_btn->setEnabled(true);
}

void MainWindow::showPatch1() {
    ui.stackedWidget->setCurrentWidget(ui.patch1);
    if (throttled_task == 2)
        PowerMgmt::setFreqCap(100 - slowdown);

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
        PowerMgmt::setFreqCap(100 - slowdown);
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
    ui.patch3->fillBar();
    postTasksFreq = PowerMgmt::getCurrentClockFreqRead(proc);

    ui.patch3->done_label->setText("Done!");
    ui.patch3->continue_btn->setEnabled(true);
}

void MainWindow::showRank() {
    ui.stackedWidget->setCurrentWidget(ui.rank);
}

void MainWindow::showCompare() {
    ui.compare->setLabels(ui.rank->listWidget);
    ui.stackedWidget->setCurrentWidget(ui.compare);
}

void MainWindow::showPreWTA() {
    ui.preWTA->setLabelText(throttled_task, unthrottled_task, slowdown);
    ui.stackedWidget->setCurrentWidget(ui.preWTA);
}

void MainWindow::showPostTasks() {
    ui.stackedWidget->setCurrentWidget(ui.posttasks);
}

void MainWindow::showWTA() {
    offer = 0;
    ui.wta->header->setText("Would you be willing to accept a permanent " + QString::number(slowdown) + "% slowdown on this computer in exchange for ");
    ui.wta->updateOffer(offer);
    ui.stackedWidget->setCurrentWidget(ui.wta);
}

std::string MainWindow::createResultsString() {
    string s = "";

    s += "name,"    +  ui.form->name_str    +    "\n";
    s += "uni,"     +  ui.form->uni_str     +    "\n";
    s += "address," +  ui.form->address_str +    "\n";
    s += "city,"    +  ui.form->city_str    +    "\n";
    s += "state,"   +  ui.form->state_str   +    "\n";
    s += "zip,"     +  ui.form->zip_str     +    "\n";
    s += "wta," + to_string(offer) + "\n";
    s += "throttled_task,"   + to_string(throttled_task)   + "\n";
    s += "unthrottled_task," + to_string(unthrottled_task) + "\n";
    s += "slowdown," + to_string(slowdown) + "\n";
    s += "fastest," + ui.rank->listWidget->item(0)->text().toStdString() + "\n";
    s += "middle,"  + ui.rank->listWidget->item(1)->text().toStdString() + "\n";
    s += "slowest," + ui.rank->listWidget->item(2)->text().toStdString() + "\n";
    s += "fastest_vs_middle,"  + to_string(ui.compare->arr1->getClicked()) + "\n";
    s += "middle_vs_slowest,"  + to_string(ui.compare->arr2->getClicked()) + "\n";
    s += "fastest_vs_slowest," + to_string(ui.compare->arr3->getClicked()) + "\n";
    s += "pre_task_freq," + to_string(preTasksFreq) + "\n";
    s += "task1_freq," + to_string(task1Freq) + "\n";
    s += "task2_freq," + to_string(task2Freq) + "\n";
    s += "task3_freq," + to_string(task3Freq) + "\n";
    s += "post_task_freq," + to_string(postTasksFreq) + "\n";

    return s;
}

void MainWindow::showForm() {
    qDebug() << offer;
    ui.stackedWidget->setCurrentWidget(ui.form);
}

void MainWindow::showDebrief() {
    enableExitButton();
    ui.debrief->setLabelText(throttled_task, slowdown);
    ui.stackedWidget->setCurrentWidget(ui.debrief);
}

void MainWindow::updateOffer_yes() {
    if (offer <= 4) {
        if (offer == 4) {
            offer = 3;
        }
        showForm();
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
            showForm();
        }
        else {
            ui.wta->updateOffer(offer);
        }
    }
}

void MainWindow::updateOffer_no() {
    if (!first_accept) {
        if (offer == 0) {
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
            showForm();
        }
        else {
            ui.wta->updateOffer(offer);
        }
    }
}

void MainWindow::showWithdraw() {
    ui.stackedWidget->setCurrentWidget(ui.withdraw);
}

void MainWindow::showFinal() {
#if QT_NO_DEBUG
    DropBox::upload(createResultsString(), ui.form->uni_str);
#endif
    ui.final->updateText();
    ui.stackedWidget->setCurrentWidget(ui.final);
}

void MainWindow::showWithdrawNext() {
    if (ui.withdraw->withdraw_btn->isChecked()) {
        ui.withdraw->Withdraw();
    }
    else {
        showDebrief();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);    


    pickThrottledTask();



    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.start->consent_btn, &QPushButton::clicked, this, &MainWindow::showStartNext);
    connect(ui.mod->consent_btn, &QPushButton::clicked, this, &MainWindow::showPatch0);
    connect(ui.mod->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.patch0->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui.task1->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch1);
    connect(ui.patch1->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui.task2->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch2);
    connect(ui.patch2->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask3);
    connect(ui.task3->continue_btn, &QPushButton::clicked, this, &MainWindow::showPatch3);
    connect(ui.patch3->continue_btn, &QPushButton::clicked, this, &MainWindow::showPostTasks);
    connect(ui.posttasks->continue_btn, &QPushButton::clicked, this, &MainWindow::showRank);
    connect(ui.rank->continue_btn, &QPushButton::clicked, this, &MainWindow::showCompare);
    connect(ui.compare->continue_btn, &QPushButton::clicked, this, &MainWindow::showPreWTA);
    connect(ui.preWTA->continue_btn, &QPushButton::clicked, this, &MainWindow::showWTA);
    connect(ui.wta->yes_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_yes);
    connect(ui.wta->no_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_no);
    connect(ui.form->continue_btn, &QPushButton::clicked, this, &MainWindow::showDebrief);
    connect(ui.debrief->yes_btn, &QPushButton::clicked, this, &MainWindow::showWithdraw);
    connect(ui.debrief->no_btn, &QPushButton::clicked, this, &MainWindow::showFinal);
    connect(ui.withdraw->continue_btn, &QPushButton::clicked, this, &MainWindow::showWithdrawNext);
    

#ifndef QT_NO_DEBUG
    //connect(ui.start->consent_btn, &QPushButton::clicked, this, &MainWindow::showPreWTA);
#endif

}
