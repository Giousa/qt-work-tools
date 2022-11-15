#include "webwidget.h"
#include "ui_webwidget.h"
#include <QDebug>
#include <QtWebEngineWidgets>
#include "customwebview.h"

WebWidget::WebWidget(QWidget *parent,QString toolName, QString toolURL) :
    QWidget(parent),
    ui(new Ui::WebWidget)
{
    ui->setupUi(this);

    qDebug() << "web页面: " << toolName << ", 链接： " << toolURL;
    if(toolName.isEmpty() || toolURL.isEmpty()){
        this->hide();
    }

    this->setWindowTitle(toolName);

//    QNetworkProxyFactory::setUseSystemConfiguration(false);

//    QWebEngineView *view = new QWebEngineView;
    CustomWebView *view = new CustomWebView(this);
    ui->gridLayout->addWidget(view);
//    QUrl url = QUrl::fromUserInput(toolURL);
    view->load(toolURL);


}

WebWidget::~WebWidget()
{
    delete ui;
}
