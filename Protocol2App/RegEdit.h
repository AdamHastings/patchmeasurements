#pragma once
#include <string>
#include <QString>
#include <QVariant>
using namespace std;

class RegEdit
{

public:
	static void setRegKey(QString key, int value);
	static void setRegKey(QString key, QString value);
	static QVariant getRegKey(QString key);
	static bool isCsEnabled();
	static void setCsEnabled(int i);


private:
	static QString RegOrg;
	static QString RegApp;

};

