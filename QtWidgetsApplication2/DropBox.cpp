#include "DropBox.h"
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QString>
#include <QNetworkReply>
#include <QDebug>


DropBox::DropBox()
{
}

DropBox::~DropBox()
{
}

void DropBox::upload(std::string s) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << repl->readAll();
            qDebug() << "in callback";
        });

    QString filename = "qtupload.txt";

    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer fsWUJerSFOIAAAAAAAAAASbQxDbv1tNxwkJ1PIJ4bukUYqf5zU0fxqherrO8gYre"));

    QString dropboxArg = QString("{\"path\": \"/qtupload.txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");

    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QFile* file = new QFile(filename);
    file->open(QIODevice::ReadOnly);
    QByteArray content = file->readAll();
    qDebug() << content;

    QNetworkReply* reply = mgr->post(request, QByteArray(s.c_str()));
}
