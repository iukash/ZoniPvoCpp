#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(int x, int y, int z);
    Point();
    int X;
    int Y;
    int Z;
    friend bool operator== (const Point &pnt1, const Point &pnt2);
    friend bool operator!= (const Point &pnt1, const Point &pnt2);
};

#endif // POINT_H
