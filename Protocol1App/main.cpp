#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "Globals.h"

int main(int argc, char *argv[])
{
    //globals_init(QApplication::desktop()->screenGeometry());
    QApplication a(argc, argv);
    MainWindow w;

    QFont mainfont = QFont();
    mainfont.setPointSize(8);

    w.setFont(mainfont);
    w.setWindowTitle("Tasks Experiment");
    w.show();
    return a.exec();
}
