#include "webwidget.h"
#include "ui_webwidget.h"
#include <QDebug>
#include <QtWebEngineWidgets/QWebEngineView>

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

    QWebEngineView *view = new QWebEngineView;
    QUrl url = QUrl::fromUserInput(toolURL);
    view->load(url);
    ui->gridLayout->addWidget(view);

}

WebWidget::~WebWidget()
{
    delete ui;
}
