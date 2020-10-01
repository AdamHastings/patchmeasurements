#pragma once
#include <string>
#include <vector>
#include <map>
#include <stdbool.h>

class PowerMgmt
{

public:

	static int default_CsEnabled;
	static int default_ACProcThrottleMin;
	static int default_ACProcThrottleMax;
	static int default_DCProcThrottleMin;
	static int default_DCProcThrottleMax;

	static std::vector<int> parsePowercfgOutput(std::string s);
	static void getDefaultPowercfg();
	static void setFreq(int p);
	static void restoreDefaults();
	static bool runningAsAdmin();

	static std::map<std::string, int> getCurrentPowerSettings();

private:
	PowerMgmt();
	~PowerMgmt();
};

