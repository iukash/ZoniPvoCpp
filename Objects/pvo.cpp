#include <QPainter>
#include "pvo.h"

Pvo::Pvo(int x, int y, int z, int r1, int r2) : Point(x,y,z)
{
    _x = x;
    _y = y;
    _z = z;
    R1 = r1;
    R2 = r2;
}

Pvo::~Pvo()
{
}

int Pvo::GetDistatncePaint(int geomGridKoord, int sizeGrid, bool flagR1)
{
    int rezult = 0;
    if(flagR1)
        rezult = geomGridKoord+sizeGrid*_x - R1/2 + sizeGrid/2;
    else
        rezult = geomGridKoord+sizeGrid*_x - R2/2 + sizeGrid/2;
    return rezult;
}

//void Pvo::paintEvent(QPaintEvent *)
//{
//    QPainter painter;
//    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
//    painter.drawEllipse(_x,_y,_r1,_r1);
//    painter.drawEllipse(_x,_y,_r2,_r2);
//}


