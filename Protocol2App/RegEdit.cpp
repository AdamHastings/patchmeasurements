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

QVariant RegEdit::getRegKey(QString registry, QString key) {
	QSettings reg(registry, QSettings::NativeFormat);
	return reg.value(key);
}