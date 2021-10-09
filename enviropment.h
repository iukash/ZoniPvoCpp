#ifndef ENVIROPMENT_H
#define ENVIROPMENT_H

enum Action { Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft };
enum Alg { DP, IterPolDP, IterStDP, MC, MCWithIS, MCOnePolicy, MCManyPolicy, TD };

class Enviropment
{
public:
    Enviropment();
    static const int Xgrid = 40;
    static const int Ygrid = 26;
    static const int XYst = 40;
};

#endif // ENVIROPMENT_H
