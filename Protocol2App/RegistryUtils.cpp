#include "RegistryUtils.h"
#include <QSettings>
#include <QDebug>
using namespace std;

QString RegistryUtils::RegOrg = "Hastings";
QString RegistryUtils::RegApp = "Settings";
QString RegistryUtils::AppName = "HastingsExperiment";

void RegistryUtils::setRegKey(QString key, int value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

void RegistryUtils::setRegKey(QString key, QString value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

QVariant RegistryUtils::getRegKey(QString key) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	return reg.value(key);
}

void RegistryUtils::setCsEnabled(int i) {
	QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
	reg.setValue("CsEnabled", i);
	qDebug() << "CsEnabled set to " << reg.value("CsEnabled").toInt();
}

bool RegistryUtils::isCsEnabled() {
	QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
	return (bool)reg.value("CsEnabled").toInt();
}

// Removes the RegOrg from the Windows Registry
void RegistryUtils::nuke() {
	qDebug() << "nuking the registry";
	// TODO figure out why this sometimes fails. Perhaps RegOrg isn't being loaded properly the second time...?
	QString path = "HKEY_CURRENT_USER\\Software\\" + RegOrg;
	qDebug() << path;
	QSettings(path, QSettings::NativeFormat).remove("");
}

void RegistryUtils::setAutorun() {
	qDebug() << "*setting autorun*";
	// Doesn't run as Administrator...
	//QSettings reg("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	//QSettings reg("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	QSettings reg("HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);

	// TODO get current working directory. Tell participants not to move binary location
	reg.setValue(AppName, "\"C:\\Program Files\\" + AppName + "\\Experiment.exe\"");
	//reg.setValue(AppName, "\"C:\\Program Files\\Release\\Protocol2App.exe\"");
}

void RegistryUtils::unsetAutorun() {
	QString path = "HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Run";
	QSettings(path, QSettings::NativeFormat).remove(AppName);
	// "C:\Program Files (x86)\Dropbox\Client\Dropbox.exe" /systemstartup
}