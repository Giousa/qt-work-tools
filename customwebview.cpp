#include "customwebview.h"


CustomWebView::CustomWebView(QWidget *parent): QWebEngineView{parent}
{
    Q_UNUSED(parent);
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(this->page(),&QWebEnginePage::linkHovered,this,&CustomWebView::on_linkHovered);

    //这里实现屏幕最大化和最小化
    this->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled,true);
    connect(this->page(),&QWebEnginePage::fullScreenRequested,this,[=](QWebEngineFullScreenRequest pageRequeset)
    {
        pageRequeset.accept();
    });
}

CustomWebView::~CustomWebView()
{
    qDebug() << "虚函数...";
}


QWebEngineView *CustomWebView::createWindow(QWebEnginePage::WebWindowType type)
{
    Q_UNUSED(type);
    //加载连接地址
    if(!m_url.isEmpty())
    {
        this->load(m_url);
        emit QEvent::ChildPolished;   //重新加载页面时，手动触发一个ChildPolished事件
    }
    return nullptr;
}

void CustomWebView::on_linkHovered(const QString &url)
{
    //获取视图里点击的链接地址
    m_url.setUrl(url);
}
