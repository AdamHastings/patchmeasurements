#include "Protocol2App.h"
#include "RegistryUtils.h"
#include "PowerMgmt.h"
#include "SysUtils.h"
#include <QCloseEvent>
#include <time.h>
#include <QDebug>
#include <thread>
#include <chrono>
#include <stdlib.h>

int Protocol2App::days;
QString Protocol2App::uni;
//QString Protocol2App::name;
int Protocol2App::hours;
int Protocol2App::acceptances = 0;
QString Protocol2App::snapshot_reason;
double Protocol2App::start_freq;
double Protocol2App::accept_freq;

void Protocol2App::enableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (closeFlag);
    setWindowFlags(flags);
    this->show();
}

void Protocol2App::disableExitButton() {
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
    this->show();
}

void Protocol2App::showStartNext() {
    if (ui.start->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else if (!PowerMgmt::runningAsAdmin()) {
            ui.stackedWidget->setCurrentWidget(ui.noadmin);
    }
/* If they use the "run.exe" this shouldn't be an issue
#ifndef QT_DEBUG
    else if (SysUtils::getpwd() != "C:\\Program Files\\" + RegistryUtils::AppName + "\\" + "Experiment.exe") {
        ui.stackedWidget->setCurrentWidget(ui.wronginstall);
    }
#endif
*/
    else if (RegistryUtils::isCsEnabled()) {
        ui.stackedWidget->setCurrentWidget(ui.mod);
    } else {
        //getDefaultPowercfg();
        //disableExitButton();
        //ui.stackedWidget->setCurrentWidget(ui.form);
        ui.stackedWidget->setCurrentWidget(ui.primary);

    }
    
}

void Protocol2App::showModNext() {
    if (ui.mod->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        //showFormPage();
        RegistryUtils::setCsEnabled(0);
        RegistryUtils::setRegKey("CsEnabled_default", 1);
        qDebug() << "CsEnabled_default is " + RegistryUtils::getRegKey("CsEnabled_default").toString();
        ui.stackedWidget->setCurrentWidget(ui.restart);
    }
}

void Protocol2App::showHoursNext() {
    if (ui.hours->spin->value() >= 10) {
        setHours(ui.hours->spin->value());
        showHMonitor();
    }
    else {
        showGoodbye();
    }
}

void Protocol2App::showHMonitor() {
    ui.stackedWidget->setCurrentWidget(ui.hmonitor);
}

void Protocol2App::showHMonitorNext(){
    if (ui.hmonitor->not_consent_btn->isChecked()) {
        SysUtils::takeSnapshot("no-monitor");
        SysUtils::restoreSystem();
        showGoodbye();
    }
    else {
        //showFormPage();
        ui.hmin->resetPage(hours);
        ui.stackedWidget->setCurrentWidget(ui.hmin);
    }
}

void Protocol2App::showHMinNext(){
    if (ui.hmin->not_consent_btn->isChecked()) {
        SysUtils::takeSnapshot("no-min");
        SysUtils::restoreSystem();
        showGoodbye();
    }
    else {
        //showFormPage();
        showWTA();
    }
}

void Protocol2App::showPrimaryNext() {
    if (ui.primary->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        //showFormPage();
        ui.stackedWidget->setCurrentWidget(ui.internet);
    }
}

void Protocol2App::showInternetNext() {
    if (ui.internet->not_consent_btn->isChecked()) {
        showGoodbye();
    }
    else {
        showFormPage();
    }
}

void Protocol2App::showFormPage() {
    disableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.form);
}

void Protocol2App::showWTA() {
    qDebug() << "days: " << days;
    if (days == TOTAL_DAYS) {
        SysUtils::initExperiment();
        SysUtils::takeSnapshot("start");
    }
    ui.wta->resetPage(days, acceptances);
    ui.stackedWidget->setCurrentWidget(ui.wta);
}

void Protocol2App::WTAnext() {
    if (ui.wta->accept->isChecked()) {
        //ui.stackedWidget->setCurrentWidget(ui.dc_accept);
        acceptOffer();
    }
    else if (ui.wta->decline->isChecked()) {
        //ui.stackedWidget->setCurrentWidget(ui.dc_decline);
        declineOffer();
    }
    else {
        qDebug() << "ERROR: Nothing selected in WTA page";
    }
}

void Protocol2App::showGoodbye() {
    SysUtils::restoreSystem();
    // RegistryUtils::nuke();
    ui.goodbye->resetPage();
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.goodbye);
}


void Protocol2App::tryUpload() {
    ui.wait->continue_btn->setEnabled(true);
    ui.stackedWidget->setCurrentWidget(ui.wait);
    //ui.tryupload->fillFirstHalf();
    
}

void Protocol2App::tryUploadNext() {
    static int num_tries;
    int MAX_TRIES = 3;


    // check if upload exists
    //QString timestamp = SysUtils::getTimestamp();
    //QString date = timestamp.split(QRegExp("\\s+"), QString::SkipEmptyParts)[0];
    //QString filename = date + "-" + snapshot_reason + ".txt";
    //ui.wait->continue_btn->setEnabled(false);
    QString filename = SysUtils::takeSnapshot(snapshot_reason);
    filename += ".txt";
//#ifdef QT_DEBUG
//    num_tries = 3;
//#endif

    ui.wait->continue_btn->setEnabled(false);
    if (days == TOTAL_DAYS) {
        if (num_tries >= MAX_TRIES) {
            // It just doesn't work. There's no precedent of it working, either
            qDebug() << "num tries exceeded";
            SysUtils::takeSnapshot("num_tries_exceeded");
            SysUtils::restoreSystem();
            ui.noteligible->resetPage(uni);
            enableExitButton();
            ui.stackedWidget->setCurrentWidget(ui.noteligible);
            return;
        }
        // check that freqs are acceptable
#ifndef QT_DEBUG
        else if (accept_freq > (start_freq * (100.0 - double(SLOWDOWN))/100.0 * 1.03) // 3% for some tolerance
            || accept_freq == 0
            || start_freq == 0
            ) {
            qDebug() << "bad freqs";
            SysUtils::takeSnapshot("bad_freqs");
            SysUtils::restoreSystem();
            ui.noteligible->resetPage(uni);
            enableExitButton();
            ui.stackedWidget->setCurrentWidget(ui.noteligible);
            return;
        }
#endif
    }
    if (DropBox::uploadSuccessful(uni, filename)) {
        // the upload worked // proceed with app
        ui.onemore->resetPage(days, uni);
        enableExitButton();
        ui.stackedWidget->setCurrentWidget(ui.onemore);
    }
    else {
        // increment attempts
        num_tries++;
        qDebug() << "trying again...";
        // Tell participant to connect to internet
        ui.stackedWidget->setCurrentWidget(ui.retry);
    }
}

void Protocol2App::acceptOffer() {
    acceptances++;
    RegistryUtils::setRegKey("acceptances", acceptances);
    //SysUtils::takeSnapshot("accept");


    // get current time
    int time = SysUtils::getUnixTime();
    if (days == TOTAL_DAYS) { // This is the first acceptance
        RegistryUtils::setAutorun();

        PowerMgmt::getDefaultPowercfg();
        PowerMgmt::createCustomPowerPlan();
        PowerMgmt::setFreqCap(100 - SLOWDOWN);
        // add timestamp of first accept
        RegistryUtils::setRegKey("first_accept", time);
    }
    // add timestamp of last accept (which should be the same)
    RegistryUtils::setRegKey("last_accept", time);

    snapshot_reason = "accept";
    tryUpload();


    /*ui.onemore->resetPage(days);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.onemore);*/
}

void Protocol2App::showPreUpload() {
    ui.waitfinal->continue_btn->setEnabled(true);
    ui.stackedWidget->setCurrentWidget(ui.waitfinal);
}

void Protocol2App::tryFinalUpload() {
    ui.waitfinal->continue_btn->setEnabled(false);
    /*ui.stackedWidget->setCurrentWidget(ui.waitfinal);*/

    if (days == 0) {
        snapshot_reason = "timeout";
    }
    else {
        snapshot_reason = "decline";
    }

#ifdef QT_DEBUG
    snapshot_reason = "decline";
    qDebug() << "snapshot reason: " << snapshot_reason;
#endif

    SysUtils::takeSnapshot(snapshot_reason);
    ui.waitfinal->continue_btn->setEnabled(true);

    tryFinalUploadNext();
}

void Protocol2App::tryFinalUploadNext() {
    // Check if upload was successful
    QString timestamp = SysUtils::getTimestamp();
    QString date = timestamp.split(QRegExp("\\s+"), QString::SkipEmptyParts)[0];
    QString filename = date + "-" + snapshot_reason + ".txt";
    static int retries = 0;
    int ATTEMPTS = 3;
#ifdef QT_DEBUG
    ATTEMPTS = 1;
#endif

    if (DropBox::uploadSuccessful(uni, filename)) {
        showNoMore();
    }
    else {
        retries++;
        if (retries < ATTEMPTS)
            showFinalRetry();
        else
            showUploadFail();
    }
}

void Protocol2App::showFinalRetry() {
    ui.stackedWidget->setCurrentWidget(ui.retryfinal);
}

void Protocol2App::showUploadFail() {
    ui.stackedWidget->setCurrentWidget(ui.fail);
}

void Protocol2App::showNoMore() {
    // remove previously created file
    string USERPROFILE = getenv("USERPROFILE");
    string filename = USERPROFILE + "\\OneDrive\\Desktop\\results.txt";
    remove(filename.c_str());
    filename = USERPROFILE + "\\Desktop\\results.txt";
    remove(filename.c_str());

    ui.nomore->resetPage(days, acceptances, uni);
    enableExitButton();
    ui.stackedWidget->setCurrentWidget(ui.nomore);
}

void Protocol2App::declineOffer() {
    SysUtils::restoreSystem();
    showSurvey();
}

void Protocol2App::showSurvey() {
    ui.survey->resetPage(days);
    ui.stackedWidget->setCurrentWidget(ui.survey);
}

void Protocol2App::showCheat() {
    ui.stackedWidget->setCurrentWidget(ui.cheat);
}

void Protocol2App::showSurveyNext() {
    if (days == TOTAL_DAYS) {
        // This is the first time
        showPurchase();
    }
    else {
        showCheat();
    }
}

void Protocol2App::showHours() {
    ui.stackedWidget->setCurrentWidget(ui.hours);
}

void Protocol2App::showDays() {
    ui.stackedWidget->setCurrentWidget(ui.days);
}

void Protocol2App::showImprove() {
    ui.stackedWidget->setCurrentWidget(ui.improve);
}

void Protocol2App::showDecrease() {
    ui.stackedWidget->setCurrentWidget(ui.decrease);
}

void Protocol2App::showMoreDays() {
    ui.stackedWidget->setCurrentWidget(ui.more);
}

void Protocol2App::showUsage() {
    ui.stackedWidget->setCurrentWidget(ui.usage);
}

void Protocol2App::showPurchase() {
    ui.stackedWidget->setCurrentWidget(ui.purchase);
}

void Protocol2App::showSellpoints() {
    ui.stackedWidget->setCurrentWidget(ui.selling);
}

void Protocol2App::showPurchaseNext() {
    if (ui.purchase->yes->isChecked()) {
        showSellpoints();
    }
    else {
        showImprove();
    }
}

void Protocol2App::showTimeoutSplash() {
    ui.stackedWidget->setCurrentWidget(ui.timeout);
}

void Protocol2App::closeEvent(QCloseEvent* event) {

    // If the user has elected to end the experiment, this should be empty..
    if (RegistryUtils::getRegKey("UNI").isValid())
    {
        if (days > 0) 
        {
            event->ignore();
            this->hide();
            resetProgram();
        }
    }
    
    else if (RegistryUtils::getRegKey("CsEnabled_default") != 1)
    {
        // one more for good measure...
        RegistryUtils::nuke();
    }
    
}

void Protocol2App::resetProgram() {
    days = RegistryUtils::getRegKey("days").toInt();
    uni = RegistryUtils::getRegKey("UNI").toString();
    acceptances = RegistryUtils::getRegKey("acceptances").toInt();
    //name = RegistryUtils::getRegKey("name").toString();

    //  figure out how long to sleep, and how many days have elapsed
    int first_accept = RegistryUtils::getRegKey("first_accept").toInt();
    int last_accept = RegistryUtils::getRegKey("last_accept").toInt();
    int time_now = SysUtils::getUnixTime();
    
    if ((time_now - first_accept) >= (WAIT_PERIOD * TOTAL_DAYS)) { //timeout
        days = 0;
        RegistryUtils::setRegKey("days", days);
        SysUtils::takeSnapshot("audit");
        timeout();
        return;
    }
    if ((time_now - last_accept) <= (WAIT_PERIOD)) { // It hasn't been a full WAIT_PERIOD since last accept
        int time_to_sleep = (WAIT_PERIOD)-(time_now - last_accept);
        _sleep(time_to_sleep * 1000);
    }

    time_now = SysUtils::getUnixTime();
    days = TOTAL_DAYS - ((time_now - first_accept) / WAIT_PERIOD);
    RegistryUtils::setRegKey("days", days);
    SysUtils::takeSnapshot("audit");

    if (days <= 0) {
        timeout();
        return;
    }
    else {
        disableExitButton();
        showWTA();
        return;
    }
}

void Protocol2App::timeout() {
    SysUtils::restoreSystem();
    showTimeoutSplash();
    this->show();
}

int Protocol2App::getDays() {
    return days;
}

QString Protocol2App::getUNI() {
    return uni;
}

void Protocol2App::setUNI(QString input) {
    uni = input;
}

int Protocol2App::getHours() {
    return hours;
}

void Protocol2App::setHours(int input) {
    hours = input;
}

int Protocol2App::getAcceptances() {
    return acceptances;
}

void Protocol2App::setAcceptances(int input) {
    acceptances = input;
}

Protocol2App::Protocol2App(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // If this isn't the first time, load values from the registry
    if (RegistryUtils::getRegKey("days").isValid()) {
        resetProgram();
    }
    else {
        days = TOTAL_DAYS;
    }

    connect(ui.start->continue_btn, &QPushButton::clicked, this, &Protocol2App::showStartNext);
    connect(ui.mod->continue_btn, &QPushButton::clicked, this, &Protocol2App::showModNext);
    connect(ui.primary->continue_btn, &QPushButton::clicked, this, &Protocol2App::showPrimaryNext);
    connect(ui.internet->continue_btn, &QPushButton::clicked, this, &Protocol2App::showInternetNext);
    connect(ui.form->continue_btn, &QPushButton::clicked, this, &Protocol2App::showDays);
    connect(ui.days->continue_btn, &QPushButton::clicked, this, &Protocol2App::showHours);
    connect(ui.hours->continue_btn, &QPushButton::clicked, this, &Protocol2App::showHoursNext);
    connect(ui.hmonitor->continue_btn, &QPushButton::clicked, this, &Protocol2App::showHMonitorNext);
    connect(ui.hmin->continue_btn, &QPushButton::clicked, this, &Protocol2App::showHMinNext);
    connect(ui.wta->continue_btn, &QPushButton::clicked, this, &Protocol2App::WTAnext);
    connect(ui.survey->continue_btn, &QPushButton::clicked, this, &Protocol2App::showSurveyNext);
    connect(ui.cheat->continue_btn, &QPushButton::clicked, this, &Protocol2App::showMoreDays);
    connect(ui.more->continue_btn, &QPushButton::clicked, this, &Protocol2App::showPurchase);
    connect(ui.purchase->continue_btn, &QPushButton::clicked, this, &Protocol2App::showPurchaseNext);
    connect(ui.selling->continue_btn, &QPushButton::clicked, this, &Protocol2App::showImprove);
    connect(ui.improve->continue_btn, &QPushButton::clicked, this, &Protocol2App::showDecrease);
    connect(ui.decrease->continue_btn, &QPushButton::clicked, this, &Protocol2App::showUsage);
    connect(ui.usage->continue_btn, &QPushButton::clicked, this, &Protocol2App::showPreUpload);
    connect(ui.waitfinal->continue_btn, &QPushButton::clicked, this, &Protocol2App::tryFinalUpload);
    connect(ui.retryfinal->continue_btn, &QPushButton::clicked, this, &Protocol2App::showPreUpload);
    connect(ui.timeout->continue_btn, &QPushButton::clicked, this, &Protocol2App::showCheat);
    connect(ui.wait->continue_btn, &QPushButton::clicked, this, &Protocol2App::tryUploadNext);
    connect(ui.retry->continue_btn, &QPushButton::clicked, this, &Protocol2App::tryUpload);
    connect(ui.fail->continue_btn, &QPushButton::clicked, this, &Protocol2App::showNoMore);


#ifdef QT_DEBUG

    //RegistryUtils::setRegKey("UNI", "akh2167");
    //Protocol2App::setUNI("akh216777777777777776");

    connect(ui.start->consent_btn, &QPushButton::clicked, this, &Protocol2App::showMoreDays);
#endif
}