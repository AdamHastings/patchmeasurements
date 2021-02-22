#include "Protocol2App.h"
#include "RegistryUtils.h"
#include "PowerMgmt.h"
#include "SysUtils.h"
#include <QCloseEvent>
#include <time.h>
#include <QDebug>

int Protocol2App::days;
QString Protocol2App::uni;
QString Protocol2App::name;


void Protocol2App::enableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (closeFlag);
    setWindowFlags(flags);
    this->show();
}

void Protocol2App::disableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
    this->show();
}

void Protocol2App::showStartNext() {
    if (!PowerMgmt::runningAsAdmin()) {
        ui.stackedWidget->setCurrentWidget(ui.noadmin);
    }
#ifndef QT_DEBUG
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
    SysUtils::takeSnapshot("accept");
    // get current time
    int time = SysUtils::getUnixTime();
    if (days == TOTAL_DAYS) { // This is the first acceptance
        RegistryUtils::setAutorun();

        PowerMgmt::getDefaultPowercfg();
        PowerMgmt::createCustomPowerPlan();
        PowerMgmt::setFreqCap(100 - SLOWDOWN);
        // add timestamp of first accept
        RegistryUtils::setRegKey("first_accept", time);
    }
    // add timestamp of last accept (which should be the same)
    RegistryUtils::setRegKey("last_accept", time);
    ui.onemore->resetPage(days);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.onemore);
}

void Protocol2App::showNoMore() {
    if (days == 0)
        SysUtils::takeSnapshot("timeout");
    else
        SysUtils::takeSnapshot("decline");
    ui.nomore->resetPage(days);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

void Protocol2App::declineOffer() {
    SysUtils::restoreSystem();
    showSurvey();
}

void Protocol2App::showSurvey() {
    ui.survey->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.survey);
}

void Protocol2App::showCheat() {
    ui.stackedWidget->setCurrentWidget(ui.cheat);
}

void Protocol2App::showSurveyNext() {
    if (days == TOTAL_DAYS) {
        // This is the first time
        showHours();
    }
    else {
        showCheat();
    }
}

void Protocol2App::showHours() {
    ui.stackedWidget->setCurrentWidget(ui.hours);
}

void Protocol2App::showImprove() {
    ui.stackedWidget->setCurrentWidget(ui.improve);
}

void Protocol2App::showDecrease() {
    ui.stackedWidget->setCurrentWidget(ui.decrease);
}

void Protocol2App::showUsage() {
    ui.stackedWidget->setCurrentWidget(ui.usage);
}

void Protocol2App::showTimeoutSplash() {
    ui.stackedWidget->setCurrentWidget(ui.timeout);
}

Protocol2App::Protocol2App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // If this isn't the first time, load values from the registry
    if (RegistryUtils::getRegKey("days").isValid()) {
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
    connect(ui.survey->continue_btn, &QPushButton::clicked, this, &Protocol2App::showSurveyNext);
    connect(ui.cheat->continue_btn, &QPushButton::clicked, this, &Protocol2App::showHours);
    connect(ui.hours->continue_btn, &QPushButton::clicked, this, &Protocol2App::showImprove);
    connect(ui.improve->continue_btn, &QPushButton::clicked, this, &Protocol2App::showDecrease);
    connect(ui.decrease->continue_btn, &QPushButton::clicked, this, &Protocol2App::showUsage);
    connect(ui.usage->continue_btn, &QPushButton::clicked, this, &Protocol2App::showNoMore);
    connect(ui.timeout->continue_btn, &QPushButton::clicked, this, &Protocol2App::showCheat);

#ifdef QT_DEBUG
    // connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showCheat);
#endif
}

void Protocol2App::closeEvent(QCloseEvent* event) {

    // If the user has elected to end the experiment, this should be empty..
    if (RegistryUtils::getRegKey("UNI").isValid()) {
        if (days > 0) {

            event->ignore();
            this->hide();

            // wait
            //int time_to_sleep = WAIT_PERIOD * 1000; // seconds to milliseconds

            // update Registry
            //days = days - 1;
            //RegistryUtils::setRegKey("Days", days);

            //_sleep(time_to_sleep);


            //if (days == 0) {
                //timeout();
            //}
            //else {
            resetProgram();
            //}
            //this->show();

        }
    }
    else {
        // one more for good measure...
        RegistryUtils::nuke();
    }
}

void Protocol2App::resetProgram() {
    days = RegistryUtils::getRegKey("days").toInt();
    uni = RegistryUtils::getRegKey("UNI").toString();
    name = RegistryUtils::getRegKey("name").toString();

    //  figure out how long to sleep, and how many days have elapsed
    int first_accept = RegistryUtils::getRegKey("first_accept").toInt();
    int last_accept = RegistryUtils::getRegKey("last_accept").toInt();
    int time_now = SysUtils::getUnixTime();
    
    if ((time_now - first_accept) >= (WAIT_PERIOD * TOTAL_DAYS)) { //timeout
        days = 0;
        RegistryUtils::setRegKey("days", days);
        SysUtils::takeSnapshot("audit");
        timeout();
        return;
    }
    if ((time_now - last_accept) <= (WAIT_PERIOD)) { // It hasn't been a full WAIT_PERIOD since last accept
        int time_to_sleep = (WAIT_PERIOD)-(time_now - last_accept);
        _sleep(time_to_sleep * 1000);
    }


    // days = (time_now - first_accept) / (WAIT_PERIOD * TOTAL_DAYS);
    time_now = SysUtils::getUnixTime();
    days = TOTAL_DAYS - ((time_now - first_accept) / WAIT_PERIOD);
    RegistryUtils::setRegKey("days", days);
    SysUtils::takeSnapshot("audit");

    if (days <= 0) {
        timeout();
        return;
    }
    else {
        disableExitButton();
        showWTA();
        return;
    }

    //}
    //else { // It's been at least a full WAIT_PERIOD since last accept. Need to adjust the registry...
    //   
    //    days = TOTAL_DAYS - ((time_now - first_accept) / WAIT_PERIOD);
    //    RegistryUtils::setRegKey("days", days);
    //    SysUtils::takeSnapshot("audit");

    //    disableExitButton();
    //    showWTA();
    //}
}

void Protocol2App::timeout() {
    SysUtils::restoreSystem();
    showTimeoutSplash();
    this->show();
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

void Protocol2App::setName(QString input) {
    name = input;
}

QString Protocol2App::getName() {
    return name;
}


