#include "test.h"
#include "ui_test.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <Employee.h>
#include <Queue.h>
#include <QInputDialog>
#include <LeaveApplication.h>
#include "LeaveApplication.h"

test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap px2(":/rec/image/man(1).png");
    ui->imageAdmin->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));

//    coding for data begins from here

    q.createQueue();

    LeaveApplication l1 = *new LeaveApplication("Fever","Yes","ok");
    Employee emp1 = *new Employee("Yeasin",4559,"Manager",true,90,l1,2);
    q.enqueue(emp1);
    ui->emp1_name->setText(QString::fromStdString(emp1.getName()));
    ui->emp1_per->setText(QString::number(emp1.getPerformanceStatus()));

    LeaveApplication l2 = *new LeaveApplication("","","");
    Employee emp2 = *new Employee("Raqib",3445,"Manager",true,85,l2,1);
    q.enqueue(emp2);
    ui->emp2_name->setText(QString::fromStdString(emp2.getName()));
    ui->emp2_per->setText(QString::number(emp2.getPerformanceStatus()));

    LeaveApplication l3 = *new LeaveApplication("Marrage","Yes","ok");
    Employee emp3 = *new Employee("Chisty",9000,"Manager",true,89,l3,7);
    q.enqueue(emp3);
    ui->emp3_name->setText(QString::fromStdString(emp3.getName()));
    ui->emp3_per->setText(QString::number(emp3.getPerformanceStatus()));

    LeaveApplication l4 = *new LeaveApplication("Sick","No","notok");
    Employee emp4 = *new Employee("Ridoy",4000,"Worker",false,60,l4,2);
    q.enqueue(emp4);
    ui->emp4_name->setText(QString::fromStdString(emp4.getName()));
    ui->emp4_per->setText(QString::number(emp4.getPerformanceStatus()));
    ui->lname->setText(QString::fromStdString(emp4.getName()));
    ui->lreason->setText(QString::fromStdString(emp4.getLeaveApplication().getName()));

    LeaveApplication l5 = *new LeaveApplication("","","");
    Employee emp5 = *new Employee("Hasib",4334,"Worker",false,70,l5,3);
    q.enqueue(emp5);
    ui->emp5_name->setText(QString::fromStdString(emp5.getName()));
    ui->emp5_per->setText(QString::number(emp5.getPerformanceStatus()));

    LeaveApplication l6 = *new LeaveApplication("","","");
    Employee emp6 = *new Employee("Himesh",2234,"Worker",false,68,l6,5);
    q.enqueue(emp6);
    ui->emp6_name->setText(QString::fromStdString(emp6.getName()));
    ui->emp6_per->setText(QString::number(emp6.getPerformanceStatus()));

    LeaveApplication l7 = *new LeaveApplication("Accident","No","notok");
    Employee emp7 = *new Employee("Kola",990,"Worker",true,88,l7,2);
    q.enqueue(emp7);
    ui->emp7_name->setText(QString::fromStdString(emp7.getName()));
    ui->emp7_per->setText(QString::number(emp7.getPerformanceStatus()));
    ui->lname_2->setText(QString::fromStdString(emp7.getName()));
    ui->lreason_2->setText(QString::fromStdString(emp7.getLeaveApplication().getName()));

    LeaveApplication l8 = *new LeaveApplication("Fever","No","notok");
    Employee emp8 = *new Employee("Latni",4355,"Worker",false,59,l8,2);
    q.enqueue(emp8);
    ui->emp8_name->setText(QString::fromStdString(emp8.getName()));
    ui->emp8_per->setText(QString::number(emp8.getPerformanceStatus()));
    ui->lname_3->setText(QString::fromStdString(emp8.getName()));
    ui->lreason_3->setText(QString::fromStdString(emp8.getLeaveApplication().getName()));

    LeaveApplication l9 = *new LeaveApplication("Fever","No","notok");
    Employee emp9 = *new Employee("Zidssa",1212,"Worker",true,90,l9,5);
    q.enqueue(emp9);
    ui->emp9_name->setText(QString::fromStdString(emp9.getName()));
    ui->emp9_per->setText(QString::number(emp9.getPerformanceStatus()));
    ui->lname_4->setText(QString::fromStdString(emp9.getName()));
    ui->lreason_4->setText(QString::fromStdString(emp9.getLeaveApplication().getName()));

    LeaveApplication l10 = *new LeaveApplication("","","");
    Employee emp10 = *new Employee("Harish",3321,"Worker",false,65,l10,6);
    q.enqueue(emp10);
    ui->emp10_name->setText(QString::fromStdString(emp10.getName()));
    ui->emp10_per->setText(QString::number(emp10.getPerformanceStatus()));

    LeaveApplication l11 = *new LeaveApplication("Fever","No","notok");
    Employee emp11 = *new Employee("Manison",5532,"Worker",false,60,l11,3);
    q.enqueue(emp11);
    ui->emp11_name->setText(QString::fromStdString(emp11.getName()));
    ui->emp11_per->setText(QString::number(emp11.getPerformanceStatus()));
    ui->lname_5->setText(QString::fromStdString(emp11.getName()));
    ui->lreason_5->setText(QString::fromStdString(emp11.getLeaveApplication().getName()));

    LeaveApplication l12 = *new LeaveApplication("Break Hands","No","notok");
    Employee emp12 = *new Employee("Karina",883,"Worker",false,90,l12,8);
    q.enqueue(emp12);
    ui->emp12_name->setText(QString::fromStdString(emp12.getName()));
    ui->emp12_per->setText(QString::number(emp12.getPerformanceStatus()));
    ui->lname_6->setText(QString::fromStdString(emp12.getName()));
    ui->lreason_6->setText(QString::fromStdString(emp12.getLeaveApplication().getName()));

    this->intializeDashboardValue();
}

void test::intializeDashboardValue(){
    //getting the number of employee
    int a = q.getTotalEmployee();
    ui->numberOfEmploye->setTextFormat(Qt::RichText);
    ui->numberOfEmploye->setText(QString::number(a));

    //setting all the promotion list
    Node * tmp = q.fptr;
    while(tmp){
        if(tmp->employee.getPromotionStatus()){
            ui->listWidget_promo->addItem(QString::fromStdString(tmp->employee.getName()));
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }

    //setting all the approve leave list
    tmp = q.fptr;
    while(tmp){
        if((tmp->employee.getLeaveApplication().getApplicationStatus().compare("ok") == 0)){
            ui->listWidget_approve->addItem(QString::fromStdString(tmp->employee.getName()));
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
//    setting the all recorded MC
    tmp = q.fptr;
    while(tmp){
        if((tmp->employee.getLeaveApplication().getMC().compare("Yes") == 0)){
            ui->listWidget_MC->addItem(QString::fromStdString(tmp->employee.getName()));
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
//       setting all the increase salary least
    tmp = q.fptr;
    while(tmp){
        if(tmp->employee.getPromotionStatus()){
            ui->listWidget_salary->addItem(QString::fromStdString(tmp->employee.getName()));
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }

//    setting all the retire list
    tmp = q.fptr;
    while(tmp){
            ui->listWidget_retire->addItem(QString::fromStdString(tmp->employee.getName()));
            tmp = tmp->next;
    }
//    settin the performance
    tmp = q.fptr;
    int manager=0,worker=0;
    int c1=0,c2=0;
    while(tmp){
        if(tmp->employee.getPosition().compare("Manager")== 0){
            manager += tmp->employee.getPerformanceStatus();
            tmp = tmp->next;
            c1++;
        }else {
            worker+= tmp->employee.getPerformanceStatus();
            tmp = tmp->next;
            c2++;
        }
    }
    ui->progressBar_2->setValue(manager/c1);
    ui->progressBar_3->setValue(worker/c2);
}
test::~test()
{
    delete ui;
}
//from page Dashboard to dashboard button
void test::on_searchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QPixmap px2(":/rec/image/man(1).png");
    ui->imageAdmin_2->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
    QPixmap px(":/rec/image/search.png");
    ui->searchsideimage->setPixmap(px.scaled(400,400,Qt::KeepAspectRatio));
}
//from page search to
void test::on_showPerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QPixmap px2(":/rec/image/man(1).png");
    ui->imageAdmin_3->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
    QPixmap px(":/rec/image/showperformance.png");
    ui->topImage->setPixmap(px.scaled(1100,170,Qt::IgnoreAspectRatio));
}
//from show Performance to
void test::on_approveLeaveButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QPixmap px2(":/rec/image/man(1).png");
    ui->adminImage->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
    QPixmap px(":/rec/image/2286286.png");
    ui->side_Image->setPixmap(px.scaled(350,350,Qt::IgnoreAspectRatio));
}
//from approve leave to
void test::on_generateRepButton_clicked()
{
    this->generateReport();
}

void test::generateReport(){
    QString fileName = QFileDialog::getSaveFileName(this,"Choose Where to Generate Report");
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
    text+= QString::number(q.getTotalEmployee());
    text+= "\n=======================================================================================\n\n";
    text+= "*************************************************************************************\n\n";
    text+= "Employee List : ";
    string a1 = q.getAllEMployee();
    text+= QString::fromStdString(a1);
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    text+= "Promoted Employee List : \n";
    Node * tmp = q.fptr;
    while(tmp){
        if(tmp->employee.getPromotionStatus()){
            text+= QString::fromStdString(tmp->employee.getName()) + "\n";
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    text+= "Increased Salary Employee List : \n";
    tmp = q.fptr;
    while(tmp){
        if(tmp->employee.getPromotionStatus()){
            text+= QString::fromStdString(tmp->employee.getName()) + "\n";
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    text+= "Recorded MC : \n";
    tmp = q.fptr;
    while(tmp){
        if((tmp->employee.getLeaveApplication().getMC().compare("Yes") == 0)){
            text+= QString::fromStdString(tmp->employee.getName()) + "\n";
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    text+= "Approved Leave Employee List : \n";
    tmp = q.fptr;
    while(tmp){
        if((tmp->employee.getLeaveApplication().getApplicationStatus().compare("ok") == 0)){
            text+= QString::fromStdString(tmp->employee.getName()) + "\n";
            tmp = tmp->next;
        }else
            tmp = tmp->next;
    }
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    text+= "Retired Employee List : \n";
    tmp = q.fptr;
    while(tmp){
            ui->listWidget_retire->addItem(QString::fromStdString(tmp->employee.getName()));
            text+= QString::fromStdString(tmp->employee.getName()) + "\n";
            tmp = tmp->next;
    }
    text+= "=======================================================================================\n\n";
    text+= "**************************************************************************************\n\n";
    out << text;
    file.flush();
    file.close();
    QMessageBox::information(this,"Success","Report is generated Successfully");
    this->setStyleSheet(tmpStyleSheet);
    }
    this->on_dashButton_clicked();
}
//from approve leave to exit
void test::on_exit_clicked()
{
    QApplication::quit();
}




//all dashboard buttons retirement
void test::on_pushButton_3_clicked()
{
    this->giveRetirement();
}

void test ::giveRetirement(){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Retirement Confirmition","Are You Sure, "
                                        "You want to give Retirement to the Vey First Employee?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        if(q.isEmpty()) {
            QMessageBox::warning(this,"Warning","No Employee Left");
            return;
        }
        q.dequeue();
        QMessageBox::information(this,"Successfull","The First Employee is Retired Successfully");
    }
    this->setStyleSheet(tmpStyleSheet);
    this->on_dashButton_clicked();
}

//show performnace from dashboard
void test::on_btnSHowPerformance_clicked(){this->on_showPerButton_clicked();}
//approve from dashboard
void test::on_approveLeaveButton_clicked(){this->on_approveLeaveButton_2_clicked();}
//generate report from dashboard
void test::on_generateReportButton_clicked(){this->on_generateRepButton_clicked();}
//exit from dashboard
void test::on_ExitButton_clicked(){this->on_exit_clicked();}



//search employee interface
//dashboard
void test::on_dashButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap px2(":/rec/image/man(1).png");
    ui->imageAdmin->setPixmap(px2.scaled(100,100,Qt::IgnoreAspectRatio));
    ui->numberOfEmploye->setText("");
    ui->listWidget_approve->clear();
    ui->listWidget_MC->clear();
    ui->listWidget_promo->clear();
    ui->listWidget_retire->clear();
    ui->listWidget_salary->clear();
    this->intializeDashboardValue();
}
//retirement
void test::on_retireButton_clicked(){this->on_pushButton_3_clicked();}
//showperformance
//above
//approve button
void test::on_pushButton_6_clicked(){this->on_approveLeaveButton_2_clicked();}
//generate report
void test::on_pushButton_7_clicked(){this->on_generateRepButton_clicked();}
//exit
void test::on_pushButton_9_clicked(){this->on_exit_clicked();}


//showperformance interface
//dashboard
void test::on_pushButton_2_clicked(){this->on_dashButton_clicked();}
//search employee
void test::on_pushButton_5_clicked(){this->on_searchButton_clicked();}
//retirement
void test::on_pushButton_10_clicked(){this->on_pushButton_3_clicked();}
//aprove
//above
//generate report
void test::on_pushButton_13_clicked(){this->on_generateRepButton_clicked();}
//exit button
void test::on_pushButton_14_clicked(){this->on_exit_clicked();}



//approve application interface
//dashboard
void test::on_pushButton_39_clicked(){this->on_dashButton_clicked();}
//search employee
void test::on_pushButton_40_clicked(){this->on_searchButton_clicked();}
//retirement
void test::on_pushButton_41_clicked(){this->on_pushButton_3_clicked();}
//show performance
void test::on_pushButton_42_clicked(){this->on_showPerButton_clicked();}


//above ar interface related code now coding related code
//coding related code
//coding related code
//coding related code
//coding related code
//search button clicked
void test::on_pushButton_8_clicked()
{
    this->searchEmployee();
}

void test::searchEmployee(){
    QString aa = ui->lineEdit->text();
    Employee temp = q.findEmployeeByName(aa.toStdString());
    ui->label_name->setText(QString::fromStdString(temp.getName()));
    ui->label_sal->setText(QString::number(temp.getSalary()));
    ui->label_posi->setText(QString::fromStdString(temp.getPosition()));
    ui->label_prom->setText((temp.getPerformanceStatus()) ? "True" : "false");
    ui->label_per->setText(QString::number(temp.getPerformanceStatus()));
    ui->label_lev->setText(QString::number(temp.getNumOfLeave()));
}
//all the increase salary
void test::on_pushButton_16_clicked()
{
    this->increaseSalary(ui->emp1_name);
}

void test::increaseSalary(QLabel *val){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox,QInputDialog{background-color: #EAEAEA;}");
    double a = QInputDialog::getDouble(this,"Salary","Input the new Salary");
    QString aa = val->text();
    Employee *emp = q.findEmployeeByRef(aa.toStdString());
    emp->setSalary(a);
    QMessageBox::information(this,"Successfull","The Salary is Updated for "+aa);
    this->setStyleSheet(tmpStyleSheet);
}

void test::on_makePromotion_clicked()
{
    this->givePromortion(ui->emp1_name);
}

void test::givePromortion(QLabel *val){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox,QInputDialog{background-color: #EAEAEA;}");
    QString aa = val->text();
    Employee *emp = q.findEmployeeByRef(aa.toStdString());
    bool promotion = true;
    emp->setPromotionStatus(promotion);
    QMessageBox::information(this,"Successfull","The Employee is Succsessfully promoted");
    this->setStyleSheet(tmpStyleSheet);
}



void test::on_pushButton_17_clicked()
{
    this->givePromortion(ui->emp4_name);
}


void test::on_pushButton_18_clicked()
{
    this->increaseSalary(ui->emp4_name);
}


void test::on_pushButton_23_clicked()
{
    this->givePromortion(ui->emp2_name);
}


void test::on_pushButton_31_clicked()
{
    this->givePromortion(ui->emp3_name);
}


void test::on_pushButton_25_clicked()
{
    this->givePromortion(ui->emp5_name);
}



void test::on_pushButton_33_clicked()
{
    this->givePromortion(ui->emp6_name);
}


void test::on_pushButton_19_clicked()
{
    this->givePromortion(ui->emp7_name);
}


void test::on_pushButton_27_clicked()
{
    this->givePromortion(ui->emp8_name);
}


void test::on_pushButton_35_clicked()
{
    this->givePromortion(ui->emp9_name);
}

void test::on_pushButton_21_clicked()
{
    this->givePromortion(ui->emp10_name);
}

void test::on_pushButton_29_clicked()
{
    this->givePromortion(ui->emp11_name);
}


void test::on_pushButton_37_clicked()
{
    this->givePromortion(ui->emp12_name);
}

void test::on_pushButton_24_clicked()
{
    this->increaseSalary(ui->emp2_name);
}


void test::on_pushButton_32_clicked()
{
    this->increaseSalary(ui->emp3_name);
}


void test::on_pushButton_26_clicked()
{
    this->increaseSalary(ui->emp5_name);
}


void test::on_pushButton_34_clicked()
{
    this->increaseSalary(ui->emp6_name);
}


void test::on_pushButton_20_clicked()
{
    this->increaseSalary(ui->emp7_name);
}


void test::on_pushButton_28_clicked()
{
    this->increaseSalary(ui->emp8_name);
}


void test::on_pushButton_36_clicked()
{
    this->increaseSalary(ui->emp9_name);
}


void test::on_pushButton_22_clicked()
{
    this->increaseSalary(ui->emp10_name);
}



void test::on_pushButton_30_clicked()
{
    this->increaseSalary(ui->emp11_name);
}


void test::on_pushButton_38_clicked()
{
    this->increaseSalary(ui->emp12_name);
}

void test::approveLeave(QLabel *val){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");
    QString aa = val->text();
    Employee *emp = q.findEmployeeByRef(aa.toStdString());
    emp->getLeave()->setApplicationStatus("ok");
    QMessageBox::information(this,"Success","Successfuly Approved Leave Appliation");
    this->setStyleSheet(tmpStyleSheet);
    this->intializeDashboardValue();
}

void test::RecordMC(QLabel *val){
    QString tmpStyleSheet=this->styleSheet();
    this->setStyleSheet("QMessageBox{background-color: #EAEAEA;}");
    QString aa = val->text();
    Employee *emp = q.findEmployeeByRef(aa.toStdString());
    emp->getLeave()->setMC("Yes");
    QMessageBox::information(this,"Success","Successfuly Recorded Medical Certificate");
    this->setStyleSheet(tmpStyleSheet);
    this->intializeDashboardValue();
}




void test::on_pushButton_46_clicked()
{
    this->approveLeave(ui->lname);
}



void test::on_pushButton_50_clicked()
{
    this->approveLeave(ui->lname_2);
}


void test::on_pushButton_54_clicked()
{
    this->approveLeave(ui->lname_3);
}



void test::on_pushButton_48_clicked()
{
    this->approveLeave(ui->lname_4);
}


void test::on_pushButton_52_clicked()
{
    this->approveLeave(ui->lname_5);
}



void test::on_pushButton_56_clicked()
{
    this->approveLeave(ui->lname_6);
}


void test::on_pushButton_47_clicked()
{
    this->RecordMC(ui->lname);
}


void test::on_pushButton_51_clicked()
{
    this->RecordMC(ui->lname_2);
}


void test::on_pushButton_55_clicked()
{
    this->RecordMC(ui->lname_3);
}


void test::on_pushButton_49_clicked()
{
    this->RecordMC(ui->lname_4);
}



void test::on_pushButton_53_clicked()
{
    this->RecordMC(ui->lname_5);
}



void test::on_pushButton_57_clicked()
{
    this->RecordMC(ui->lname_6);
}
