#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Protocol2App.h"

//enum restoreReason {TIMEOUT, DECLINE};

class Protocol2App : public QMainWindow
{
    Q_OBJECT

public:
    Protocol2App(QWidget *parent = Q_NULLPTR);
    
    //static void restoreSystem(restoreReason r);
    static int getDays();
   

private:
    Ui::MainWindow ui;

    int days;


private:
    void showStartNext();
    void showWTA();
    void WTAnext();
    void showFormPage();
    void showGoodbye();
    void acceptOffer();
    void declineOffer();
    void showSurvey();
    void showCheat();
    void showNoMore();
    void showSurveyNext();

    void closeEvent(QCloseEvent* event);
    void resetProgram();
    void timeout();

    void enableExitButton();
    void disableExitButton();
};
