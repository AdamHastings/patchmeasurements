#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Protocol2App.h"

class Protocol2App : public QMainWindow
{
    Q_OBJECT

public:
    Protocol2App(QWidget *parent = Q_NULLPTR);
    
   

private:
    Ui::MainWindow ui;


private:
    void showStartNext();
    void showWTA();
    void WTAnext();
    void showFormPage();
    void showGoodbye();
    void acceptOffer();
    void declineOffer();

    void closeEvent(QCloseEvent* event);
};
