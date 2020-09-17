#include "PowerMgmt.h"
#include "Windows.h"
#include <sstream>
#include <QProcess>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

PowerMgmt::PowerMgmt() {
}

PowerMgmt::~PowerMgmt() {
}


vector<int> PowerMgmt::parsePowercfgOutput(string s) {
    // gets last two values and returns in vector
    vector<string> tokens;

    istringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        tokens.push_back(tmp);
        cout << tmp << endl;
    }

    cout << tokens[tokens.size() - 1] << endl;
    cout << tokens[tokens.size() - 7] << endl;

    vector<int> retvec{ 0, 0 };
    return retvec;
}

int PowerMgmt::default_ACProcThrottleMin;
int PowerMgmt::default_DCProcThrottleMin;
int PowerMgmt::default_ACProcThrottleMax;
int PowerMgmt::default_DCProcThrottleMax;

void PowerMgmt::getDefaultPowercfg() {
#ifdef _WIN32
    string get_max_default = "powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX";
    string get_min_default = "powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN";

    QProcess process;
    process.start("powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX");
    process.waitForFinished(-1);

    vector<int> maxs = parsePowercfgOutput(process.readAllStandardOutput().toStdString());

    process.start("powercfg Q SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN");
    process.waitForFinished(-1);

    vector<int> mins = parsePowercfgOutput(process.readAllStandardOutput().toStdString());

    default_ACProcThrottleMin = mins[0];
    default_DCProcThrottleMin = mins[1];
    default_ACProcThrottleMax = maxs[0];
    default_DCProcThrottleMax = maxs[1];

#endif
}

void PowerMgmt::setFreq(int p) {
#if QT_NO_DEBUG
#ifdef _WIN32

    std::string min_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(p);
    std::string min_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(p);
    std::string max_ac_str = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + std::to_string(p);
    std::string max_dc_str = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + std::to_string(p);

    WinExec(min_ac_str.c_str(), SW_HIDE);
    WinExec(min_dc_str.c_str(), SW_HIDE);
    WinExec(max_ac_str.c_str(), SW_HIDE);
    WinExec(max_dc_str.c_str(), SW_HIDE);

    // TODO maybe switch to QProcess?

#endif
#endif
}

void PowerMgmt::restoreDefaults() {
    
    // TODO what if program quits halfway through app?
    QProcess proc;

    string def_min_ac = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(default_ACProcThrottleMin);
    string def_max_ac = "powercfg -setacvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(default_ACProcThrottleMax);
    string def_min_dc = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMIN " + std::to_string(default_ACProcThrottleMin);
    string def_max_dc = "powercfg -setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR PROCTHROTTLEMAX " + std::to_string(default_ACProcThrottleMin);

    proc.start(def_min_ac.c_str());
    proc.start(def_max_ac.c_str());
    proc.start(def_max_dc.c_str());
    proc.start(def_max_dc.c_str());
}