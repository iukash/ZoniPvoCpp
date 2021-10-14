#include "enviropment.h"

int Enviropment::Xgrid = 0;
int Enviropment::Ygrid = 0;
int Enviropment::XYst = 0;

Enviropment::Enviropment(int xGrid, int yGrid, int xySt)
{
    Enviropment::Xgrid = xGrid;
    Enviropment::Ygrid = yGrid;
    Enviropment::XYst = xySt;
}

int Enviropment::GetXgrid()
{
    return Enviropment::Xgrid;
}

int Enviropment::GetYgrid()
{
    return Enviropment::Ygrid;
}

int Enviropment::GetXYst()
{
    return Enviropment::XYst;
}
