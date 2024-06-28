/********************************************************************************
** Form generated from reading UI file 'webwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBWIDGET_H
#define UI_WEBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;

    void setupUi(QWidget *WebWidget)
    {
        if (WebWidget->objectName().isEmpty())
            WebWidget->setObjectName("WebWidget");
        WebWidget->resize(1000, 600);
        horizontalLayout = new QHBoxLayout(WebWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        horizontalLayout->addLayout(gridLayout);


        retranslateUi(WebWidget);

        QMetaObject::connectSlotsByName(WebWidget);
    } // setupUi

    void retranslateUi(QWidget *WebWidget)
    {
        WebWidget->setWindowTitle(QCoreApplication::translate("WebWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WebWidget: public Ui_WebWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBWIDGET_H
