#pragma once
#include <string>
#include <QObject>


class DropBox {

public:
    DropBox();
    ~DropBox();

    static void upload(QString contents, std::string filename);
    static bool uploadSuccessful(std::string uni);
};


