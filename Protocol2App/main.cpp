#include "Protocol2App.h"
#include <QtWidgets/QApplication>
#include <filesystem>


int main(int argc, char *argv[])
{

    std::filesystem::current_path("C:/Program Files/HastingsExperiment"); //setting path

    QApplication a(argc, argv);
    Protocol2App w;
    w.show();
    return a.exec();
}
