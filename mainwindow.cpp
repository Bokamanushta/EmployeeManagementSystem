#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include <QPixmap>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //setting the background
    QPixmap bkgnd(":/rec/image/home.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!(ui->input_password->text() == "admin")) ui->label_status->setText("Incorrect Password");
    else{
        ui->label_status->setText("");
        hide();
        win = new test(this);
        win->setFixedWidth(1360);
        win->setFixedHeight(700);
        win->show();

    }
}
