#include "approveleave.h"
#include "ui_approveleave.h"

approveLeave::approveLeave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::approveLeave)
{
    ui->setupUi(this);
    QPixmap px2(":/rec/image/man(1).png");
    ui->adminImage->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
    QPixmap px(":/rec/image/LeaveForApplication.png");
    ui->side_Image->setPixmap(px.scaled(400,500,Qt::IgnoreAspectRatio));
}

approveLeave::~approveLeave()
{
    delete ui;
}
