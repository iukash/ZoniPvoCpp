#include "stateui.h"
#include "ui_stateui.h"
#include <QPainter>

StateUi::StateUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateUi)
{
    ui->setupUi(this);
}

void StateUi::paintEvent(QPaintEvent *event)
 {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 50, 50);
 }
StateUi::~StateUi()
{
    delete ui;
}
