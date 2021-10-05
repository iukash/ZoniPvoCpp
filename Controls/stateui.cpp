#include "stateui.h"
#include "ui_stateui.h"
#include <QPainter>

StateUi::StateUi(QWidget *parent) :
    QWidget(parent), ui(new Ui::StateUi)
{
    ui->setupUi(this);
    XYst = Enviropment::XYst;
    this->setMinimumSize(XYst,XYst);
}

void StateUi::paintEvent(QPaintEvent *)
 {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    painter.drawLine(0, 0, XYst, XYst);
    painter.drawLine(0, XYst, XYst, 0);
    painter.drawLine(0, 0, XYst, 0);
    painter.drawLine(0, 0, 0, XYst);
    painter.drawLine(XYst, XYst, XYst, 0);
    painter.drawLine(XYst, XYst, 0, XYst);
    double centerEl = XYst/10;
    painter.drawEllipse(XYst/2-centerEl/2,XYst/2-centerEl/2,centerEl,centerEl);
 }
StateUi::~StateUi()
{
    delete ui;
}
