#include "MainWindow.h"
#include "ui_MainWindow.h"

void MainWindow::setBluePage(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->start_page);
    return;
}

void MainWindow::setRedPage(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->Red_page);
    return;
}

void MainWindow::setYellowPage(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->Yellow_page);
    return;
}

void MainWindow::setGoodbyePage(bool b) {
    ui->stackedWidget->setCurrentWidget(ui->goodbye_page);
    return;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            // ui->progressBar_2, SLOT(setValue(int)));

    connect(ui->blu_btn, SIGNAL(clicked(bool)), this, SLOT(setBluePage(bool)));
    connect(ui->red_btn, SIGNAL(clicked(bool)), this, SLOT(setRedPage(bool)));
    connect(ui->ylw_btn, SIGNAL(clicked(bool)), this, SLOT(setYellowPage(bool)));
    connect(ui->not_consent_btn, SIGNAL(clicked(bool)), this, SLOT(setGoodbyePage(bool)));

//    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
//            ui->progressBar_2, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
