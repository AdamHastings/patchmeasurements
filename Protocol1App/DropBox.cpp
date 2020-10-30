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

void DropBox::upload(QString contents, std::string filename) {
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

    QNetworkReply* reply = mgr->post(request, contents.toUtf8());
}
