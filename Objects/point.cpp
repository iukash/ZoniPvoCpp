#include "point.h"

Point::Point(int x, int y, int z)
{
    X = x;
    Y = y;
    Z = z;
}

Point::Point()
{
    X = 0;
    Y = 0;
    Z = 0;
}

bool operator== (const Point &pnt1, const Point &pnt2)
{
    return ((pnt1.X == pnt2.X) && (pnt1.Y == pnt2.Y) && (pnt1.Z == pnt2.Z));
}

bool operator!= (const Point &pnt1, const Point &pnt2)
{
    return !(pnt1 == pnt2);
}
