#include "dropbox.h"

#include <QFile>
#include <QNetworkReply>

void DropBox::upload(const QString filename)
{
    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer 1v4q0_X7ptQAAAAAAAAAAXLkDScfpTbZWVk9TXX8Uy3DRsxRttFB34tQ41IGbEjl"));
    QString dropboxArg = QString("{\"path\": \"/test\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}").arg(filename);
    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());
    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QFile* file = new QFile(filename);
    file->open(QIODevice::ReadOnly);
    QByteArray content = file->readAll();
    request.setRawHeader(QByteArray("Content-Length"), QByteArray::number(content.size()));

    QNetworkReply* reply = this->post(request, content);

    QObject::connect(reply,
        &QNetworkReply::finished,
        [=](){
        QString err = reply->errorString();
        QString contents = QString::fromUtf8(reply->readAll());
        qInfo() << "Error:" << err; });
}