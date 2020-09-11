#pragma once
#include <string>
#include <QObject>


class DropBox {
    Q_OBJECT

public:
    DropBox();
    ~DropBox();

    static void upload(std::string s);
};
