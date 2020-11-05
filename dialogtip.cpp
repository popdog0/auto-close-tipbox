#include "dialogtip.h"
#include "ui_dialogtip.h"
#include <QDebug>

DialogTip::DialogTip(QWidget *parent,QString strTip,int iTime) :
    QDialog(parent)
{
    lbTip = new QLabel(this);
    lbTip->setGeometry(QRect(70, 20, 241, 71));
    lbTip->setAlignment(Qt::AlignCenter);
    lbTip->setWordWrap(true);
    pbOk = new QPushButton(this);
    pbOk->setGeometry(QRect(145, 110, 91, 31));
    lbIcon = new QLabel(this);
    lbIcon->setGeometry(QRect(10, 30, 51, 51));
    lbIcon->setPixmap(QPixmap(":/new/prefix1/images/info.png"));
    lbIcon->setScaledContents(false);

    if(iTime<0)
        lbIcon->setPixmap(QPixmap(":/new/prefix1/images/error.png"));
    lbTip->setText(strTip);
    iTimeOut=abs(iTime);
    if(iTimeOut > 0)
    {
        QString str;
        str.sprintf("关闭(%d)",iTimeOut);
        pbOk->setText(str);

        //定时器
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->start(1000);
    }
    else
        pbOk->setText("关闭");

    if(strTip.indexOf('\n')>0)
        lbTip->setAlignment(Qt::AlignLeft);
    else
        lbTip->setAlignment(Qt::AlignCenter);

    connect(pbOk,SIGNAL(clicked(bool)),this,SLOT(on_pbOk_clicked()));
}

DialogTip::~DialogTip()
{

}

void DialogTip::onTimer()
{
    iTimeOut --;
    if(iTimeOut > 0)
    {
        QString str;
        str.sprintf("关闭(%d)",iTimeOut);
        pbOk->setText(str);
    }
    else
        this->close();
}

void DialogTip::on_pbOk_clicked()
{
    this->close();
}
