#include "PostRequest.h"

PostRequest::PostRequest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QUrl url = QUrl("https://content.dropboxapi.com/2/files/upload");

    QNetworkAccessManager* mgr = new QNetworkAccessManager();
}
