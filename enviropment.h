#ifndef ENVIROPMENT_H
#define ENVIROPMENT_H

enum Action { Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft };
enum Alg { DP, IterPolDP, IterStDP, MC, MCWithIS, MCOnePolicy, MCManyPolicy, TD };

class Enviropment
{
public:
    Enviropment(int, int, int);
    static int GetXgrid();
    static int GetYgrid();
    static int GetXYst();

private:
    static int Xgrid;
    static int Ygrid;
    static int XYst;
};

#endif // ENVIROPMENT_H
