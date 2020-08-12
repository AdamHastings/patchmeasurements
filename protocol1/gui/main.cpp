#include "MainWindow.h"
#include <QApplication>
#include <QRect>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    // QDesktopWidget *desk = QApplication::desktop();
    // const QRect rect = desk->screenGeometry();
    
    return app.exec();
}