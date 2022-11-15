#ifndef WEBWIDGET_H
#define WEBWIDGET_H

#include <QWidget>

namespace Ui {
class WebWidget;
}

class WebWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WebWidget(QWidget *parent = nullptr,QString toolName = NULL,QString toolURL = NULL);
    ~WebWidget();

private:
    Ui::WebWidget *ui;
};

#endif // WEBWIDGET_H
