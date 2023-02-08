#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./trianglerenderer.h"

#include <QMainWindow>
#include <QVulkanWindow>
#include <QDockWidget>
#include "formhier.h"
#include "formlayer.h"
#include "formtop.h"
#include "forminfo.h"
#include "formmap.h"
#include "all_data.h"

//#include "mydataset.h"

class VulkanWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(VulkanWindow *w);
    ~MainWindow();



public slots:

    void inputStatus(QString text);
    void on_actionOpen_file_triggered();

//    void takeInfoValue(QString infoName, float value);

private slots:
    void on_pushButton_clicked();

signals:
    void sendInfoValue(float value);
    void sendSelectFileName(QString file_name);

public:
    QVulkanWindow *m_window;
    Ui::MainWindow *ui;
    QString statusText;
    FormHier *formHier;
    FormLayer *formLayer;
    FormTop *formTop;
    FormInfo *formInfo;
    FormMap *formMap;
    all_data *donut;
    QStringList split_data;


public:
    //MyDataSet *dataset = nullptr;

public:
    //void setMyDataSet(MyDataSet * dataset_){ this->dataset = dataset_;}

};



// Graphics output
class VulkanRenderer : public TriangleRenderer
{
public:
    VulkanRenderer(VulkanWindow *w);
};

// Graphics output -> Qt
class VulkanWindow : public QVulkanWindow
{
    Q_OBJECT

public:
    QVulkanWindowRenderer *createRenderer() override;


private:
    VulkanRenderer *m_renderer;
    void wheelEvent(QWheelEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    void keyReleaseEvent(QKeyEvent *) override;

    bool keyCtrl = false;
    bool keyShift = false;
    bool keyAlt = false;

    int m_mouseButton = 0;


    QPoint m_lastPos;


signals:
    void outputStatus(QString funcValue);
    void sendInfo(QString infoName, float value);
};



#endif // MAINWINDOW_H
