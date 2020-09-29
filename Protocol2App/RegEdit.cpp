#include "RegEdit.h"
#include <QSettings>
#include <QDebug>
using namespace std;

void RegEdit::setRegKey(QString RegOrg, QString RegApp, QString key, int value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

void RegEdit::setRegKey(QString RegOrg, QString RegApp, QString key, QString value) {
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, RegOrg, RegApp);
	reg.setValue(key, value);
}

QVariant RegEdit::getRegKey(QString registry, QString key) {
	QSettings reg(registry, QSettings::NativeFormat);
	return reg.value(key);
}