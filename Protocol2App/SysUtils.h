#pragma once
#include <string>
#include <QString>
using namespace std;

//enum SnapshotType {
//	ACCEPT,
//	DECLINE,
//	TIMEOUT
//};


class SysUtils
{

public:

	static void takeSnapshot(QString snapshot_reason);
	static void restoreSystem();

private:

	static QString getTimestamp();
	static void restoreDefaultPowerSettings();

	SysUtils();
	~SysUtils();
};

