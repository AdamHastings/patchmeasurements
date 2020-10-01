#include "RegistryUtils.h"
#include <QSettings>
#include <QDebug>
using namespace std;

QString RegistryUtils::RegOrg = "Hastings";
QString RegistryUtils::RegApp = "Settings";

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
	QString path = "HKEY_CURRENT_USER\\Software\\" + RegOrg;
	QSettings(path, QSettings::NativeFormat).remove("");
}