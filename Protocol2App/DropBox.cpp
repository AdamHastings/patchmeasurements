#include "DropBox.h"
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QString>
#include <QNetworkReply>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>


#include "Protocol2App.h"


DropBox::DropBox()
{
}

DropBox::~DropBox()
{
}


void DropBox::upload(QString contents, QString filename) {
    
    QString directory = Protocol2App::getUNI();

    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            qDebug() << repl->readAll();
        });

    QNetworkRequest request(QUrl("https://content.dropboxapi.com/2/files/upload"));

 
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer qHsc0jnrT4EAAAAAAAAAAeHJyK46BY6Ayaon3yz_8A4FWkapt_RTku2PZf7vFPUu"));

    QString dropboxArg = QString("{\"path\": \"/" + directory + "/" + filename + ".txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": true,\"strict_conflict\": false}");

#ifdef QT_DEBUG
    dropboxArg = QString("{\"path\": \"/ " + directory + "/" + filename + ".txt\",\"mode\": \"overwrite\",\"autorename\": false,\"mute\": true,\"strict_conflict\": false}");
#endif


    request.setRawHeader(QByteArray("Dropbox-API-Arg"), dropboxArg.toUtf8());

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/octet-stream"));

    QNetworkReply* reply = mgr->post(request, QByteArray(contents.toStdString().c_str()));
}


bool DropBox::uploadSuccessful(QString uni, QString filename) {
    QNetworkAccessManager* mgr = new QNetworkAccessManager();

    QJsonObject json_reply;

    QObject::connect(mgr, &QNetworkAccessManager::finished,
        [&](QNetworkReply* repl) {
            json_reply = QJsonDocument::fromJson(repl->readAll()).object();
        });

    QNetworkRequest request(QUrl("https://api.dropboxapi.com/2/files/get_metadata"));

    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer qHsc0jnrT4EAAAAAAAAAAeHJyK46BY6Ayaon3yz_8A4FWkapt_RTku2PZf7vFPUu"));

    request.setRawHeader(QByteArray("Content-Type"), QByteArray("application/json"));

    QByteArray jsonString = "{\"path\": \"/" + uni.toUtf8() + "/" + filename.toUtf8() + "\"}";

    qDebug() << "jsonString: " << jsonString;

    QNetworkReply* reply = mgr->post(request, jsonString);

    QEventLoop loop;
    loop.connect(mgr, SIGNAL(finished(QNetworkReply*)), SLOT(quit()));
    loop.exec();

    qDebug("================ reply ================");
    qDebug() << json_reply;
    qDebug() << json_reply.value("name");

    if (json_reply.value("name").toString() == QString(filename)) {
        return true;
    }
    else {
        return false;
    }
}
