#include "MainWindow.h"
#include "Ui_MainWindow.h"

void MainWindow::setFreq() {
    return;
}

void MainWindow::showGoodbye() {
    return;
}

void MainWindow::close() {
    return;
}

void MainWindow::showTask1() {
    return;
}

void MainWindow::showPatch() {
    return;
}

void MainWindow::showTask2() {
    return;
}

void MainWindow::showQ1() {
    return;
}

void MainWindow::q1Response() {
    return;
}

void MainWindow::showQ1Next() {
    return;
}

void MainWindow::showQ3() {
    return;
}

void MainWindow::q3Response() {
    return;
}

void MainWindow::showQ4() {
    return;
}

void MainWindow::showWTA() {
    return;
}

void MainWindow::updateOffer_yes() {
    return;
}

void MainWindow::updateOffer_no() {
    return;
}

void MainWindow::conclude() {
    return;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            // ui->progressBar_2, SLOT(setValue(int)));

//    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
//            ui->progressBar_2, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}