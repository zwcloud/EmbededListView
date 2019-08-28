#include "mainwindow.h"
#include <QVBoxLayout>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include "MainListModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(450, 500);
    auto central = new QWidget;
    setCentralWidget(central);

    //container's layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    central->setLayout(layout);

    //model
    auto* objectList = new MainListModel();
    std::vector<MyObject*> list;
    list.push_back(new MyObject(0, "Apple", {1, 2, 3}));
    list.push_back(new MyObject(1, "Orange", {4, 5, 6, 7}));
    list.push_back(new MyObject(2, "Banana", {8, 9, 10, 11, 12, 13}));
    objectList->fill(list);

    //quick widget
    QQuickWidget* quickWidget = new QQuickWidget;
    quickWidget->engine()->rootContext()->setContextProperty("objectList", objectList);
    quickWidget->setSource(QUrl::fromLocalFile("../EmbededListView/main.qml"));
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    layout->addWidget(quickWidget, 1);
}
