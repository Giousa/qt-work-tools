#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int offsetNum = 7;

    void parseConfigFile(QString path);

private slots:
    void on_btnSelectFile_clicked();

    void on_btnRefresh_clicked();

    void buttonClicked(QString toolName,QString toolURL);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
