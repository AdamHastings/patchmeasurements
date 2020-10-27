#include "Protocol2App.h"
#include "RegistryUtils.h"
#include "PowerMgmt.h"
#include "SysUtils.h"
#include <QCloseEvent>
#include <time.h>
#include  <QDebug>

void Protocol2App::showWTA() {
    qDebug() << "days: " << days;
    if (days == TOTAL_DAYS) {
        SysUtils::initExperiment();
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

void Protocol2App::showStartNext() {
    if (!PowerMgmt::runningAsAdmin()) {
        ui.stackedWidget->setCurrentWidget(ui.noadmin);
    }
    else if (RegistryUtils::isCsEnabled()) {
        ui.stackedWidget->setCurrentWidget(ui.regedit);
    }
    else {
        //getDefaultPowercfg();
        ui.stackedWidget->setCurrentWidget(ui.form);
    }
}

void Protocol2App::showFormPage() {
    ui.stackedWidget->setCurrentWidget(ui.form);
}

void Protocol2App::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void Protocol2App::acceptOffer() {
    //RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("accept");
    ui.onemore->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.onemore);
}

void Protocol2App::showNoMore() {
    ui.nomore->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

void Protocol2App::declineOffer() {
    //RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("decline");
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
    }
    else {
        days = TOTAL_DAYS;
    }
    ////if (RegistryUtils::getRegKey("FirstOffer").toInt() == 0) {
    //    stackedWidget->setCurrentWidget(wta);
    //    DropBox::setDirectory(RegistryUtils::getRegKey("UNI").toString());
    //}
    //else {

    // TODO maybe it makes more sense to do this in reverse? E.g. first offer is the default, and only change the wording if it's not the first time...
     // TODO really need to re-evaluate this design issue here...
     //wta->firstOffer();
     //dc_accept->firstOffer();
     //dc_decline->firstOffer();
     //onemore->firstOffer();
     //nomore->firstOffer();
     //survey->firstOffer();
     //stackedWidget->setCurrentWidget(start);
     


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
            qDebug() << "days is now set to " << days;

            // update Registry
            RegistryUtils::setRegKey("Days", days);

            if (days == 0) {
                //restoreSystem(TIMEOUT);
                SysUtils::takeSnapshot("timeout");
                SysUtils::restoreSystem();
                ui.stackedWidget->setCurrentWidget(ui.nomore);
            }
            else {
                showWTA();
            }
            this->show();

        }

    }
}

//void Protocol2App::resetProgram() {
//    ui.wta->resetPage(days);
//    ui.stackedWidget->setCurrentWidget(ui.wta);
//}
