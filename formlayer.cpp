#include "formlayer.h"
#include "ui_formlayer.h"
#include <QDebug>



FormLayer::FormLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormLayer)
{
    ui->setupUi(this);
    QStringList defalutTableHeader;
    defalutTableHeader << "" << "LayerName" << "LayerNum" << "LayerType";

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnWidth(0,15);
    ui->tableWidget->setColumnWidth(1,80);
    ui->tableWidget->setColumnWidth(2,80);
    ui->tableWidget->setHorizontalHeaderLabels(defalutTableHeader);

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#404040;color:#FFFFFF;}");



}

FormLayer::~FormLayer()
{
    delete ui;
}


void FormLayer::ReceiveSplitData(int row, int column, const QVector <QVector <QString>> &inputDataVector)
{
//    qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxx";
//    qDebug() << "row" << row;
//    qDebug() << "column" << column;
//    qDebug() << "1st" << inputDataVector.value(0);
//    qDebug() << "2nd" << inputDataVector.value(1);
//    qDebug() << "3rd" << inputDataVector.value(2);
//    qDebug() << "1st_1st" << inputDataVector.value(0).value(0);



// QTableWidget 에서 QStringList 로만 받기때문에 자료형변환
    QStringList vectorTOqstringlist;
    QStringList vectorTOqstringlistHoriLabels;
    vectorTOqstringlistHoriLabels << " ";

// QTableWidget 크기 설정
    ui->tableWidget->setColumnCount(column-2);
    ui->tableWidget->setRowCount(row);

// Table Header Font size/bold change
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    font.setPointSize(10);
    ui->tableWidget->horizontalHeader()->setFont(font);


    // Table 채우기
    for (int i=0; i<row ; i++)
    {
        // checkbox 채우기
        QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
        checkBoxItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkBoxItem->setCheckState(Qt::Checked);

//        QTableWidget::itemC


        ui->tableWidget->setItem(i,0,checkBoxItem);

        for (int j=0; j<(column-3) ; j++)
        {
            vectorTOqstringlist << inputDataVector.value(i+1).value(j);
            vectorTOqstringlistHoriLabels << inputDataVector.value(0).value(j);
            ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(vectorTOqstringlist[i*(column-3)+j]));
        }

    }

    ui->tableWidget->setHorizontalHeaderLabels(vectorTOqstringlistHoriLabels);


    QObject::connect(this,SIGNAL(&QTableWidget::itemChaged),this,SLOT(on_tableWidget_itemChanged));

}





void FormLayer::on_tableWidget_itemChanged(QTableWidgetItem *checkBoxItem)
{
    int clickedRow = checkBoxItem->row();

    qDebug() << clickedRow;

    QTableWidgetItem *item = ui->tableWidget->item(clickedRow,1);

    if (item != nullptr) {
       QString cellValue = item->text();
        qDebug() << "Cell value at (1, 1):" << cellValue;
    } else {
        qDebug() << "No item at (1, 1)";
    }


}
