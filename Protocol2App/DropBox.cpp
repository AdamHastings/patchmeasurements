#include "DropBox.h"
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QString>
#include <QNetworkReply>
#include <QDebug>
#include <QString>


DropBox::DropBox()
{
}

DropBox::~DropBox()
{
}

QString DropBox::directory;

void DropBox::setDirectory(QString dir) {
    directory = dir;
}

//void DropBox::upload(std::string contents, std::string filename) {
//    QNetworkAccessManager* mgr = new QNetworkAccessManager();
//
//    QObject::connect(mgr, &QNetworkAccessManager::finished,
//        [&](QNetworkReply* repl) {
//            qDebug() << repl->readAll();
//            qDebug() << "in callback";
//        });
//
//    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));
//
//    filename.erase(remove_if(filename.begin(), filename.end(), [](char c) {return !isalnum(c); }), filename.end());
//
//    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer qHsc0jnrT4EAAAAAAAAAAeHJyK46BY6Ayaon3yz_8A4FWkapt_RTku2PZf7vFPUu"));
//
//    QString dropboxArg = QString("{\"path\": \"/ " + directory + "/" + QString::fromStdString(filename) + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");
//
//#ifdef QT_DEBUG
//    dropboxArg = QString("{\"path\": \"/ " + directory + "/" + QString::fromStdString(filename) + ".txt\",\"mode\": \"add\",\"autorename\": false,\"mute\": false,\"strict_conflict\": false}");
//#endif
//
//
//    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
//
//    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));
//
//    QNetworkReply* reply = mgr->post(request, QByteArray(contents.c_str()));
//}

void DropBox::upload(QString contents, QString filename) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << repl->readAll();
            qDebug() << "in callback";
        });

    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));

 
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer qHsc0jnrT4EAAAAAAAAAAeHJyK46BY6Ayaon3yz_8A4FWkapt_RTku2PZf7vFPUu"));

    QString dropboxArg = QString("{\"path\": \"/ " + directory + "/" + filename + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");

#ifdef QT_DEBUG
    dropboxArg = QString("{\"path\": \"/ " + directory + "/" + filename + ".txt\",\"mode\": \"add\",\"autorename\": false,\"mute\": false,\"strict_conflict\": false}");
#endif


    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QNetworkReply* reply = mgr->post(request, QByteArray(contents.toStdString().c_str()));
}