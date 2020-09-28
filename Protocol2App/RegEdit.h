#pragma once
#include <string>
#include <QString>
#include <QVariant>
using namespace std;

class RegEdit
{

public:
	static void setRegKey(QString registry, QString key, int value);
	static QVariant getRegKey(QString registry, QString key);

};

