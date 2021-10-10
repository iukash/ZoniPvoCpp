#include <QtDebug>
#include "logicwork.h"

LogicWork::LogicWork()
{
    for (int i = 0; i < Enviropment::Ygrid; i++)
        for (int j = 0; j < Enviropment::Xgrid; j++)
            states.push_back(State(Point(j,i,0),new StateUi()));

    pvoes.push_back(Pvo(Point(17,15,0), 150, 300));
    pvoes.push_back(Pvo(Point(13,11,0), 150, 300));
    finish = Point(37, 4, 0);
    findState(finish)->SetReward(500);
    agent = Agent(Point(2,22,0));
    updateRewardPvo();
    connect(&algDpPol, SIGNAL(signalGetInfoState(State*, Action)), this, SLOT(slotGetInfoState(State*, Action)));
    connect(this, SIGNAL(signalReturnInfoState(std::pair <double, double>)), &algDpPol, SLOT(slotReturnInfoState(std::pair <double, double>)));
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

void LogicWork::updateRewardPvo(void)
{
    for (Pvo& pvoItem: pvoes)
    {
        for(State& stateItem: states)
        {
            double _distance = sqrt(pow(Enviropment::XYst*(pvoItem.X - stateItem.X), 2) + pow(Enviropment::XYst*(pvoItem.Y - stateItem.Y), 2));
            if(_distance < pvoItem.R2)
                stateItem.SetReward(stateItem.GetReward()-10000);
            if(_distance < pvoItem.R1)
                stateItem.SetReward(stateItem.GetReward()-30000);
        }
    }
}

double LogicWork::agentMoveGetReward(Action act, bool move)
{
    Point movePoint = moveToPoint(&agent, act);
    if(move)
        agent.SetPosition(movePoint);

    return findState(movePoint)->GetReward();
}

template <class TempAgentState>
Point LogicWork::moveToPoint(const TempAgentState &st, Action act)
{
    Point movePoint = Point(st->X, st->Y, st->Z);
    switch(act)
    {
        case Up:
        if(st->Y!=Enviropment::Ygrid-1)
            movePoint = Point(st->X, st->Y + 1, st->Z);
        break;
        case UpRight:
        if(st->X!=(Enviropment::Xgrid-1) && st->Y!=(Enviropment::Ygrid-1))
            movePoint = Point(st->X + 1, st->Y + 1, st->Z);
        break;
        case Right:
        if(st->X!=(Enviropment::Xgrid-1))
            movePoint = Point(st->X + 1, st->Y, st->Z);
        break;
        case DownRight:
        if(st->X!=(Enviropment::Xgrid-1) && st->Y!=0)
            movePoint = Point(st->X + 1, st->Y - 1, st->Z);
        break;
        case Down:
        if(st->Y!=0)
            movePoint = Point(st->X, st->Y - 1, st->Z);
        break;
        case DownLeft:
        if(st->X!=0 && st->Y!=0)
            movePoint = Point(st->X - 1, st->Y - 1, st->Z);
        break;
        case Left:
        if(st->X!=0)
            movePoint = Point(st->X - 1, st->Y, st->Z);
        break;
        case UpLeft:
        if(st->X!=0 && st->Y!=(Enviropment::Ygrid-1))
            movePoint = Point(st->X - 1, st->Y + 1, st->Z);
        break;
    }
    return movePoint;
}

void LogicWork::slotStartAlgoritm(Alg alg)
{
    if(alg == Alg::IterPolDP)
        algDpPol.StartAlgoritmDpIterPolicy(&states);
}

void LogicWork::slotGetInfoState(State* st, Action act)
{
    State* _st = findState(moveToPoint(st, act));
    std::pair <double, double> par = {_st->GetReward(), _st->GetVpOpt()};
    emit signalReturnInfoState(par);
}
