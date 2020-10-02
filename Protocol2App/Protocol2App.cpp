#include "Protocol2App.h"
#include "RegistryUtils.h"
#include "PowerMgmt.h"
#include "SysUtils.h"
#include <QCloseEvent>
#include <time.h>
#include  <QDebug>

void Protocol2App::showWTA() {
    SysUtils::initExperiment();
    ui.stackedWidget->setCurrentWidget(ui.wta);
}


void Protocol2App::WTAnext() {
    if (ui.wta->accept->isChecked()) {
        ui.stackedWidget->setCurrentWidget(ui.dc_accept);
    }
    else if (ui.wta->decline->isChecked()) {
        ui.stackedWidget->setCurrentWidget(ui.dc_decline);
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
    RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("accept");
    ui.stackedWidget->setCurrentWidget(ui.onemore);
}

void Protocol2App::declineOffer() {
    RegistryUtils::setRegKey("firstoffer", 0);
    SysUtils::takeSnapshot("decline");
    SysUtils::restoreSystem();
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

Protocol2App::Protocol2App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showStartNext);
    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &Protocol2App::showGoodbye);

    connect(ui.mod->consent_btn, &QPushButton::clicked, this, &Protocol2App::showFormPage);
    connect(ui.mod->not_consent_btn, &QPushButton::clicked, this, &Protocol2App::showGoodbye);

    connect(ui.form->continue_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.wta->continue_btn, &QPushButton::clicked, this, &Protocol2App::WTAnext);

    connect(ui.dc_accept->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);
    connect(ui.dc_decline->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.dc_accept->confirm_btn, &QPushButton::clicked, this, &Protocol2App::acceptOffer);
    connect(ui.dc_decline->confirm_btn, &QPushButton::clicked, this, &Protocol2App::declineOffer);
}

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
                //restoreSystem(TIMEOUT);
                SysUtils::takeSnapshot("timeout");
                SysUtils::restoreSystem();
                ui.stackedWidget->setCurrentWidget(ui.nomore);
            }
            else {
                ui.stackedWidget->setCurrentWidget(ui.wta);
            }
            this->show();

        }

    }
}
