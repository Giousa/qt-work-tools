#ifndef CUSTOMWEBVIEW_H
#define CUSTOMWEBVIEW_H

#include <QObject>
#include <QWidget>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QUrl>
#include <QMouseEvent>
#include <QApplication>
#include <QWebEngineSettings>
#include <QWebEngineFullScreenRequest>
#include <QDebug>

class CustomWebView : public QWebEngineView
{
    Q_OBJECT

public:
    explicit CustomWebView(QWidget *parent = nullptr);
    ~CustomWebView();

protected:
    QWebEngineView* createWindow(QWebEnginePage::WebWindowType type);

private slots:
    void on_linkHovered(const QString& url);

private:
    QUrl m_url;

};

#endif // CUSTOMWEBVIEW_H
