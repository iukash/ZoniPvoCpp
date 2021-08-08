#include <QtWidgets>
#include <QBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   sizeX = 19;
   sizeY = 19;
   for (int i = 0; i < sizeY; i++) {
       for (int j = 0; j < sizeX; j++) {
           states.push_back(new State(new StateUi()));
           ui->gridLayout->addWidget(states.at(sizeY*i + j)->GetStateUi(), i , j);
       }
   }

}

MainWindow::~MainWindow()
{
    delete ui;
}

