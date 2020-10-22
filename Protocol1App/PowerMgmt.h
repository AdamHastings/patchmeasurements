#pragma once
#include <string>
#include <QString>
#include <vector>
#include <stdbool.h>

class PowerMgmt
{

public: 

	static QString customPowerPlanGUID;
	static QString defaultPowerPlan;

	static void getDefaultPowercfg();
	static void setFreqCap(int p);
	static void removeFreqCap();
	static void restoreDefaults();
	static bool runningAsAdmin();
	static void createCustomPowerPlan();

	static int getCurrentClockFreq();
	

private:
	PowerMgmt();
	~PowerMgmt();

	static void deleteCustomPowerPlan();
	static void restoreDefaultPowerPlan();
};

