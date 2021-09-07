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



   pvoes.push_back(Pvo(7,7,0, 150, 300));
   pvoes.push_back(Pvo(10,10,0, 150, 300));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPixmap pixPvo(":/resource/PVO.jpg");
    auto geomGrid = ui->gridLayout->geometry();
    QPainter painter;
    QImage ImagePvoLevelOne(this->size(), QImage::Format_ARGB32_Premultiplied);
    QImage ImagePvoLevelTwo(this->size(), QImage::Format_ARGB32_Premultiplied);
    QImage ImagePvoLevelThree(this->size(), QImage::Format_ARGB32_Premultiplied);

    for (Pvo pvoItem: pvoes)
    {
      painter.begin(&ImagePvoLevelOne);
      painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
      painter.drawEllipse(pvoItem.GetDistatncePaint(geomGrid.x(),xGrid, false),pvoItem.GetDistatncePaint(geomGrid.y(),yGrid, false), pvoItem.R2, pvoItem.R2);
      painter.end();

      painter.begin(&ImagePvoLevelTwo);
      painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
      painter.drawEllipse(pvoItem.GetDistatncePaint(geomGrid.x(),xGrid, true),pvoItem.GetDistatncePaint(geomGrid.y(),yGrid, true), pvoItem.R1, pvoItem.R1);
      painter.end();

      painter.begin(&ImagePvoLevelThree);
      painter.drawPixmap(geomGrid.x()+xGrid*pvoItem.X,geomGrid.y()+yGrid*pvoItem.Y,xGrid,yGrid,pixPvo);
      painter.end();
    }
    painter.begin(this);
    painter.drawImage(0,0,ImagePvoLevelOne);
    painter.drawImage(0,0,ImagePvoLevelTwo);
    painter.drawImage(0,0,ImagePvoLevelThree);
    painter.end();

}
