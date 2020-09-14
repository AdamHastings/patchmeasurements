#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "Globals.h"

int main(int argc, char *argv[])
{
    //globals_init(QApplication::desktop()->screenGeometry());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
