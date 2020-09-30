#include "RegEdit.h"
#include <QSettings>
#include <QDebug>
using namespace std;

QString RegEdit::RegOrg = "Hastings";
QString RegEdit::RegApp = "Settings";

void RegEdit::setRegKey(QString key, int value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

void RegEdit::setRegKey(QString key, QString value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

QVariant RegEdit::getRegKey(QString key) {
	//QSettings reg(registry, QSettings::NativeFormat);
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	return reg.value(key);
}

void RegEdit::setCsEnabled(int i) {
	QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
	reg.setValue("CsEnabled", i);
	qDebug() << "CsEnabled set to " << reg.value("CsEnabled").toInt();
}

bool RegEdit::isCsEnabled() {
	QSettings reg("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power", QSettings::NativeFormat);
	return (bool)reg.value("CsEnabled").toInt();
}