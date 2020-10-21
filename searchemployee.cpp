#include "searchemployee.h"
#include "ui_searchemployee.h"
#include <qpixmap.h>
#include "dashboard.h"
#include "approveleave.h"
#include "showperformance.h"
#include <QMessageBox>

searchEmployee::searchEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchEmployee)
{
    ui->setupUi(this);
    QPixmap px(":/rec/image/search.png");
    ui->img->setPixmap(px.scaled(400,400,Qt::KeepAspectRatio));
    QPixmap px2(":/rec/image/man(1).png");
    ui->adminImage->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
}

searchEmployee::~searchEmployee()
{
    delete ui;
}

void searchEmployee::on_dashButton_clicked()
{
    hide();
    Dashboard *dash = new Dashboard(this);
    dash->setFixedWidth(1360);
    dash->setFixedHeight(700);
    dash->show();
}

void searchEmployee::on_retireButton_clicked()
{
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");


    QMessageBox::StandardButton reply = QMessageBox::question(this,"Retirement Confirmition","Are You Sure, "
                                        "You want to give Retirement to the Vey First EMployee",
                                        QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){}
    this->setStyleSheet(tmpStyleSheet);

}
