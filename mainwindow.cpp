#include <QtWidgets>
#include <QBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   QButtonGroup *bGr = new QButtonGroup;
   bGr->addButton(ui->radioButtonDP);
   bGr->addButton(ui->radioButtonMC);
   bGr->addButton(ui->radioButtonTD);
   ui->groupBoxMC->setEnabled(false);

   logicWork = LogicWork();
   for (State stateItem: logicWork.states)
    ui->gridLayout->addWidget(stateItem.GetStateUi(), stateItem.Y ,stateItem.X);
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

    for (Pvo pvoItem: logicWork.pvoes)
    {
      painter.begin(&ImagePvoLevelOne);
      painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
      painter.drawEllipse(pvoItem.GetPaintR2X(geomGrid.x()),pvoItem.GetPaintR2Y(geomGrid.y()), pvoItem.R2, pvoItem.R2);
      painter.end();

      painter.begin(&ImagePvoLevelTwo);
      painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
      painter.drawEllipse(pvoItem.GetPaintR1X(geomGrid.x()),pvoItem.GetPaintR1Y(geomGrid.y()), pvoItem.R1, pvoItem.R1);
      painter.end();

      painter.begin(&ImagePvoLevelThree);
      painter.drawPixmap(geomGrid.x()+Enviropment::XYst*pvoItem.X,geomGrid.y()+Enviropment::XYst*pvoItem.Y,Enviropment::XYst,Enviropment::XYst,pixPvo);
      painter.end();
    }
    painter.begin(this);
    painter.drawImage(0,0,ImagePvoLevelOne);
    painter.drawImage(0,0,ImagePvoLevelTwo);
    painter.drawImage(0,0,ImagePvoLevelThree);
    QPixmap pixCel(":/resource/Cel.jpg");
    State* cel = logicWork.findState(logicWork.finish);
    painter.drawPixmap(geomGrid.x()+Enviropment::XYst*cel->X,geomGrid.y()+Enviropment::XYst*cel->Y,Enviropment::XYst,Enviropment::XYst,pixCel);
    QPixmap pixAgent(":/resource/Cel.jpg");
    State* agent = logicWork.findState((Point)logicWork.agent);
    painter.drawPixmap(geomGrid.x()+Enviropment::XYst*agent->X,geomGrid.y()+Enviropment::XYst*agent->Y,Enviropment::XYst,Enviropment::XYst,pixAgent);
    painter.end();

}
