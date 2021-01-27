#include "SysUtils.h"
#include "RegistryUtils.h"
#include "DropBox.h"
#include "crypto.h"
#include "PowerMgmt.h"
#include <map>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <qDebug>
#include <filesystem>
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
    contents.append("action,");
    contents.append(snapshot_reason);
    contents.append("\n");
    contents.append("timestamp,");
    contents.append(timestamp);
    contents.append("\n");

    contents.append("days,");
    if (snapshot_reason == "restore") {
        contents.append("NULL");
    }
    else {
        contents.append(RegistryUtils::getRegKey("Days").toString());
    }
    contents.append("\n");

    // TODO add more details here

    qDebug() << "adding file";
    string encrypted_filename = "logs/" + filename.toStdString() + ".txt";
    crypto::addFile(encrypted_filename, contents.toStdString(), "q49b0LfAlwP994jbqQf");
    DropBox::upload(contents, filename);
}

void SysUtils::restoreExperiment() {

}

void SysUtils::restoreDefaultPowerSettings() {

}

void SysUtils::restoreSystem() {
    //if (RegistryUtils::getRegKey("FirstOffer").toInt() != 1) {
    //    qDebug() << "restoring powermgmt defaults";
    //    PowerMgmt::restoreDefaults();
    //}
    /*else {
        qDebug() << "NOT restoring powermgmt defaults";
    }*/
    qDebug() << "restoring system";
    QVariant qv = RegistryUtils::getRegKey("CsEnabled");
    if (qv.isValid()) {
        RegistryUtils::setCsEnabled(1);
        qDebug() << "Restoring CsEnabled to 1";
        // REBOOT_AT_END = true; // TODO figure out how to do this
    }
    RegistryUtils::nuke();
    RegistryUtils::unsetAutorun();
    takeSnapshot("restore");
}

void SysUtils::initExperiment() {
    // set up everything that needs to be done the first time the user runs the experiment
    RegistryUtils::setRegKey("FirstOffer", 1);
    RegistryUtils::setRegKey("Days", 30);
    takeSnapshot("start");
}

QString SysUtils::getpwd() {
    string exename = (RegistryUtils::AppName + ".exe").toStdString();
    QString pwd = QString::fromStdString(std::filesystem::absolute(exename).string());
    qDebug() << pwd;
    return pwd;
}
