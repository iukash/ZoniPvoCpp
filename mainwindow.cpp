#include <QtWidgets>
#include <QBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stateui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StateUi *st1 = new StateUi();
    StateUi *st2 = new StateUi();
    StateUi *st3 = new StateUi();
    StateUi *st4 = new StateUi();
    StateUi *st5 = new StateUi();
    StateUi *st6 = new StateUi();
    QVBoxLayout *vbmain = new QVBoxLayout;
    vbmain->addWidget(st1);
    //ui->gridLayout_2->setColumnStretch(4,0);
    //ui->gridLayout_2->addWidget(st2, 0, 0);
    //ui->gridLayout_2->addWidget(st3, 0, 1);
    //ui->gridLayout_2->addWidget(st4, 0, 2);
    //ui->gridLayout_2->addWidget(st5, 0, 3);
    //ui->gridLayout_2->addWidget(st6, 0, 4);
    setLayout(vbmain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

