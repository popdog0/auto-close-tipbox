#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tooltip.showInfo("这是一个提示信息：\nthis is a message\n0 ~ 100",QCursor::pos());
}

void MainWindow::on_pushButton_2_clicked()
{
    tooltip.showError("这是一个错误信息：\nthis is a message\n0 ~ 100",QCursor::pos());
}

void MainWindow::on_pushButton_3_clicked()
{
    DialogTip tip(this,"这是一个提示信息!",5);
    tip.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    DialogTip tip(this,"这是一个错误信息!",-5);
    tip.exec();
}
