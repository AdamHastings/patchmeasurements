#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "DropBox.h"

void MainWindow::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

void MainWindow::showTask1() {
    ui.stackedWidget->setCurrentWidget(ui.task1);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    DropBox::upload("Protocol1App");

    /*connect(ui.not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);*/

    connect(ui.start->not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);
    connect(ui.start->consent_btn, &QPushButton::clicked, this, &MainWindow::showTask1);

    connect(ui.task1->subtask_a, &QPushButton::clicked, ui.task1->subtask_b, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_b, &QPushButton::clicked, ui.task1->subtask_c, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_c, &QPushButton::clicked, ui.task1->subtask_d, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_d, &QPushButton::clicked, ui.task1->subtask_e, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_e, &QPushButton::clicked, ui.task1->subtask_f, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_f, &QPushButton::clicked, ui.task1->subtask_g, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_g, &QPushButton::clicked, ui.task1->subtask_h, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_h, &QPushButton::clicked, ui.task1->subtask_i, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_i, &QPushButton::clicked, ui.task1->subtask_j, &QCheckBox::setEnabled);
    connect(ui.task1->subtask_j, &QPushButton::clicked, ui.task1->continue_btn, &QPushButton::setEnabled);
    connect(ui.task1->subtask_a, &QPushButton::clicked, ui.task1->subtask_a, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_b, &QPushButton::clicked, ui.task1->subtask_b, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_c, &QPushButton::clicked, ui.task1->subtask_c, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_d, &QPushButton::clicked, ui.task1->subtask_d, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_e, &QPushButton::clicked, ui.task1->subtask_e, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_f, &QPushButton::clicked, ui.task1->subtask_f, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_g, &QPushButton::clicked, ui.task1->subtask_g, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_h, &QPushButton::clicked, ui.task1->subtask_h, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_i, &QPushButton::clicked, ui.task1->subtask_i, &QCheckBox::setDisabled);
    connect(ui.task1->subtask_j, &QPushButton::clicked, ui.task1->subtask_j, &QCheckBox::setDisabled);
    
    connect(ui.task2->subtask_a, &QPushButton::clicked, ui.task2->subtask_b, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_b, &QPushButton::clicked, ui.task2->subtask_c, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_c, &QPushButton::clicked, ui.task2->subtask_d, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_d, &QPushButton::clicked, ui.task2->subtask_e, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_e, &QPushButton::clicked, ui.task2->subtask_f, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_f, &QPushButton::clicked, ui.task2->subtask_g, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_g, &QPushButton::clicked, ui.task2->subtask_h, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_h, &QPushButton::clicked, ui.task2->subtask_i, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_i, &QPushButton::clicked, ui.task2->subtask_j, &QCheckBox::setEnabled);
    connect(ui.task2->subtask_j, &QPushButton::clicked, ui.task2->continue_btn, &QPushButton::setEnabled);
    connect(ui.task2->subtask_a, &QPushButton::clicked, ui.task2->subtask_a, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_b, &QPushButton::clicked, ui.task2->subtask_b, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_c, &QPushButton::clicked, ui.task2->subtask_c, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_d, &QPushButton::clicked, ui.task2->subtask_d, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_e, &QPushButton::clicked, ui.task2->subtask_e, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_f, &QPushButton::clicked, ui.task2->subtask_f, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_g, &QPushButton::clicked, ui.task2->subtask_g, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_h, &QPushButton::clicked, ui.task2->subtask_h, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_i, &QPushButton::clicked, ui.task2->subtask_i, &QCheckBox::setDisabled);
    connect(ui.task2->subtask_j, &QPushButton::clicked, ui.task2->subtask_j, &QCheckBox::setDisabled);
    
    connect(ui.task3->subtask_a, &QPushButton::clicked, ui.task3->subtask_b, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_b, &QPushButton::clicked, ui.task3->subtask_c, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_c, &QPushButton::clicked, ui.task3->subtask_d, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_d, &QPushButton::clicked, ui.task3->subtask_e, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_e, &QPushButton::clicked, ui.task3->subtask_f, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_f, &QPushButton::clicked, ui.task3->subtask_g, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_g, &QPushButton::clicked, ui.task3->subtask_h, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_h, &QPushButton::clicked, ui.task3->subtask_i, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_i, &QPushButton::clicked, ui.task3->subtask_j, &QCheckBox::setEnabled);
    connect(ui.task3->subtask_j, &QPushButton::clicked, ui.task3->continue_btn, &QPushButton::setEnabled);
    connect(ui.task3->subtask_a, &QPushButton::clicked, ui.task3->subtask_a, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_b, &QPushButton::clicked, ui.task3->subtask_b, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_c, &QPushButton::clicked, ui.task3->subtask_c, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_d, &QPushButton::clicked, ui.task3->subtask_d, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_e, &QPushButton::clicked, ui.task3->subtask_e, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_f, &QPushButton::clicked, ui.task3->subtask_f, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_g, &QPushButton::clicked, ui.task3->subtask_g, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_h, &QPushButton::clicked, ui.task3->subtask_h, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_i, &QPushButton::clicked, ui.task3->subtask_i, &QCheckBox::setDisabled);
    connect(ui.task3->subtask_j, &QPushButton::clicked, ui.task3->subtask_j, &QCheckBox::setDisabled);

}
