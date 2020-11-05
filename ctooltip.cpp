#include "ctooltip.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

CToolTip::CToolTip(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint|Qt::SubWindow|Qt::WindowStaysOnTopHint);
    this->resize(200, 100); ;

    pixInfo.load(":/new/prefix1/images/info.png");
    pixErr.load(":/new/prefix1/images/error.png");
    pixErr=pixErr.scaled(32,32);
    pixInfo=pixInfo.scaled(32,32);

    this->setObjectName("CToolTip");
    this->setStyleSheet("QWidget#CToolTip {border: 2px solid #111111; background-color: white;}");

    groupBox = new QGroupBox(this);
    groupBox->setGeometry(1, 1, 198, 98);
    groupBox->setTitle("");

    labelIcon = new QLabel(groupBox);
    labelInfo = new QLabel(groupBox);
    labelCT = new QLabel(groupBox);
    labelCT->setAlignment(Qt::AlignRight);
    labelInfo->setWordWrap(true);

    verlayout = new QVBoxLayout();
    verlayout->setContentsMargins(0, 0, 0, 0);
    verlayout->addWidget(labelInfo,4, Qt::AlignTop);
    verlayout->addWidget(labelCT,1);

    horLayout = new QHBoxLayout(groupBox);
    horLayout->setContentsMargins(10, 10, 10, 10);
    horLayout->addWidget(labelIcon, 1, Qt::AlignTop);
    horLayout->addLayout(verlayout, 4);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    timerCnt=0;
}

// 显示ToolTip消息
void CToolTip::showInfo(QString info, QPoint point) {
    labelIcon->setPixmap(pixInfo);
    labelInfo->setText(info);

    // 重新定义CToolTip的坐标
    int rectX;
    int rectY;
    if (point.rx() < 200) {
        rectX = point.rx() + 10;
    } else {
        rectX = point.rx() - 240;
    }
    rectY =  point.ry();
    move(QPoint(rectX, rectY));

    timerCnt=5;
    onTimer();
    timer->start(1000);
    QWidget::show();
}

// 显示ToolTip消息
void CToolTip::showError(QString info, QPoint point) {
    labelIcon->setPixmap(pixErr);
    labelInfo->setText(info);

    // 重新定义CToolTip的坐标
    int rectX;
    int rectY;
    if (point.rx() < 200) {
        rectX = point.rx() + 10;
    } else {
        rectX = point.rx() - 240;
    }
    rectY =  point.ry();
    move(QPoint(rectX, rectY));

    timerCnt=5;
    onTimer();
    timer->start(1000);
    QWidget::show();
}

// 鼠标点击事件时，让界面隐藏掉
void CToolTip::mouseReleaseEvent(QMouseEvent *ev) {
    hide();
}

void CToolTip::onTimer() {
    if(timerCnt==0)
    {
        hide();
        timer->stop();
    }
    else if(timerCnt>0)
    {
        labelCT->setText(QString("[ %1 ]").arg(timerCnt));
        timerCnt--;
    }
    else
        return;
}
