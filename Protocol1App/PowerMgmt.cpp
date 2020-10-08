#include "PowerMgmt.h"
#include "Windows.h"
#include <sstream>
#include <QProcess>
#include <QSettings>
#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

PowerMgmt::PowerMgmt() {
}

PowerMgmt::~PowerMgmt() {
}

QString PowerMgmt::defaultPowerPlan;
QString PowerMgmt::customPowerPlanGUID;
int PowerMgmt::defaultCsEnabled;


bool PowerMgmt::runningAsAdmin() {
    bool fRet = false;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fRet;
}

void PowerMgmt::setCsEnabled(int i) {
    QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
    reg.setValue("CsEnabled", i);
    qDebug() << "CsEnabled set to " << reg.value("CsEnabled").toInt();
}

bool PowerMgmt::isCsEnabled() {
    QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
    return (bool)reg.value("CsEnabled").toInt();
}

void PowerMgmt::getDefaultPowercfg() {
    defaultCsEnabled = (int)isCsEnabled();

    QProcess proc;
    proc.start("powercfg -getactivescheme");
    proc.waitForFinished(-1);

    string out = proc.readAllStandardOutput().toStdString();
    istringstream iss(out);
    vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());
    defaultPowerPlan = QString().fromStdString(tokens[3]);
  }

void PowerMgmt::setFreqCap(int p) {

    QProcess proc;

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 5 ");
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 5 ");
    proc.waitForFinished(-1);

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + QString::number(p));
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + QString::number(p));
    proc.waitForFinished(-1);

    proc.start("powercfg -setactive SCHEME_CURRENT");
    proc.waitForFinished(-1);
}

void PowerMgmt::removeFreqCap() {
    QProcess proc;

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 5 ");
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 5 ");
    proc.waitForFinished(-1);

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setactive SCHEME_CURRENT");
    proc.waitForFinished(-1);
}

void PowerMgmt::restoreDefaults() {
    restoreDefaultPowerPlan();
    deleteCustomPowerPlan();
    setCsEnabled(defaultCsEnabled);
}

void PowerMgmt::createCustomPowerPlan() {
    QProcess proc;

    QString HighPerformanceGUID = "8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c";

    // Create new power plan
    proc.start("powercfg -duplicatescheme " + HighPerformanceGUID);
    proc.waitForFinished(-1);

    string out = proc.readAllStandardOutput().toStdString();
    istringstream iss(out);
    vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());
    customPowerPlanGUID = QString().fromStdString(tokens[3]);
    qDebug() << customPowerPlanGUID;

    proc.start("powercfg -setactive " + customPowerPlanGUID);
    proc.waitForFinished(-1);
}

void PowerMgmt::deleteCustomPowerPlan() {
    QProcess proc;

    proc.start("powercfg -d " + customPowerPlanGUID);
    proc.waitForFinished(-1);

}

void PowerMgmt::restoreDefaultPowerPlan() {
    QProcess proc;
    proc.start("powercfg -setactive " + defaultPowerPlan);
    proc.waitForFinished(-1);
}

