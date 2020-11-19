#include "DropBox.h"
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QString>
#include <QNetworkReply>
#include <QDebug>
#include <QString>
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonDocument>


DropBox::DropBox()
{
}

DropBox::~DropBox()
{
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
//    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));
//
//    QString dropboxArg = QString("{\"path\": \"/ " + QString::fromStdString(filename) + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");
//
//    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
//
//    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));
//
//    QNetworkReply* reply = mgr->post(request, QByteArray(contents.c_str()));
//}

void DropBox::upload(QString contents, std::string filename) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << "*********in upload callback**********";
            qDebug() << repl->readAll();
        });

    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));


    filename.erase(remove_if(filename.begin(), filename.end(), [](char c) {return !isalnum(c); }), filename.end());

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));

    QString dropboxArg = QString("{\"path\": \"/" + QString::fromStdString(filename) + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");

    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QNetworkReply* reply = mgr->post(request, contents.toUtf8());  

    QEventLoop loop;
    loop.connect(mgr, SIGNAL(finished(QNetworkReply*)), SLOT(quit()));
    loop.exec();
}

bool DropBox::uploadSuccessful(std::string uni) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QJsonObject json_reply;

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            //qDebug() << "*********in check callback*******";
            /*qDebug() << repl->error();
            qDebug() << repl->readAll();
            qDebug() << repl->errorString();
            qDebug() << repl->rawHeaderList();
            qDebug() << repl->errorString();*/
            json_reply = QJsonDocument::fromJson(repl->readAll()).object();
            /*qDebug() << json_reply;
            QString returned_filename;
            return true;*/
        });

    QNetworkRequest request(QUrl("https://api.dropboxapi.com/2/files/get_metadata"));

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));

    //QString dropboxArg = QString("{\"path\": \"/" + QString::fromStdString(uni) + ".txt\"}");

    // request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
    

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));

    QByteArray jsonString = "{\"path\": \"/" + QByteArray::fromStdString(uni) + ".txt\"}";

    //QNetworkReply* reply = mgr->post(request, QByteArray(contents.c_str()));
    QNetworkReply* reply = mgr->post(request, jsonString);

    QEventLoop loop;
    loop.connect(mgr, SIGNAL(finished(QNetworkReply*)), SLOT(quit()));
    loop.exec();

    qDebug("================ reply ================");
    qDebug() << json_reply;
    qDebug() << json_reply.value("name");

    if (json_reply.value("name").toString() == QString(QString::fromStdString(uni) + ".txt")) {
        return true;
    }
    else {
        return false;
    }
}
