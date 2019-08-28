#pragma once
#include <QMainWindow>
#include "MyObject.h"
#include "MainListModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
};
