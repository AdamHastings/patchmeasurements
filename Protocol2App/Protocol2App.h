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
    static QString getUNI();
    // static QString getName();
    static int getHours();
    static int getAcceptances();
    static void setAcceptances(int input);

    static void setUNI(QString input);
    // static void setName(QString input);
    static void setHours(int input);

    static QString snapshot_reason;
    static double start_freq;
    static double accept_freq;

   

private:
    Ui::MainWindow ui;

    static int days;
    static QString uni;
    //static QString name;
    static int hours;
    static int acceptances;


private:
    void showStartNext();
    void showModNext();
    void showHMonitor();
    void showHMonitorNext();
    void showHMinNext();
    void showPrimaryNext();
    void showWTA();
    void WTAnext();
    void showFormPage();
    void showGoodbye();
    void acceptOffer();
    void declineOffer();
    void showSurvey();
    void showCheat();
    void showUsage();
    void showHours();
    void showDays();
    void showNoMore();
    void showSurveyNext();
    void showImprove();
    void showDecrease();
    void showTimeoutSplash();
    void showInternetNext();
    void showCompNotEligible();
    void tryUpload();
    void tryUploadNext();
    void tryFinalUpload();
    void tryFinalUploadNext();
    void showFinalRetry();
    void showHoursNext();
    void showMoreDays();
    void showUploadFail();
    void showPreUpload();
    void showFailNext();
    void showPurchase();
    void showPurchaseNext();
    void showSellpoints();
    void testEligibility();

    void closeEvent(QCloseEvent* event);
    void resetProgram();
    void timeout();

    void enableExitButton();
    void disableExitButton();
};
