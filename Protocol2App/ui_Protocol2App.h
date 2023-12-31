#pragma once

#include <QRect>
#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QDesktopWidget>
#include <QDebug>

#include "Globals.h"
#include "StartPage.h"
#include "WTAPage.h"
#include "DoubleCheck.h"
#include "ExitPage.h"
#include "FormPage.h"
#include "RegistryEditPage.h"
#include "SurveyPage.h"
#include "Check4Cheating.h"
#include "SpinBoxPage.h"
#include "UsagePage.h"
#include "ChoicePage.h"
#include "PatchPage.h"
#include <fstream>


#include "RegistryUtils.h"
#include "DropBox.h"

QT_BEGIN_NAMESPACE



class ui_Protocol2App
{

public:
    QWidget* centralwidget;
    QStackedWidget* stackedWidget;

    StartPage* start;
    NoAdminPage* noadmin;
    WrongInstallLocationPage* wronginstall;
    RegistryEditPage* regedit;
    GoodbyePage* goodbye;
    ModPage* mod;
    RestartPage* restart;
    WTAPage* wta;
    DoubleCheckAccept* dc_accept;
    DoubleCheckDecline* dc_decline;
    NoMoreDaysPage* nomore;
    OneMoreDayPage* onemore;
    FormPage* form;
    SurveyPage* survey;
    Check4Cheating* cheat;
    UsagePage* usage;
    HoursPage* hours;
    DaysPage* days;
    ImproveChoicePage* improve;
    DecreaseChoicePage* decrease;
    TimeoutSplashPage* timeout;
    HoursMonitorPage* hmonitor;
    HoursMinimumPage* hmin;
    PrimaryDevicePage* primary;
    InternetPage* internet;
    //PatchPage* tryupload;
    WaitPage* wait;
    RetryPage* retry;
    CompNotEligiblePage* noteligible;
    WaitPage* waitfinal;
    RetryPage* retryfinal;
    MoreDaysPage* more;
    UploadFailPage* fail;
    PurchasePage* purchase;
    SellingPointsPage* selling;
    //TestEligibilityPage* test;
    


    void setupUi(QMainWindow* MainWindow)
    {
        rec = QApplication::desktop()->screenGeometry();
        H = std::min(rec.height() / 2, rec.width() / 2);
        W = std::max(rec.height() / 2, rec.width() / 2);
        M = H / 10;
        LINEWIDTH = W - (2 * M);
        BUTTON_WIDTH = W / 4;
        BUTTON_HEIGHT = H / 16;

        BASELINE = 2;
        /*TOTAL_DAYS = 14;*/
        std::string daysstr;
        std::ifstream days_infile("dcfg.txt");
        std::getline(days_infile, daysstr);
        TOTAL_DAYS = std::stoi(daysstr);
        
        COMPLETION_CODE = "g0j2390lep";

        // read file
        std::string slowdownstr;
        std::ifstream slowdown_infile("scfg.txt");
        std::getline(slowdown_infile, slowdownstr);
        SLOWDOWN = std::stoi(slowdownstr);

        std::string offerstr;
        std::ifstream offer_infile("ocfg.txt");
        std::getline(offer_infile, offerstr);
        OFFER = std::stod(offerstr);

        UPLOAD_WEBPAGE = "www.cs.columbia.edu/~hastings/uploads/p2/upload.html";
#ifdef QT_DEBUG
        //TOTAL_DAYS = 2;
#endif

        std::string timesleepstr;
        std::ifstream sleep_infile("tcfg.txt");
        std::getline(sleep_infile, timesleepstr);
        WAIT_PERIOD = std::stoi(timesleepstr);
        // WAIT_PERIOD = 86400; // one day, in seconds
        // WAIT_PERIOD = 60 * 60; // One hour
        // WAIT_PERIOD = 1 * 60; // 1 Minute
        // WAIT_PERIOD = 5; // 5 seconds
#ifdef QT_DEBUG
        WAIT_PERIOD = 30; // one minute = 60
#endif

        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));

        //// main setup ///////////////////////////////////////////////////////

        MainWindow->setMinimumSize(QSize(W, H));
        MainWindow->setMaximumSize(QSize(W, H));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(W, H));
        centralwidget->setMaximumSize(QSize(W, H));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, W, H));
        stackedWidget->setMinimumSize(QSize(W, H));
        stackedWidget->setMaximumSize(QSize(W, H));

        start = new StartPage();
        stackedWidget->addWidget(start);

        noadmin = new NoAdminPage();
        stackedWidget->addWidget(noadmin);

        wronginstall = new WrongInstallLocationPage();
        stackedWidget->addWidget(wronginstall);

        regedit = new RegistryEditPage();
        stackedWidget->addWidget(regedit);

        goodbye = new GoodbyePage();
        stackedWidget->addWidget(goodbye);

        mod = new ModPage();
        stackedWidget->addWidget(mod);

        restart = new RestartPage();
        stackedWidget->addWidget(restart);

        form = new FormPage();
        stackedWidget->addWidget(form);

        wta = new WTAPage();
        stackedWidget->addWidget(wta);

        dc_accept = new DoubleCheckAccept();
        stackedWidget->addWidget(dc_accept);

        dc_decline = new DoubleCheckDecline();
        stackedWidget->addWidget(dc_decline);

        nomore = new NoMoreDaysPage();
        stackedWidget->addWidget(nomore);

        onemore = new OneMoreDayPage();
        stackedWidget->addWidget(onemore);

        survey = new SurveyPage();
        stackedWidget->addWidget(survey);

        cheat = new Check4Cheating();
        stackedWidget->addWidget(cheat);

        usage = new UsagePage();
        stackedWidget->addWidget(usage);

        hours = new HoursPage();
        stackedWidget->addWidget(hours);

        days = new DaysPage();
        stackedWidget->addWidget(days);

        improve = new ImproveChoicePage();
        stackedWidget->addWidget(improve);

        decrease = new DecreaseChoicePage();
        stackedWidget->addWidget(decrease);

        timeout = new TimeoutSplashPage();
        stackedWidget->addWidget(timeout);

        hmonitor = new HoursMonitorPage();
        stackedWidget->addWidget(hmonitor);

        hmin = new HoursMinimumPage();
        stackedWidget->addWidget(hmin);

        primary = new PrimaryDevicePage();
        stackedWidget->addWidget(primary);

        internet = new InternetPage();
        stackedWidget->addWidget(internet);

        /*tryupload = new PatchPage();
        stackedWidget->addWidget(tryupload);*/
        wait = new WaitPage();
        stackedWidget->addWidget(wait);

        retry = new RetryPage();
        stackedWidget->addWidget(retry);

        noteligible = new CompNotEligiblePage();
        stackedWidget->addWidget(noteligible);

        waitfinal = new WaitPage();
        stackedWidget->addWidget(waitfinal);

        retryfinal = new RetryPage();
        stackedWidget->addWidget(retryfinal);

        more = new MoreDaysPage();
        stackedWidget->addWidget(more);

        fail = new UploadFailPage();
        stackedWidget->addWidget(fail);

        purchase = new PurchasePage();
        stackedWidget->addWidget(purchase);

        selling = new SellingPointsPage();
        stackedWidget->addWidget(selling);

        //test = new TestEligibilityPage();
        //stackedWidget->addWidget(test);

    } // setupUi
};

namespace Ui {
    class MainWindow : public ui_Protocol2App {};
} // namespace Ui

QT_END_NAMESPACE