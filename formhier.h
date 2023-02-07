#ifndef FORMHIER_H
#define FORMHIER_H

#include <QDialog>
#include "mydataset.h"
//#include "mainwindow.h"

namespace Ui {
class FormHier;
}

class FormHier : public QDialog
{
    Q_OBJECT

public slots:
    void ReceiveSplitData();

public:
    FormHier(QWidget *parent = nullptr);
    ~FormHier();
    Ui::FormHier *ui;

public:
    //MyDataSet *dataset = nullptr;

public:
    //void setMyDataSet(MyDataSet * dataset_){ this->dataset = dataset_;}
    //void testMyData();

};

#endif // FORMHIER_H
