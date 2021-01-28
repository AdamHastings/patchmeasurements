#pragma once
#include <string>
#include <QString>
#include <QVariant>
using namespace std;

class RegistryUtils
{

public:
	static void setRegKey(QString key, int value);
	static void setRegKey(QString key, QString value);
	static QVariant getRegKey(QString key);
	static void setAutorun();
	static void unsetAutorun();
	static bool isCsEnabled();
	static void setCsEnabled(int i);
	static void nuke();

public:
	static QString AppName;


private:
	static QString RegOrg;
	static QString RegApp;

};

