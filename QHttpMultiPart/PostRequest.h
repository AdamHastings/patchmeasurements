#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PostRequest.h"

class PostRequest : public QMainWindow
{
    Q_OBJECT

public:
    PostRequest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QHttpMultiPartClass ui;
};
