#include "Protocol2App.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Protocol2App w;
    w.show();
    return a.exec();
}
