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
   xGrid = 50;
   yGrid = 50;

   for (int i = 0; i < sizeY; i++) {
       for (int j = 0; j < sizeX; j++) {
           states.push_back(State(new StateUi()));
           ui->gridLayout->addWidget(states.at(State::GetNumber(j, i, sizeY)).GetStateUi(), i , j);
       }
   }

   QButtonGroup *bGr = new QButtonGroup;
   bGr->addButton(ui->radioButtonDP);
   bGr->addButton(ui->radioButtonMC);
   bGr->addButton(ui->radioButtonTD);
   ui->groupBoxMC->setEnabled(false);

   pvoes.push_back(Pvo(0,0,0));
   pvoes.push_back(Pvo(2,2,0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    auto geomGrid = ui->gridLayout->geometry();
    QPainter painter(this);
    for (Pvo pvoItem: pvoes)
      painter.drawPixmap(geomGrid.x()+xGrid*pvoItem.X,geomGrid.y()+yGrid*pvoItem.Y,xGrid,yGrid,pvoItem.GetPixmap());
}
