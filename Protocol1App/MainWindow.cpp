#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "DropBox.h"

void MainWindow::showGoodbye() {
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    DropBox::upload("Protocol1App");

    connect(ui.not_consent_btn, &QPushButton::clicked, this, &MainWindow::showGoodbye);

}
