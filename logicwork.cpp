#include "logicwork.h"

LogicWork::LogicWork()
{
    for (int i = Enviropment::Ygrid - 1; i > -1; i--)
        for (int j = 0; j < Enviropment::Xgrid; j++)
            states.push_back(State(Point(j,i,0),new StateUi()));

    pvoes.push_back(Pvo(Point(17,17,0), 150, 300));
    pvoes.push_back(Pvo(Point(13,13,0), 150, 300));
    finish = Point(Enviropment::Xgrid - int(Enviropment::Xgrid/10), Enviropment::Ygrid - int(Enviropment::Ygrid/5), 0);
    agent = Agent(Point(2,2,0));
}

LogicWork::~LogicWork()
{
    states.~vector();
    pvoes.~vector();
}

State* LogicWork::findState(Point pnt)
{
    return &states.at(pnt.Y*Enviropment::Xgrid + pnt.X);
}
