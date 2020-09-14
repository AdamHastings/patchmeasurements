#include "dropbox.h"
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QString>
#include <QNetworkReply>
#include <QDebug>


DropBox::DropBox() {}
DropBox::~DropBox() {}

void DropBox::upload(std::string s) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << "HTTPS Post Response:";
            qDebug() << repl->readAll();
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

    QNetworkReply* reply = mgr->post(request, QByteArray("hello world"));
}


//void DropBox::upload(const QString filename)
//{
//    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));
//
//    request.setRawHeader(QByteArray("Authorization"), QByteArray/("Bearer /1v4q0_X7ptQAAAAAAAAAAXLkDScfpTbZWVk9TXX8Uy3DRsxRttFB34tQ41IGbEjl"));
//    QString dropboxArg = QString("{\"path\": \"/test\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": //false}").arg(filename);
//    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
//    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));
//
//    QFile* file = new QFile(filename);
//    file->open(QIODevice::ReadOnly);
//    QByteArray content = file->readAll();
//    request.setRawHeader(QByteArray("Content-Length"), QByteArray::number(content.size()));
//
//    QNetworkReply* reply = this->post(request, content);
//
//    QObject::connect(reply,
//        &QNetworkReply::finished,
//        [=](){
//        QString err = reply->errorString();
//        QString contents = QString::fromUtf8(reply->readAll());
//        qInfo() << "Error:" << err; });
//}