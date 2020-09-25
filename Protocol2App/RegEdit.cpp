#include "RegEdit.h"
#include <QSettings>

QString RegEdit::prefix = "HKEY_LOCAL_USER\\Software\\HastingsExperiment2020\\";

void RegEdit::setRegKey(QString registry, QString key, int value) {
	QSettings reg(registry, QSettings::NativeFormat);
	reg.setValue(key, value);

}

QString RegEdit::getRegKey(QString registry, QString key) {
	QSettings reg(registry, QSettings::NativeFormat);
	return reg.value(key).toString();
}