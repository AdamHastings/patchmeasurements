#pragma once

#include <QtWidgets/QMainWindow>
#include <QProgressBar>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindow ui;

    void showGoodbye();
    void showTask1();
    void showTask2();
    void showTask3();
    void fillBar(QProgressBar *qb);
    void showPatch1();
    void showPatch2();
    void showPatch3();

};
