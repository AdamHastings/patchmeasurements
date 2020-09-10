#include "QtCurlTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCurlTest w;
    w.show();
    return a.exec();
}
