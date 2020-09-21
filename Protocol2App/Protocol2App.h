#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Protocol2App.h"

class Protocol2App : public QMainWindow
{
    Q_OBJECT

public:
    Protocol2App(QWidget *parent = Q_NULLPTR);

private:
    Ui::Protocol2AppClass ui;
};
