#pragma once
#include <string>
#include <QString>
#include <vector>
#include <stdbool.h>

class PowerMgmt
{

public: 

	//static int default_ACProcThrottleMin;
	//static int default_ACProcThrottleMax;
	//static int default_DCProcThrottleMin;
	//static int default_DCProcThrottleMax;

	static QString customPowerPlanGUID;
	static QString defaultPowerPlan;
	static int defaultCsEnabled;



	static std::vector<int> parsePowercfgOutput(std::string s);
	static void getDefaultPowercfg();
	static void setFreqCap(int p);
	static void removeFreqCap();
	static void restoreDefaults();
	static bool isCsEnabled();
	static void setCsEnabled(int i);
	static bool runningAsAdmin();
	static void createCustomPowerPlan();
	

private:
	PowerMgmt();
	~PowerMgmt();



	static void deleteCustomPowerPlan();
	static void restoreDefaultPowerPlan();
};

