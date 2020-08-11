#include "MainWindow.h"
#include "ui_MainWindow.h"

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
