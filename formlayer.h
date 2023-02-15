#ifndef FORMLAYER_H
#define FORMLAYER_H

#include <QDialog>
#include <QtWidgets/QCheckBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>

namespace Ui {
class FormLayer;
}

class FormLayer : public QDialog
{
    Q_OBJECT

public slots:
    void ReceiveSplitData(int row, int column, const QVector <QVector <QString>> &inputDataVector);

public:
    explicit FormLayer(QWidget *parent = nullptr);
    ~FormLayer();
//    QTableWidgetItem *checkBoxItem[3];


private slots:
    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::FormLayer *ui;
};

#endif // FORMLAYER_H
