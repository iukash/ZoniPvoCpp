#ifndef PVO_H
#define PVO_H

#include <QPixmap>
#include <QWidget>
#include "Objects/point.h"
#include "enviropment.h"

class Pvo: public Point
{
public:
    Pvo(Point pnt, int r1, int r2);
    ~Pvo();
    int GetPaintR1X(int geomGridKoord);
    int GetPaintR2X(int geomGridKoord);
    int GetPaintR1Y(int geomGridKoord);
    int GetPaintR2Y(int geomGridKoord);
    int R1, R2;
private:
};
#endif // PVO_H
