#include "PostRequest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PostRequest w;
    w.show();
    return a.exec();
}
