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

   for (int j = 0; j < Enviropment::Ygrid; j++) {
       for (int i = 0; i < Enviropment::Xgrid; i++) {
           State* st = &(logicWork.states.at(Enviropment::Ygrid*Enviropment::Xgrid - Enviropment::Xgrid - Enviropment::Xgrid*j + i));
           ui->gridLayout->addWidget(st->GetStateUi(), j, i);
       }
   }
//   for (int j = 1; j < Enviropment::Ygrid + 1; j++) {
//       for (int i = 0; i < Enviropment::Xgrid; i++) {
//           State* st = &(logicWork.states.at(Enviropment::Xgrid*j - Enviropment::Xgrid + i));
//           ui->gridLayout->addWidget(st->GetStateUi(), st->Y, st->X);
//       }
//   }
//   for (State stateItem: logicWork.states)
//        ui->gridLayout->addWidget(stateItem.GetStateUi(), stateItem.Y, stateItem.X);

   connect(ui->pushButtonStart, SIGNAL(clicked()), this, SLOT(slotClickedSelectAlgoritm()));
   connect(this, SIGNAL(signalSelectAlgoritm(Alg)), &logicWork, SLOT(slotStartAlgoritm(Alg)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    auto geomGrid = ui->gridLayout->geometry();
    QPixmap pixPvo(":/resource/PVO.jpg");
    if(_initPaint)
    {
        ImagePvoLevelOne = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
        ImagePvoLevelTwo = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
        ImagePvoLevelThree = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
        for (Pvo pvoItem: logicWork.pvoes)
        {
          painter.begin(&ImagePvoLevelOne);
          painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
          painter.drawEllipse(pvoItem.GetPaintR2X(geomGrid.x()),Enviropment::XYst*Enviropment::Ygrid - (geomGrid.y()+Enviropment::XYst*pvoItem.Y + pvoItem.R2), pvoItem.R2*2, pvoItem.R2*2);
          painter.end();

          painter.begin(&ImagePvoLevelTwo);
          painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
          painter.drawEllipse(pvoItem.GetPaintR1X(geomGrid.x()),Enviropment::XYst*Enviropment::Ygrid - (geomGrid.y()+Enviropment::XYst*pvoItem.Y + pvoItem.R1), pvoItem.R1*2, pvoItem.R1*2);
          painter.end();

          painter.begin(&ImagePvoLevelThree);
          painter.drawPixmap(geomGrid.x()+Enviropment::XYst*pvoItem.X,Enviropment::XYst*Enviropment::Ygrid - (geomGrid.y()+Enviropment::XYst*pvoItem.Y+Enviropment::XYst/2),Enviropment::XYst,Enviropment::XYst,pixPvo);
          painter.end();
        }
        _initPaint = false;
    }
    painter.begin(this);
    painter.drawImage(0,0,ImagePvoLevelOne);
    painter.drawImage(0,0,ImagePvoLevelTwo);
    painter.drawImage(0,0,ImagePvoLevelThree);
    QPixmap pixCel(":/resource/Cel.jpg");
    State* cel = logicWork.findState(logicWork.finish);
    painter.drawPixmap(geomGrid.x()+Enviropment::XYst*cel->X,Enviropment::XYst*Enviropment::Ygrid - (geomGrid.y()+Enviropment::XYst/2+Enviropment::XYst*cel->Y),Enviropment::XYst,Enviropment::XYst,pixCel);
    QPixmap pixAgent(":/resource/su57.png");
    State* agent = logicWork.findState((Point)logicWork.agent);
    painter.drawPixmap(geomGrid.x()+Enviropment::XYst*agent->X,Enviropment::XYst*Enviropment::Ygrid - (geomGrid.y()+Enviropment::XYst/2+Enviropment::XYst*agent->Y),Enviropment::XYst,Enviropment::XYst,pixAgent);
    painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch ( e->key() )
    {
    case Qt::Key_W:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(Up, true)));
        update();
        break;
    case Qt::Key_E:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(UpRight, true)));
        update();
        break;
    case Qt::Key_D:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(Right, true)));
        update();
        break;
    case Qt::Key_C:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(DownRight, true)));
        update();
        break;
    case Qt::Key_X:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(Down, true)));
        update();
        break;
    case Qt::Key_Z:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(DownLeft, true)));
        update();
        break;
    case Qt::Key_A:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(Left, true)));
        update();
        break;
    case Qt::Key_Q:
        ui->lineEdit->setText(QString::number(logicWork.agentMoveGetReward(UpLeft, true)));
        update();
        break;
    }
}

void MainWindow::slotClickedSelectAlgoritm()
{
    if(ui->radioButtonDpIterPol->isChecked())
        emit signalSelectAlgoritm(Alg::IterPolDP);
    if(ui->radioButtonDpIterState->isChecked())
        emit signalSelectAlgoritm(Alg::IterStDP);
    if(ui->radioButtonTD->isChecked())
        emit signalSelectAlgoritm(Alg::TD);
}
