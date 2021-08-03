#pragma once
#include <string>
#include <QString>
using namespace std;


class SysUtils
{

public:

	static QString takeSnapshot(QString snapshot_reason);
	static void restoreSystem();
	static void initExperiment();
	static int getUnixTime();
	static QString getpwd();
	static QString getTimestamp();

	static bool REBOOT_AT_END;


private:


	SysUtils();
	~SysUtils();
};

