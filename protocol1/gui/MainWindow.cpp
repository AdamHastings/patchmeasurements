#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include <thread>
#include <chrono>
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
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i=MAGIC_THRES; i<=100; i++) {
        ui->patch_progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ui->patch_continue_btn->setEnabled(true);
    ui->patch_continue_btn->setDisabled(false);

    ui->patch_done_label->setText(QApplication::translate("MainWindow", "Done!", Q_NULLPTR));
}

void MainWindow::showTask2(bool b) {
    return;
}

void MainWindow::showQ1(bool b) {
    return;
}

void MainWindow::q1Response(bool b) {
    return;
}

void MainWindow::showQ1Next(bool b) {
    return;
}

void MainWindow::showQ3(bool b) {
    return;
}

void MainWindow::q3Response(bool b) {
    return;
}

void MainWindow::showQ4(bool b) {
    return;
}

void MainWindow::showWTA(bool b) {
    return;
}

void MainWindow::updateOffer_yes(bool b) {
    return;
}

void MainWindow::updateOffer_no(bool b) {
    return;
}

void MainWindow::conclude(bool b) {
    return;
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


    // connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            // ui->progressBar_2, SLOT(setValue(int)));

//    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
//            ui->progressBar_2, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
