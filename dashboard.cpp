#include "dashboard.h"
#include "ui_dashboard.h"
#include "searchemployee.h"
#include "showperformance.h"
#include "approveleave.h"
#include <QPalette>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->listWidget_6->addItem("New Item Added");
    QPixmap px2(":/rec/image/man(1).png");
    ui->imageAdmin->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_2_clicked()
{
    hide();
    searchEmp = new searchEmployee(this);
    searchEmp->setFixedWidth(1360);
    searchEmp->setFixedHeight(700);
    searchEmp->show();
}

void Dashboard::on_pushButton_3_clicked()
{
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");


    QMessageBox::StandardButton reply = QMessageBox::question(this,"Retirement Confirmition","Are You Sure, "
                                        "You want to give Retirement to the Vey First EMployee",
                                        QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){}
    this->setStyleSheet(tmpStyleSheet);

}

void Dashboard::on_btnSHowPerformance_clicked()
{
    hide();
    performance = new showPerformance(this);
    performance->setFixedWidth(1360);
    performance->setFixedHeight(700);
    performance->show();
}


void Dashboard::on_ExitButton_clicked()
{
    QApplication::quit();
}

void Dashboard::on_approveLeaveButton_clicked()
{
    hide();
    approve = new approveLeave(this);
    approve->setFixedWidth(1360);
    approve->setFixedHeight(700);
    approve->show();
}

void Dashboard::on_generateReportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open File");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");
    QMessageBox::warning(this,"Warning","File Not Opened");
    this->setStyleSheet(tmpStyleSheet);
    return;
    }else{
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");
    QTextStream out(&file);
    QString text = "";
    text+= "***********************************Employee Report***********************************\n\n";
    text+= "Total Number of EMployees : ";
    text+= "*************************************************************************************\n\n";
    text+= "Employee List : ";
    text+= "**************************************************************************************\n\n";
    text+= "Promoted Employee List : ";
    text+= "**************************************************************************************\n\n";
    text+= "Increased Salary Employee List : ";
    text+= "**************************************************************************************\n\n";
    text+= "Recorded MC : ";
    text+= "**************************************************************************************\n\n";
    text+= "Approved Leave Employee List : ";
    text+= "**************************************************************************************\n\n";
    text+= "Promoted Employee List : ";
    text+= "**************************************************************************************\n\n";
    text+= "Retired Employee List : ";
    text+= "**************************************************************************************\n\n";
    out << text;
    file.flush();
    file.close();
    QMessageBox::information(this,"Success","Report is generated Successfully");
    this->setStyleSheet(tmpStyleSheet);
    }
}
