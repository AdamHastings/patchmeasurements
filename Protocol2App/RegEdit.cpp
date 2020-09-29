#include "RegEdit.h"
#include <QSettings>
#include <QDebug>

void RegEdit::setRegKey(QString registry, QString key, int value) {
	//QSettings reg(registry, QSettings::NativeFormat);
	QSettings reg(QSettings::NativeFormat, QSettings::UserScope, "Hastings", "Tasks2020");
	reg.setValue(key, value);

	QSettings reg2("HKEY_LOCAL_USER\\SOFTWARE\\Hastings", QSettings::NativeFormat);

	qDebug() << "getRegKey: ";
	qDebug() << reg2.value("Tasks2020");

}

QVariant RegEdit::getRegKey(QString registry, QString key) {
	QSettings reg(registry, QSettings::NativeFormat);
	return reg.value(key);
}