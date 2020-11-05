#ifndef CTOOLTIP_H
#define CTOOLTIP_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#pragma execution_character_set("utf-8")

class CToolTip : public QWidget
{
    Q_OBJECT
public:
    explicit CToolTip(QWidget *parent = 0);
    void showInfo(QString info, QPoint point);
    void showError(QString info, QPoint point);
signals:

private slots:
    void onTimer();
private:
    QPixmap pixInfo,pixErr;
    QLabel *labelIcon;
    QLabel *labelInfo;
    QLabel *labelCT;

    QVBoxLayout *verlayout;
    QHBoxLayout *horLayout;
    QTimer *timer;
    int timerCnt;
    QGroupBox *groupBox;

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // CTOOLTIP_H
