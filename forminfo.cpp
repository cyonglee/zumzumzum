#include "forminfo.h"
#include "ui_forminfo.h"
#include <QDebug>

FormInfo::FormInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormInfo)
{
    ui->setupUi(this);
}

void FormInfo::setPointX(float value)
{
    qDebug()<<"setPointX";
    pointX = pointX + value;
    ui->pointX->setText(QString::number(pointX));
}

FormInfo::~FormInfo()
{
    delete ui;
}
