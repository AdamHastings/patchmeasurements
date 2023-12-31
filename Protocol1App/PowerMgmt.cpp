#include "PowerMgmt.h"
#include "Windows.h"
#include "RegistryUtils.h"
#include "Globals.h"
#include <sstream>
#include <QProcess>
#include <QSettings>
#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <vector>
#include <QRegularExpression>
using namespace std;

PowerMgmt::PowerMgmt() {
}

PowerMgmt::~PowerMgmt() {
}

QString PowerMgmt::defaultPowerPlan;
QString PowerMgmt::customPowerPlanGUID;

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

void PowerMgmt::getSystemConfigStart(QProcess& proc) {
    QStringList commands;
    commands.append("Get-ComputerInfo");
    proc.start("powershell", commands);
}

QString PowerMgmt::getSystemConfigRead(QProcess &proc) {
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());

    // qDebug() << "output:";
    // qDebug() << output;

    output.replace(",", ";");
    QRegularExpression regex("\\s+:\\s");
    output.replace(regex, ",");
    QRegularExpression re3("\r\n\ {2,}");
    output.replace(re3, "");
    QRegularExpression re2("^\\s+");
    output.replace(re2, "");
    return output;
}

void PowerMgmt::getDefaultPowercfg() {
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

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + QString::number(p));
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + QString::number(p));
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

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX 100");
    proc.waitForFinished(-1);

    proc.start("powercfg -setactive SCHEME_CURRENT");
    proc.waitForFinished(-1);
}

void PowerMgmt::restoreRegistry() {
    QVariant qv = RegistryUtils::getRegKey("CsEnabled");
    if (qv.isValid()) {
        RegistryUtils::setCsEnabled(1);
        qDebug() << "Restoring CsEnabled to 1";
        REBOOT_AT_END = true;
    }
    RegistryUtils::nuke();
}

void PowerMgmt::restoreDefaults() {
    restoreDefaultPowerPlan();
    deleteCustomPowerPlan();
    restoreRegistry();
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

double PowerMgmt::getCurrentClockFreq() {
    QString path = "C:/Windows/system32/WindowsPowerShell/v1.0/powershell.exe";
    QStringList commands;
    commands.append("-Command");
    commands.append("(Get-CimInstance CIM_Processor).MaxClockSpeed * ((Get-Counter -Counter \"\\Processor Information(_Total)\\% Processor Performance\").CounterSamples.CookedValue/100)");
    QProcess proc;
    proc.start("powershell", commands);
    proc.waitForFinished(-1);

    QString output(proc.readAllStandardOutput());

    if (output.length() > 2) {
        output = output.left(output.length() - 2);
        return output.toDouble();
    }
    else {
        return -1;
    }
}

void PowerMgmt::getCurrentClockFreqStart(QProcess &proc) {
    QStringList commands;
    commands.append("-Command");
    commands.append("(Get-CimInstance CIM_Processor).MaxClockSpeed * ((Get-Counter -Counter \"\\Processor Information(_Total)\\% Processor Performance\").CounterSamples.CookedValue/100)");
    proc.start("powershell", commands);
    
}

double PowerMgmt::getCurrentClockFreqRead(QProcess &proc) {
    // Blocking 
    proc.waitForFinished(-1);

    QString output(proc.readAllStandardOutput());

    if (output.length() > 2) {
        output = output.left(output.length() - 2);
        qDebug() << output;
        return output.toDouble();
    }
    else {
        return -1;
    }
}

QString PowerMgmt::getCurrentCPUUtilization() {
    QProcess proc;
    QStringList commands;
    commands.append("-Command");
    commands.append("Get-WmiObject Win32_Processor | Measure-Object -Property LoadPercentage -Average | Select Average");
    proc.start("powershell", commands);
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    QStringList split_output = output.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    QString utilization = split_output.value(split_output.length() - 1);
    return utilization;
}

void PowerMgmt::getCurrentCPUUtilizationStart(QProcess &proc) {
    QStringList commands;
    commands.append("-Command");
    commands.append("Get-WmiObject Win32_Processor | Measure-Object -Property LoadPercentage -Average | Select Average");
    proc.start("powershell", commands);
}

QString PowerMgmt::getCurrentCPUUtilizationRead(QProcess &proc) {
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    QStringList split_output = output.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    QString utilization = split_output.value(split_output.length() - 1);
    return utilization;
}

QString PowerMgmt::getTotalRAM() {
    QProcess proc;
    QStringList commands;
    commands.append("-Command");
    commands.append("Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum");
    proc.start("powershell", commands);
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    output = output.replace("\\n", ",");
    output = output.replace("\\r", "");
    output = output.simplified();
    return output;
}

QString PowerMgmt::getCurrentRAMUtilization() {
    QProcess proc;
    QStringList commands;
    commands.append("-Command");
    commands.append("Get-Counter '\\Memory\\Available MBytes'");
    proc.start("powershell", commands);
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    QStringList split_output = output.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QString utilization = split_output.value(split_output.length() - 1);
    return utilization;
}

void PowerMgmt::getCurrentRAMUtilizationStart(QProcess &proc) {
    QStringList commands;
    commands.append("-Command");
    commands.append("Get-Counter '\\Memory\\Available MBytes'");
    proc.start("powershell", commands);
}

QString PowerMgmt::getCurrentRAMUtilizationRead(QProcess& proc) {
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    QStringList split_output = output.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QString utilization = split_output.value(split_output.length() - 1);
    return utilization;
}

