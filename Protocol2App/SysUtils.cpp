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
#include "ChoicePage.h"
#include <QDir>
#include <thread>
#include <chrono>
#include <stdlib.h>
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
    PowerMgmt::getSystemConfigStart(proc2);


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

    contents.append("days_remaining," + QString::number(Protocol2App::getDays()) + "\n");
    // contents.append("name," + Protocol2App::getName() + "\n"); // no name in MTurk
    contents.append("uni," + Protocol2App::getUNI() + "\n");

    // WTA offer price
    contents.append("wta_offer," + QString::number(OFFER) + "\n");

    // Slowdown
    contents.append("slowdown," + QString::number(SLOWDOWN) + "\n");

    contents.append("acceptances," + QString::number(Protocol2App::getAcceptances()) + "\n");

    contents.append("earnings," + QString::number(Protocol2App::getAcceptances() * OFFER) + "\n");
    
    // Append clock speed. Maybe we'll need to introduce the patch page?
    contents.append("freq," + QString::number(PowerMgmt::getCurrentClockFreqRead(proc)) + "\n");


    // survey results
    // only append survey results if this is a timeout or a decline.
    if (snapshot_reason == "decline" || snapshot_reason == "timeout") {
        if (snapshot_reason == "decline") {
            if (SurveyPage::not_enough_money->isChecked()) {
                contents.append("not_enough_money," + QString::number(SurveyPage::wta_input->value()) + "\n");
            }
            else {
                contents.append("not_enough_money,0\n");
            }
            contents.append("mistrust," + QString::number(SurveyPage::mistrust->isChecked()) + "\n");
            contents.append("other_users," + QString::number(SurveyPage::other_users->isChecked()) + "\n");
            contents.append("malfunction,");
            if (Protocol2App::getDays() == TOTAL_DAYS) {
                contents.append("n/a\n");
            }
            else if (SurveyPage::malfunction->isChecked()) {
                QString reason = SurveyPage::malfunction_reason->toPlainText();
                reason.replace(",", ";");
                reason.replace("\n", ";");
                contents.append(reason + "\n");
            }
            else {
                contents.append("0\n");
            }
            if (SurveyPage::other->isChecked()) {
                QString reason = SurveyPage::other_reason->toPlainText();
                reason.replace(",", ";");
                reason.replace("\n", ";");
                contents.append("other," + reason + "\n");
            }
            else {
                contents.append("other,0\n");
            }
        }
        contents.append("cheated,");
        // Not first time, cheating  is possible
        if (Protocol2App::getDays() != TOTAL_DAYS) {
            if (Check4Cheating::cheated_btn->isChecked()) {
                QString cheat_method = Check4Cheating::details->toPlainText();
                cheat_method.replace(",", ";");
                cheat_method.replace("\n", ";");
                contents.append(cheat_method + "\n");
            }
            else if (Check4Cheating::honest_btn->isChecked()) {
                contents.append("0\n");
            }
            else {
                contents.append("neither?\n");
            }
        }
        else {
            contents.append("n/a\n");
        }
        contents.append("hours," + QString::number(HoursPage::spin->value()) + "\n");

        contents.append("improve,");
        if (ImproveChoicePage::perf_btn->isChecked()) {
            contents.append("performance\n");
        }
        else if (ImproveChoicePage::sec_btn->isChecked()) {
            contents.append("security\n");
        }
        else {
            contents.append("neither?\n");
        }

        contents.append("decrease,");
        if (DecreaseChoicePage::perf_btn->isChecked()) {
            contents.append("performance\n");
        }
        else if (DecreaseChoicePage::sec_btn->isChecked()) {
            contents.append("security\n");
        }
        else {
            contents.append("neither?\n");
        }


        contents.append("gaming," + QString::number(UsagePage::gaming->isChecked()) + "\n");
        contents.append("word_processing," + QString::number(UsagePage::word_processing->isChecked()) + "\n");
        contents.append("spreadsheets," + QString::number(UsagePage::spreadsheets->isChecked()) + "\n");
        contents.append("programming," + QString::number(UsagePage::programming->isChecked()) + "\n");
        contents.append("streaming," + QString::number(UsagePage::streaming->isChecked()) + "\n");
        contents.append("video_editing," + QString::number(UsagePage::video_editing->isChecked()) + "\n");
        contents.append("animation," + QString::number(UsagePage::animation->isChecked()) + "\n");
        contents.append("design_tools," + QString::number(UsagePage::design_tools->isChecked()) + "\n");
        contents.append("web_searches," + QString::number(UsagePage::web_searches->isChecked()) + "\n");
        contents.append("email," + QString::number(UsagePage::email->isChecked()) + "\n");
        contents.append("e_reading," + QString::number(UsagePage::e_reading->isChecked()) + "\n");
        contents.append("social_media," + QString::number(UsagePage::social_media->isChecked()) + "\n");
        contents.append("video_calls," + QString::number(UsagePage::video_calls->isChecked()) + "\n");
        contents.append("crypto_mining," + QString::number(UsagePage::crypto_mining->isChecked()) + "\n");
        contents.append("photo_storage," + QString::number(UsagePage::photo_storage->isChecked()) + "\n");
        contents.append("shopping," + QString::number(UsagePage::shopping->isChecked()) + "\n");
        contents.append("other," + QString::number(UsagePage::other->isChecked()) + "\n");
        QString other_input = UsagePage::input->text();
        other_input.replace(",", ";");
        other_input.replace("\n", ";");
        if ((UsagePage::other->isChecked()))
            contents.append("other_input," + other_input + "\n");
        else
            contents.append("other_input,n/a\n");
    }

    // append sysinfo
    QString sysinfo = PowerMgmt::getSystemConfigRead(proc2);
    contents.append(sysinfo);

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

// Restore system to its original, pre-experiment state
void SysUtils::restoreSystem() {
    qDebug() << "restoring system";
    int CsEnabled_default = RegistryUtils::getRegKey("CsEnabled_default").toInt();
    if (CsEnabled_default == 1) {
        RegistryUtils::setCsEnabled(1);
        qDebug() << "Restoring CsEnabled to 1";
        // REBOOT_AT_END = true; // TODO figure out how to do this
    }
    if (Protocol2App::getDays() != TOTAL_DAYS || (Protocol2App::getDays() == TOTAL_DAYS && Protocol2App::snapshot_reason == "accept")) {
        PowerMgmt::restoreDefaults();
        RegistryUtils::unsetAutorun();
    }
    RegistryUtils::nuke();
}

void SysUtils::initExperiment() {
    RegistryUtils::setRegKey("Days", TOTAL_DAYS);
}

QString SysUtils::getpwd() {
    string exename = "Experiment.exe";
    //QString pwd = QString::fromStdString(std::filesystem::absolute(exename).string());
    //QString pwd = QString::fromStdString(std::filesystem::current_path().string());
    QString pwd = QDir::currentPath();
    qDebug() << pwd;
    return pwd;
}

int SysUtils::getUnixTime() {
    /*const auto p1 = std::chrono::system_clock::now();
    uint timeSinceEpoch = std::chrono::duration_cast<uint>(p1.time_since_epoch());
    return timeSinceEpoch;*/
    std::time_t t = std::time(0);  // t is an integer type
    return t;
}
