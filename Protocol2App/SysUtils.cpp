#include "SysUtils.h"
#include "RegistryUtils.h"
#include "DropBox.h"
#include "PowerMgmt.h"
#include <map>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;


QString SysUtils::getTimestamp() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%m-%d-%Y %H-%M-%S");
    auto str = oss.str();
    return QString::fromStdString(str);
}


// Takes a snapshot of the system and uploads to Dropbox
void SysUtils::takeSnapshot(QString snapshot_reason) {
    QString timestamp = getTimestamp();
    QString date = timestamp.split(QRegExp("\\s+"), QString::SkipEmptyParts)[0];
    QString filename = date + "-" + snapshot_reason;

    // header info
    QString contents = "";
    contents.append("reason,");
    contents.append(snapshot_reason);
    contents.append("\n");
    contents.append("timestamp,");
    contents.append(filename);
    contents.append("\n");

    contents.append("days");
    contents.append(RegistryUtils::getRegKey("days").toString());
    contents.append("\n");

    map<string, int> currentPowerSettings = PowerMgmt::getCurrentPowerSettings();

    // power settings
    for (auto i : currentPowerSettings) {
        contents.append(QString::fromStdString(i.first));
        contents.append(",");
        contents.append(QString::number(i.second));
        contents.append("\n");
    }

    DropBox::upload(contents, filename);
}

void SysUtils::restoreDefaultPowerSettings() {
    // TODO
}

void SysUtils::restoreSystem() {
    restoreDefaultPowerSettings();
    takeSnapshot("restore");
    RegistryUtils::nuke();
}
