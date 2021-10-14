#include <QPainter>
#include "pvo.h"

Pvo::Pvo(Point pnt, int r1, int r2) : Point()
{
    X = pnt.X;
    Y = pnt.Y;
    Z = pnt.Z;
    R1 = r1;
    R2 = r2;
}

Pvo::~Pvo()
{
}

int Pvo::GetPaintR1X(int geomGridKoord)
{
    return geomGridKoord+Enviropment::GetXYst()*X - R1 + Enviropment::GetXYst()/2;
}
int Pvo::GetPaintR2X(int geomGridKoord)
{
    return geomGridKoord+Enviropment::GetXYst()*X - R2 + Enviropment::GetXYst()/2;
}
int Pvo::GetPaintR1Y(int geomGridKoord)
{
    return geomGridKoord+Enviropment::GetXYst()*Y - R1 + Enviropment::GetXYst()/2;
}
int Pvo::GetPaintR2Y(int geomGridKoord)
{
    return geomGridKoord+Enviropment::GetXYst()*Y - R2 + Enviropment::GetXYst()/2;
}
//void Pvo::paintEvent(QPaintEvent *)
//{
//    QPainter painter;
//    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
//    painter.drawEllipse(_x,_y,_r1,_r1);
//    painter.drawEllipse(_x,_y,_r2,_r2);
//}


