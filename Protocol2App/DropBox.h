#pragma once
#include <string>
#include <QObject>


class DropBox {

public:
    DropBox();
    ~DropBox();

    //static void upload(std::string contents, std::string filename);
    static void upload(QString contents, QString filename);
    static bool uploadSuccessful(QString uni, QString filename);

};


