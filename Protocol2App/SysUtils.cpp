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
#include <fstream>
#include "SurveyPage.h"
#include "Globals.h"
#include "Protocol2App.h"
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

    QProcess proc, proc2;
    PowerMgmt::getCurrentClockFreqStart(proc);
    PowerMgmt::getCurrentClockFreqStart(proc2);


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

    // append registry contents
    /*contents.append("days,");
    if (snapshot_reason == "restore") {
        contents.append("RESTORE\n");
    }
    else {
        contents.append(RegistryUtils::getRegKey("Days").toString() + "\n");
    }*/
    contents.append("days," + QString::number(Protocol2App::getDays()) + "\n");

    contents.append("name," + RegistryUtils::getRegKey("name").toString() + "\n");
    contents.append("uni," + Protocol2App::getUNI() + "\n");

    // WTA offer price
    contents.append("wta_offer," + QString::number(OFFER) + "\n");

    // Slowdown
    contents.append("slowdown," + QString::number(SLOWDOWN) + "\n");
    
    // Append clock speed. Maybe we'll need to introduce the patch page?
    contents.append("freq," + QString::number(PowerMgmt::getCurrentClockFreqRead(proc)) + "\n");


    // TODO survey results
    // TODO only append survey results if this is a timeout or a decline.

    if (snapshot_reason == "final") {
        if (SurveyPage::not_enough_money->isChecked()) {
            contents.append("not_enough_money," + QString::number(SurveyPage::wta_input->value()) + "\n");
        } 
        else {
            contents.append("not_enough_money,no\n");
        }
        contents.append("mistrust," + QString::number(SurveyPage::mistrust->isChecked()) + "\n");
        contents.append("other_users," + QString::number(SurveyPage::other_users->isChecked()) + "\n");
        if (SurveyPage::other->isChecked()) {
            QString reason = SurveyPage::other_reason->toPlainText();
            reason.replace(",", ";");
            reason.replace("\n", ";");
            contents.append("other," + reason + "\n");
        }
        else {
            contents.append("other,\n");
        }
    }
    // Not first time, cheating  is possible
    if (Protocol2App::getDays() != TOTAL_DAYS) {
        contents.append("cheated,");
        if (Check4Cheating::cheated_btn->isChecked()) {
            QString cheat_method = Check4Cheating::details->toPlainText();
            cheat_method.replace(",", ";");
            cheat_method.replace("\n", ";");
            contents.append("other," + cheat_method + "\n");
        }
        else if (Check4Cheating::honest_btn->isChecked()) {
            contents.append("no");
        }
        else {
            contents.append("neither?");
        }
        contents.append("\n");
    }
    



    // TODO append sysinfo
    PowerMgmt::getSystemConfigRead(proc2);


    // Save encrypted file to device
    string encrypted_filename = "logs/" + filename.toStdString() + ".txt";
    crypto::addFile(encrypted_filename, contents.toStdString(), "q49b0LfAlwP994jbqQf");

    // Debug plaintext results
#ifdef QT_DEBUG
    ofstream myfile;
    string debug_filename = encrypted_filename + ".debug";
    myfile.open(debug_filename);
    myfile << contents.toStdString();
    myfile.close();
#endif

    // Upload to DB
    DropBox::upload(contents, filename);
}

void SysUtils::restoreExperiment() {

}

void SysUtils::restoreDefaultPowerSettings() {

}

// Restore system to its original, pre-experiment state
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
    // Shouldn't this be where we restore performance?
    RegistryUtils::nuke();
    RegistryUtils::unsetAutorun();
    //takeSnapshot("restore");
}

void SysUtils::initExperiment() {
    // set up everything that needs to be done the first time the user runs the experiment
    // RegistryUtils::setRegKey("FirstOffer", 1);
    RegistryUtils::setRegKey("Days", 30);
}

QString SysUtils::getpwd() {
    string exename = (RegistryUtils::AppName + ".exe").toStdString();
    QString pwd = QString::fromStdString(std::filesystem::absolute(exename).string());
    qDebug() << pwd;
    return pwd;
}
