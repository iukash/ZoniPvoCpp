#include "stateui.h"
#include "ui_stateui.h"
#include <QPainter>
#include <QVBoxLayout>

StateUi::StateUi(QWidget *parent) :
    QWidget(parent), ui(new Ui::StateUi)
{
    ui->setupUi(this);
    XYst = Enviropment::GetXYst();
    this->setMinimumSize(XYst,XYst);
    lbl = new QLabel("0", this);
    lbl->setFixedWidth(XYst);
    lbl->setAlignment(Qt::AlignHCenter);
    lbl->setStyleSheet("QLabel {color : green;}"); // background-color : red;
    //QVBoxLayout *vBoxLayoutMain = new QVBoxLayout();
    //vBoxLayoutMain->addWidget(lbl);
    //vBoxLayoutMain->addWidget(lbl);
    //setLayout(vBoxLayoutMain);
}

void StateUi::SetTextLabel(QString str)
{
    lbl->setText(str);
    //update();
}

void StateUi::paintEvent(QPaintEvent *)
 {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(0, 0, XYst, XYst);
    painter.drawLine(XYst/2, 0, XYst/2, XYst);
    painter.drawLine(0, XYst, XYst, 0);
    painter.drawLine(0, XYst/2, XYst, XYst/2);
    double centerEl = XYst/8;
    painter.setBrush(Qt::black);
    painter.drawEllipse(XYst/2-centerEl/2,XYst/2-centerEl/2,centerEl,centerEl);
 }
StateUi::~StateUi()
{
    delete lbl;
    delete ui;
}
