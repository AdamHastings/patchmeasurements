#pragma once
#include <string>
#include <vector>
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
	static bool isCsEnabled();
	static void setCsEnabled(int i);
	static bool runningAsAdmin();

private:
	PowerMgmt();
	~PowerMgmt();
};

