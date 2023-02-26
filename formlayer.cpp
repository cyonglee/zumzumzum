#include "formlayer.h"
#include "ui_formlayer.h"



FormLayer::FormLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormLayer)
{
    ui->setupUi(this);
    QStringList defalutTableHeader;
    defalutTableHeader << "" << "color" << "LayerName" << "LayerNum" << "LayerType";

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnWidth(0,12);
    ui->tableWidget->setColumnWidth(1,80);
    ui->tableWidget->setColumnWidth(2,80);
    ui->tableWidget->setHorizontalHeaderLabels(defalutTableHeader);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#404040;color:#FFFFFF;}");


}

FormLayer::~FormLayer()
{
    delete ui;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief FormLayer::ReceiveSplitData
/// \param row
/// \param column
/// \param inputDataVector
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FormLayer::ReceiveSplitData(int row, int column, const QVector <QVector <QString>> &inputDataVector)
{
// QTableWidget 에서 QStringList 로만 받기때문에 자료형변환
    QStringList vectorTOqstringlist;
    QStringList vectorTOqstringlistHoriLabels;
    QStringList vectorTOqstringcolorlist;
    QString LayerColorRed;
    QString LayerColorGreen;
    QString LayerColorBlue;
    QString LayerColorText;
    vectorTOqstringlistHoriLabels << " ";

// QTableWidget 크기 설정
    ui->tableWidget->setColumnCount(column-1);
    ui->tableWidget->setRowCount(row-1);

// Table Header Font size/bold change
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    font.setPointSize(10);
    ui->tableWidget->horizontalHeader()->setFont(font);

// Table 채우기
    for (int i=0; i<row ; i++)
    {
        // table value 채우기
        for (int j=0; j<(column-3) ; j++)
        {
            vectorTOqstringlist << inputDataVector.value(i+1).value(j);
//            vectorTOqstringlistHoriLabels << inputDataVector.value(0).value(j+1);
            ui->tableWidget->setItem(i,j+2,new QTableWidgetItem(vectorTOqstringlist[i*(column-3)+j]));
            qDebug() << "column : " << column;
        }

        // checkbox 채우기
//        QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
//        checkBoxItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
//        checkBoxItem->setCheckState(Qt::Checked);
//        ui->tableWidget->setItem(i,0,checkBoxItem);
//        ui->tableWidget->setFocusPolicy(Qt::NoFocus);


        QCheckBox *checkBoxItem = new QCheckBox();
        checkBoxItem->setCheckState(Qt::Checked);
        QWidget *checkboxWidget = new QWidget();
        QHBoxLayout *checkboxLayout = new QHBoxLayout(checkboxWidget);
        checkboxLayout->addWidget(checkBoxItem);
        checkboxLayout->setAlignment(Qt::AlignCenter);
        checkboxLayout->setContentsMargins(0,0,0,0);
        checkboxWidget->setLayout(checkboxLayout);
        ui->tableWidget->setCellWidget(i,0,checkboxWidget);

        QWidget *widget = ui->tableWidget->cellWidget(i, 0);
        QCheckBox *checkboxInTable = widget->findChild<QCheckBox *>();
        QObject::connect(checkboxInTable, SIGNAL(stateChanged(int)), this, SLOT(tableWidget_checkBoxChanged()));

        // Layer color rgb value
        LayerColorRed = inputDataVector.value(i+1).value(3);
        LayerColorGreen = inputDataVector.value(i+1).value(4);
        LayerColorBlue = inputDataVector.value(i+1).value(5);

        LayerColorText = "background-color: rgb(" + LayerColorRed;
        LayerColorText = LayerColorText + "," + LayerColorGreen + "," + LayerColorBlue + ")";

        // color pushbutton 채우기
        QPushButton *colorbutton = new QPushButton();
        colorbutton->setStyleSheet(LayerColorText);
        ui->tableWidget->setCellWidget(i,1,colorbutton);
        QObject::connect(colorbutton, SIGNAL(clicked()), this, SLOT(on_colorbutton_clicked()));
    }
    ui->tableWidget->setHorizontalHeaderLabels(vectorTOqstringlistHoriLabels);
//    ui->tableWidget->resizeColumnsToContents();

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief FormLayer::on_tableWidget_itemChanged
/// \param checkBoxItem
/// description : checkbox 선택에 따라 Layer On/Off mainwindow status 창에 출력
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FormLayer::tableWidget_checkBoxChanged()
{
    qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxzzzzzzzzzzzzzzzzzzzzz";
    //ui->tableWidget->connect
    QCheckBox *checkboxInTable = qobject_cast<QCheckBox*>(sender());
    if (!checkboxInTable)
        return;


    QPoint checkboxPos = checkboxInTable->mapTo(ui->tableWidget, QPoint(0, 0));

    int row = ui->tableWidget->indexAt(checkboxPos).row();
    int column = ui->tableWidget->indexAt(checkboxPos).column();

    if (checkboxInTable->isChecked()) {
        qDebug() << "Checkbox at row" << row << "column" << column << "is checked.";
    } else {
        qDebug() << "Checkbox at row" << row << "column" << column << "is unchecked.";
    }

}

void FormLayer::on_colorbutton_clicked()
{
    QString LayerColorname;
    QString LayerColorText;
    int colorbuttonRow = ui->tableWidget->currentRow();

    QColor color = QColorDialog::getColor(Qt::yellow, this);

    LayerColorname = color.name();
    LayerColorText = "background-color: " + LayerColorname;

//    qDebug() << ui->tableWidget->cellWidget(colorbuttonRow,1);

    ui->tableWidget->cellWidget(colorbuttonRow,1)->setStyleSheet(LayerColorText);

}

