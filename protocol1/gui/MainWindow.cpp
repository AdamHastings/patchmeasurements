#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
#include <string>
#include <iostream>

void MainWindow::setFreq(bool b) {
    return;
}

void MainWindow::showGoodbye(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
}

void MainWindow::close(bool b) {
    QApplication::quit();
}

void MainWindow::showTask1(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->task1_page);
}

void MainWindow::showPatch(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->patch_page);

    int MAGIC_THRES = 24;

    for (int i=0; i<MAGIC_THRES; i++) {
        ui->patch_progress_bar->setValue(i);
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i=MAGIC_THRES; i<=100; i++) {
        ui->patch_progress_bar->setValue(i);
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ui->patch_continue_btn->setEnabled(true);
    ui->patch_continue_btn->setDisabled(false);

    ui->patch_done_label->setText(QApplication::translate("MainWindow", "Done!", Q_NULLPTR));
}

void MainWindow::showTask2(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->task2_page);
}

void MainWindow::showQ1(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->q1_page);
}

void MainWindow::q1Response(bool b) {
    ui->q1_continue_btn->setEnabled(true);
}

void MainWindow::showQ1Next(bool b) {
    if (ui->q1_yes_btn->isChecked()) {
        ui->stackedWidget->setCurrentWidget(ui->q2_page);
    } else{
        ui->stackedWidget->setCurrentWidget(ui->q3_page);
    }
}

void MainWindow::showQ3(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->q3_page);
}

void MainWindow::showQ4(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->q4_page);
}

void MainWindow::showWTA() {
    std::string offerstring = "$" + std::to_string(offer) + "?";
    char chrarr[offerstring.length() + 1];
    strcpy(chrarr, offerstring.c_str());
    ui->wta_offer->setText(chrarr);
    ui->stackedWidget->setCurrentWidget(ui->wta_page);
}

void MainWindow::updateOffer_yes(bool b) {
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

void MainWindow::updateOffer_no(bool b) {
    if (!first_accept) {
        offer *= 2;
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->not_consent_btn, SIGNAL(clicked(bool)), this, SLOT(showGoodbye(bool)));
    connect(ui->goodbye_btn, SIGNAL(clicked(bool)), this, SLOT(close(bool)));
    connect(ui->consent_btn, SIGNAL(clicked(bool)), this, SLOT(showTask1(bool)));
    connect(ui->task1_continue_btn, SIGNAL(clicked(bool)), this, SLOT(showPatch(bool)));
    connect(ui->patch_continue_btn, SIGNAL(clicked(bool)), this, SLOT(showTask2(bool)));
    connect(ui->task2_continue_btn, SIGNAL(clicked(bool)), this, SLOT(showQ1(bool)));
    connect(ui->q1_yes_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_no_btn, &QPushButton::clicked, ui->q1_continue_btn, &QPushButton::setEnabled);
    connect(ui->q1_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ1Next);
    connect(ui->q2_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ3);
    connect(ui->q3_yes_btn, &QPushButton::clicked, ui->q3_continue_btn, &QPushButton::setEnabled);
    connect(ui->q3_no_btn, &QPushButton::clicked, ui->q3_continue_btn, &QPushButton::setEnabled);
    connect(ui->q3_continue_btn, &QPushButton::clicked, this, &MainWindow::showQ4);
    connect(ui->q4_continue_btn, &QPushButton::clicked, this, &MainWindow::showWTA);
    connect(ui->wta_yes_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_yes);
    connect(ui->wta_no_btn, &QPushButton::clicked, this, &MainWindow::updateOffer_no);


    // connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            // ui->progressBar_2, SLOT(setValue(int)));

//    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
//            ui->progressBar_2, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
