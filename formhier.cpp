#include "formhier.h"
#include "ui_formhier.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QDebug>


FormHier::FormHier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormHier)
{
    ui->setupUi(this);
}

FormHier::~FormHier()
{
    delete ui;
}

//void FormHier::testMyData(){
//    this->dataset->split_datas[0][0] = QString("No, I'm not fool!!!");
//}

void FormHier::ReceiveSplitData()
{
    qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxx";




    ui->tableWidget->setColumnCount(20);
    //ui->tableWidget->setHorizontalHeaderLabels(split_data[100][100]);



    //qDebug() << split_data;

}
