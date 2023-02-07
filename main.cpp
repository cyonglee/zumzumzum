#include "mainwindow.h"

#include <QApplication>
#include <QVulkanInstance>
#include "mydataset.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QVulkanInstance inst;

#ifndef Q_OS_ANDROID
    inst.setLayers(QByteArrayList() << "VK_LAYER_LUNARG_standard_validation");
#else
    inst.setLayers(QByteArrayList()
                   << "VK_LAYER_GOOGLE_threading"
                   << "VK_LAYER_LUNARG_parameter_validation"
                   << "VK_LAYER_LUNARG_object_tracker"
                   << "VK_LAYER_LUNARG_core_validation"
                   << "VK_LAYER_LUNARG_image"
                   << "VK_LAYER_LUNARG_swapchain"
                   << "VK_LAYER_GOOGLE_unique_objects");
#endif

    if (!inst.create())
        qFatal("Failed to create Vulkan instance: %d", inst.errorCode());

    VulkanWindow *vulkanWindow = new VulkanWindow;
    vulkanWindow->setVulkanInstance(&inst);

    MainWindow mainWindow(vulkanWindow);

    //MyDataSet my_data;

    //mainWindow.setMyDataSet(&my_data);
    //mainWindow.formHier->setMyDataSet(&my_data);

    //qDebug() << "%%%%% " << my_data.split_datas[0][0];
    //qDebug() << "%%%%% " << mainWindow.dataset->split_datas[0][0];
    //qDebug()<< "%%%%% before " << mainWindow.formHier->dataset->split_datas[0][0];
    //mainWindow.formHier->testMyData();
    //qDebug()<< "%%%%% after " << mainWindow.formHier->dataset->split_datas[0][0];


    QObject::connect(vulkanWindow, &VulkanWindow::outputStatus, &mainWindow, &MainWindow::inputStatus);
    //QObject::connect(vulkanWindow, &VulkanWindow::sendInfo, &mainWindow, &MainWindow::takeInfoValue);
    mainWindow.resize(1024,768);
    mainWindow.show();



    return app.exec();
}
