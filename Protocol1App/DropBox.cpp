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


DropBox::DropBox()
{
}

DropBox::~DropBox()
{
}

void DropBox::upload(std::string contents, std::string filename) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << repl->readAll();
            qDebug() << "in callback";
        });

    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));

    filename.erase(remove_if(filename.begin(), filename.end(), [](char c) {return !isalnum(c); }), filename.end());

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));

    QString dropboxArg = QString("{\"path\": \"/ " + QString::fromStdString(filename) + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");

    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QNetworkReply* reply = mgr->post(request, QByteArray(contents.c_str()));
}

bool DropBox::uploadDone = false;
bool DropBox::checkDone = false;

void DropBox::upload(QString contents, std::string filename) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << "*********in upload callback**********";
            qDebug() << repl->readAll();
            qDebug() << "*********in upload callback**********";
            //uploadDone = true;
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
    //loop->connect(mgr, &QNetworkAccessManager::finished, loop, &QEventLoop::quit);
    //QObject::connect(mgr, &QNetworkAccessManager::finished,
    //    [&](QNetworkReply* repl) {
    //        qDebug() << "*********in upload callback**********";
    //        qDebug() << repl->readAll();
    //        qDebug() << "*********in upload callback**********";
    //        //uploadDone = true;
    //    });
    loop.exec();
}

bool DropBox::uploadSuccessful(std::string uni) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << "*********in check callback*******";
            qDebug() << repl->error();
            qDebug() << repl->readAll();
            qDebug() << repl->errorString();
            qDebug() << repl->rawHeaderList();
            qDebug() << repl->errorString();
            qDebug() << "*********in check callback*******";
            //checkDone = true;
        });

    QNetworkRequest request(QUrl("https://api.dropboxapi.com/2/files/get_metadata"));

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));

    //QString dropboxArg = QString("{\"path\": \"/" + QString::fromStdString(uni) + ".txt\"}");

    // request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
    

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));

    QByteArray jsonString = "{\"path\": \"/" + QByteArray::fromStdString(uni) + ".txt\"}";

    //QNetworkReply* reply = mgr->post(request, QByteArray(contents.c_str()));
    QNetworkReply* reply = mgr->post(request, jsonString);


    qDebug("================ reply ================");
    qDebug() << jsonString;
    qDebug() << reply->error();
    qDebug() << reply->readAll();
    qDebug() << reply->errorString();
    qDebug() << reply->rawHeaderList();

    QEventLoop loop;
    loop.connect(mgr, SIGNAL(finished(QNetworkReply*)), SLOT(quit()));
    loop.exec();

    return true;
}
