#include "Protocol2App.h"

#include "QPushButton"


void Protocol2App::showWTA() {
    ui.stackedWidget->setCurrentWidget(ui.wta);
}

Protocol2App::Protocol2App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showWTA);
}
