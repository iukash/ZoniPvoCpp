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
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    painter.drawLine(0, 0, 50, 50);
    painter.drawLine(0, 50, 50, 0);
    painter.drawLine(0, 0, 50, 0);
    painter.drawLine(0, 0, 0, 50);
    painter.drawLine(50, 50, 50, 0);
    painter.drawLine(50, 50, 0, 50);
    painter.drawEllipse(23,23,4,4);
 }
StateUi::~StateUi()
{
    delete ui;
}
