#ifndef PVO_H
#define PVO_H

#include <QPixmap>
#include "Objects/point.h"

class Pvo: public Point
{
public:
    Pvo(int x, int y, int z);
    QPixmap GetPixmap();

private:
    QPixmap pix;
};

#endif // PVO_H
