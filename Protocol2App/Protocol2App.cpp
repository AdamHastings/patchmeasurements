#include "Protocol2App.h"
#include "RegEdit.h"

#include  <QDebug>

void Protocol2App::showWTA() {
    RegEdit::setRegKey(RegLocation, "testKey", 22);
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

void Protocol2App::showFormPage() {
    ui.stackedWidget->setCurrentWidget(ui.form);
}

void Protocol2App::acceptOffer() {
    qDebug() << "accepting WTA offer";
    ui.stackedWidget->setCurrentWidget(ui.onemore);
}

void Protocol2App::declineOffer() {
    qDebug() << "declining WTA offer";
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

Protocol2App::Protocol2App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showFormPage);

    connect(ui.form->continue_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.wta->continue_btn, &QPushButton::clicked, this, &Protocol2App::WTAnext);

    connect(ui.dc_accept->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);
    connect(ui.dc_decline->mistake_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);

    connect(ui.dc_accept->confirm_btn, &QPushButton::clicked, this, &Protocol2App::acceptOffer);
    connect(ui.dc_decline->confirm_btn, &QPushButton::clicked, this, &Protocol2App::declineOffer);
}
