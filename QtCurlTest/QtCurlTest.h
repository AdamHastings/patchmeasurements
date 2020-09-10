#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtCurlTest.h"

class QtCurlTest : public QMainWindow
{
    Q_OBJECT

public:
    QtCurlTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtCurlTestClass ui;
};
