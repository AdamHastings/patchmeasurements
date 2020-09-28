#include "RegEdit.h"
#include <QSettings>


void RegEdit::setRegKey(QString registry, QString key, int value) {
	//QSettings reg(registry, QSettings::NativeFormat);
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, "Hastings", "Tasks2020");
	reg.setValue(key, value);

}

QVariant RegEdit::getRegKey(QString registry, QString key) {
	QSettings reg(registry, QSettings::NativeFormat);
	return reg.value(key);
}