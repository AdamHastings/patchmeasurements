#pragma once
#include <string>
#include <QObject>


class DropBox {

public:
    DropBox();
    ~DropBox();

    static void upload(std::string s);
};


