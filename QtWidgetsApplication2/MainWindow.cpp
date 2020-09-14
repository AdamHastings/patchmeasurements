#include "MainWindow.h"
#include "DropBox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    DropBox::upload("qt2");
}
