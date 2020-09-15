#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "DropBox.h"

void MainWindow::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void MainWindow::showTask1() {
    ui.stackedWidget->setCurrentWidget(ui.task1);
}

void MainWindow::showTask2() {
    ui.stackedWidget->setCurrentWidget(ui.task2);
}

void MainWindow::showTask3() {
    ui.stackedWidget->setCurrentWidget(ui.task3);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //DropBox::upload("Protocol1App");

    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.start->consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);
    connect(ui.task1->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask2);
    connect(ui.task2->continue_btn, &QPushButton::clicked, this, &MainWindow::showTask3);

}
