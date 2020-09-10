#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>

class DropBox : public QNetworkAccessManager
{
    Q_OBJECT

public:
    explicit DropBox(QObject* parent = nullptr) : QNetworkAccessManager(parent) {}
    void upload(const QString filename);

signals:

public slots:

private:

};
