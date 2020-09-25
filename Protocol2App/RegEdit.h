#pragma once
#include <string>
#include <QString>
using namespace std;

class RegEdit
{

public:
	static void setRegKey(QString registry, QString key, int value);
	static QString getRegKey(QString registry, QString key);

private:
	static QString prefix;
};

