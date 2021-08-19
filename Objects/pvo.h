#ifndef PVO_H
#define PVO_H

#include <QPixmap>
#include <QWidget>
#include "Objects/point.h"

class Pvo: public Point
{

public:
    Pvo(int x, int y, int z, int r1 = 0, int r2 = 0);
    ~Pvo();
    int R1, R2;
    int GetDistatncePaint(int geomGridKoord, int sizeGrid, bool flagR1);

private:
    int _x,_y,_z,_r1,_r2;
};

#endif // PVO_H
