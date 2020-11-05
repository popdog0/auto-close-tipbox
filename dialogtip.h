#ifndef DIALOGTIP_H
#define DIALOGTIP_H

#include <QDialog>
#include <QLabel>
#include <QTimer>
#pragma execution_character_set("utf-8")

namespace Ui {
class DialogTip;
}

class DialogTip : public QDialog
{
    Q_OBJECT
    
public:
    //iTime=3 默认延时关闭时间，=0 不自动关闭，
    //>0 显示成功图标，并延时自动关闭
    //<0 显示错误图标，并延时自动关闭
    explicit DialogTip(QWidget *parent = 0,QString strTip="",int iTime=2);
    ~DialogTip();
    
private slots:
    void onTimer();
    void on_pbOk_clicked();

private:
    QLabel *lbTip;
    QPushButton *pbOk;
    QLabel *lbIcon;

    QTimer *timer;
    int iTimeOut;

};

#endif // DIALOGTIP_H
