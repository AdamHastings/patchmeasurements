#pragma once
#include <string>
#include <QString>
#include <QVariant>
using namespace std;

class RegEdit
{

public:
	static void setRegKey(QString RegOrg, QString RegApp, QString key, int value);
	static void setRegKey(QString RegOrg, QString RegApp, QString key, QString value);
	static QVariant getRegKey(QString registry, QString key);

};

