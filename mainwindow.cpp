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

   logicWork = new LogicWork(40, 26, 40);
   for (int j = 0; j < Enviropment::GetYgrid(); j++) {
       for (int i = 0; i < Enviropment::GetXgrid(); i++) {
           State* st = &(logicWork->states.at(Enviropment::GetYgrid()*Enviropment::GetXgrid() - Enviropment::GetXgrid() - Enviropment::GetXgrid()*j + i));
           ui->gridLayout->addWidget(st->GetStateUi(), j, i);
       }
   }
   connect(ui->pushButtonStart, SIGNAL(clicked()), this, SLOT(slotClickedSelectAlgoritm()));
   connect(logicWork, SIGNAL(signalDrawRoute(std::vector<State* >)), this, SLOT(slotDrawRoute(std::vector<State* >)));
   connect(this, SIGNAL(signalSelectAlgoritm(Alg)), logicWork, SLOT(slotStartAlgoritm(Alg)));
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
        for (Pvo pvoItem: logicWork->pvoes)
        {
          painter.begin(&ImagePvoLevelOne);
          painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
          painter.drawEllipse(pvoItem.GetPaintR2X(geomGrid.x()),Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()*pvoItem.Y + pvoItem.R2), pvoItem.R2*2, pvoItem.R2*2);
          painter.end();

          painter.begin(&ImagePvoLevelTwo);
          painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
          painter.drawEllipse(pvoItem.GetPaintR1X(geomGrid.x()),Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()*pvoItem.Y + pvoItem.R1), pvoItem.R1*2, pvoItem.R1*2);
          painter.end();

          painter.begin(&ImagePvoLevelThree);
          painter.drawPixmap(geomGrid.x()+Enviropment::GetXYst()*pvoItem.X,Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()*pvoItem.Y+Enviropment::GetXYst()/2),Enviropment::GetXYst(),Enviropment::GetXYst(),pixPvo);
          painter.end();
        }
        _initPaint = false;
    }

    painter.begin(this);
    painter.setPen(QPen(Qt::green, 5, Qt::SolidLine));
    if(routeDraw)
    {
        auto item = route.begin();
        while( (item+1) != route.end() )
        {
            State* nac = (*item);
            item++;
            State* kon = (*item);
            painter.drawLine(geomGrid.x()+Enviropment::GetXYst()*nac->X+Enviropment::GetXYst()/2,Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()*nac->Y),
                             geomGrid.x()+Enviropment::GetXYst()*kon->X+Enviropment::GetXYst()/2,Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()*kon->Y));
        }
    }

    painter.drawImage(0,0,ImagePvoLevelOne);
    painter.drawImage(0,0,ImagePvoLevelTwo);
    painter.drawImage(0,0,ImagePvoLevelThree);
    QPixmap pixCel(":/resource/Cel.jpg");
    State* cel = logicWork->findState(logicWork->finish);
    painter.drawPixmap(geomGrid.x()+Enviropment::GetXYst()*cel->X,Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()/2+Enviropment::GetXYst()*cel->Y),Enviropment::GetXYst(),Enviropment::GetXYst(),pixCel);
    QPixmap pixAgent(":/resource/su57.png");
    State* agent = logicWork->findState((Point)logicWork->agent);
    painter.drawPixmap(geomGrid.x()+Enviropment::GetXYst()*agent->X,Enviropment::GetXYst()*Enviropment::GetYgrid() - (geomGrid.y()+Enviropment::GetXYst()/2+Enviropment::GetXYst()*agent->Y),Enviropment::GetXYst(),Enviropment::GetXYst(),pixAgent);
    painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch ( e->key() )
    {
    case Qt::Key_W:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(Up, true)));
        update();
        break;
    case Qt::Key_E:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(UpRight, true)));
        update();
        break;
    case Qt::Key_D:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(Right, true)));
        update();
        break;
    case Qt::Key_C:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(DownRight, true)));
        update();
        break;
    case Qt::Key_X:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(Down, true)));
        update();
        break;
    case Qt::Key_Z:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(DownLeft, true)));
        update();
        break;
    case Qt::Key_A:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(Left, true)));
        update();
        break;
    case Qt::Key_Q:
        ui->lineEdit->setText(QString::number(logicWork->agentMoveGetReward(UpLeft, true)));
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

void MainWindow::slotDrawRoute(std::vector<State* > rezSlotRoute)
{
    route = rezSlotRoute;
    routeDraw = true;
    update();
}
