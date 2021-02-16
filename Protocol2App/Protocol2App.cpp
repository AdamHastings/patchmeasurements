#include "Protocol2App.h"
#include "RegistryUtils.h"
#include "PowerMgmt.h"
#include "SysUtils.h"
#include <QCloseEvent>
#include <time.h>
#include <QDebug>

int Protocol2App::days;
QString Protocol2App::uni;


void Protocol2App::enableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (closeFlag);
    setWindowFlags(flags);
    this->show();
}

void Protocol2App::disableExitButton() {
//#ifdef QT_NO_DEBUG
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
    this->show();
//#endif
}

void Protocol2App::showStartNext() {
    if (!PowerMgmt::runningAsAdmin()) {
        ui.stackedWidget->setCurrentWidget(ui.noadmin);
    }
#if QT_NO_DEBUG
    else if (SysUtils::getpwd() != "C:\\Program Files\\" + RegistryUtils::AppName + "\\" + RegistryUtils::AppName + ".exe") {
        ui.stackedWidget->setCurrentWidget(ui.wronginstall);
    }
#endif
    else if (RegistryUtils::isCsEnabled()) {
        ui.stackedWidget->setCurrentWidget(ui.regedit);
    }
    else {
        //getDefaultPowercfg();
        disableExitButton();
        ui.stackedWidget->setCurrentWidget(ui.form);
    }
}

void Protocol2App::showFormPage() {
    disableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.form);
}


void Protocol2App::showWTA() {
    qDebug() << "days: " << days;
    if (days == TOTAL_DAYS) {
        SysUtils::initExperiment();
        SysUtils::takeSnapshot("start");
    }
    ui.wta->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.wta);
}

void Protocol2App::WTAnext() {
    if (ui.wta->accept->isChecked()) {
        //ui.stackedWidget->setCurrentWidget(ui.dc_accept);
        acceptOffer();
    }
    else if (ui.wta->decline->isChecked()) {
        //ui.stackedWidget->setCurrentWidget(ui.dc_decline);
        declineOffer();
    }
    else {
        qDebug() << "ERROR: Nothing selected in WTA page";
    }
}

void Protocol2App::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void Protocol2App::acceptOffer() {
    //RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("accept");
    if (days == TOTAL_DAYS) { // This is the first acceptance
        RegistryUtils::setAutorun();

        PowerMgmt::getDefaultPowercfg();
        PowerMgmt::createCustomPowerPlan();
        PowerMgmt::setFreqCap(100 - SLOWDOWN);
    }
    ui.onemore->resetPage(days);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.onemore);
}

void Protocol2App::showNoMore() {
    SysUtils::takeSnapshot("final");
    ui.nomore->resetPage(days);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

void Protocol2App::declineOffer() {
    qDebug() << "declining offer";
    //RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("decline");
    if (days != TOTAL_DAYS) { // The system was actually slowed down
        PowerMgmt::restoreDefaults();
    }
    SysUtils::restoreSystem();
    showSurvey();
    //showNoMore();
}

void Protocol2App::showSurvey() {
    ui.survey->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.survey);
}

void Protocol2App::showCheat() {
    ui.stackedWidget->setCurrentWidget(ui.cheat);
}

void Protocol2App::showSurveyNext() {
    SurveyPage::not_enough_money->isChecked();
    if (days == TOTAL_DAYS) {
        // This is the first time
        showNoMore();
    }
    else {
        showCheat();
    }
}

Protocol2App::Protocol2App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // If this isn't the first time, load values from the registry
    if (RegistryUtils::getRegKey("days").isValid()) {
        days = RegistryUtils::getRegKey("days").toInt();
        // TODO is this what we want?
        resetProgram();
    }
    else {
        days = TOTAL_DAYS;
    }
     


    connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showStartNext);
    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &Protocol2App::showGoodbye);

    connect(ui.mod->consent_btn, &QPushButton::clicked, this, &Protocol2App::showFormPage);
    connect(ui.mod->not_consent_btn, &QPushButton::clicked, this, &Protocol2App::showGoodbye);

    connect(ui.form->continue_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.wta->continue_btn, &QPushButton::clicked, this, &Protocol2App::WTAnext);

    /*connect(ui.dc_accept->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);
    connect(ui.dc_decline->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.dc_accept->confirm_btn, &QPushButton::clicked, this, &Protocol2App::acceptOffer);
    connect(ui.dc_decline->confirm_btn, &QPushButton::clicked, this, &Protocol2App::showSurvey);*/

    connect(ui.survey->continue_btn, &QPushButton::clicked, this, &Protocol2App::showSurveyNext);
    connect(ui.cheat->continue_btn, &QPushButton::clicked, this, &Protocol2App::showNoMore);

#ifdef QT_DEBUG
    // connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showCheat);
#endif
}

//int Protocol2App::getDays() {
//    return days;
//}

//void Protocol2App::restoreSystem(restoreReason r) {
//    // TODO
//    //restorePowerDefaults();
//    RegistryUtils::nuke();
//}


void Protocol2App::closeEvent(QCloseEvent* event) {

    // If the user has elected to end the experiment, this should be empty..
    if (RegistryUtils::getRegKey("UNI").isValid()) {
        if (days > 0) {

            event->ignore();
            this->hide();

            // wait
            int time_to_sleep = 60 * 60 * 24 * 1000; // one day

#ifdef QT_DEBUG
            time_to_sleep = 1 * 1000;
            days /= 2;
#endif
            _sleep(time_to_sleep);

            days--;

            // update Registry
            RegistryUtils::setRegKey("Days", days);

            if (days == 0) {
                timeout();
            }
            else {
                resetProgram();
            }
            this->show();

        }
    }
    else {
        // one more for good measure...
        RegistryUtils::nuke();
    }
}

void Protocol2App::resetProgram() {
    disableExitButton();
    showWTA();
}

void Protocol2App::timeout() {
    //restoreSystem(TIMEOUT);
    //SysUtils::takeSnapshot("timeout");
    if (days != TOTAL_DAYS) { // The system was actually slowed down
        PowerMgmt::restoreDefaults();
    }
    SysUtils::restoreSystem();
    showNoMore();
}

int Protocol2App::getDays() {
    return days;
}

QString Protocol2App::getUNI() {
    return uni;
}

void Protocol2App::setUNI(QString input) {
    uni = input;
}


