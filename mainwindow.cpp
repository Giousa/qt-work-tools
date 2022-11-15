#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QDebug>
#include <QSettings>
#include "webwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings setting("STJK_WORK","TOOLS");
    QString storePath = setting.value("TOOL_CONFIG_PATH","/").toString();
    if(!storePath.isEmpty()){
        ui->lineEdit->setText(storePath);
        parseConfigFile(storePath);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSelectFile_clicked()
{
    QSettings setting("STJK_WORK","TOOLS");
    QString storePath = setting.value("TOOL_CONFIG_PATH","/").toString();
    QString path = QFileDialog::getOpenFileName(this,"打开文件",storePath);
    if(path.isEmpty()){
        return;
    }
    ui->lineEdit->setText(path);
    setting.setValue("TOOL_CONFIG_PATH",path);

    parseConfigFile(path);
}


void MainWindow::on_btnRefresh_clicked()
{
    parseConfigFile(ui->lineEdit->text());
}


void MainWindow::parseConfigFile(QString path)
{
    if(path.isEmpty()){
        return;
    }


    //读取文件
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)){
         qDebug()<<"文件打开失败!";
        return;
    }

    //将文件内容读取到数组中
    QByteArray data = file.readAll();
    file.close();

    //解析
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError){
        qDebug()<<"文件配置错误";
        return;
    }

    QJsonArray toolArray = doc.array();
    qDebug() << "toolArray:  " << toolArray;

    for (int i = 0;i < toolArray.size() ;i++ ) {
        QJsonObject object = toolArray.at(i).toObject();
        QString toolName = object.take("toolName").toString();
        QString toolURL = object.take("toolURL").toString();

        qDebug() << "toolName: " << toolName << ",toolURL: " << toolURL;

        QPushButton * btn = new QPushButton(toolName,this);
        btn->setMaximumSize(160, 40);

        int offset = i/offsetNum;
        qDebug() << "offset = " << offset;
        ui->gridLayout->addWidget(btn,offset,i-offsetNum*offset);

        connect(btn,&QPushButton::clicked,this,[=](){buttonClicked(toolName,toolURL);});

    }

}


void MainWindow::buttonClicked(QString toolName, QString toolURL)
{
    qDebug() << "点击： " << toolName << ", 链接： " << toolURL;

    WebWidget *widget = new WebWidget(this,toolName,toolURL);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget->setWindowFlag(Qt::Window,true);
    widget->show();
}


