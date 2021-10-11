#include <QtDebug>
#include "logicwork.h"

LogicWork::LogicWork()
{
    //инициализация состояний
    for (int i = 0; i < Enviropment::Ygrid; i++)
        for (int j = 0; j < Enviropment::Xgrid; j++)
            states.push_back(State(Point(j,i,0),new StateUi()));

    //инициализация ПВО
    pvoes.push_back(Pvo(Point(17,14,0), 150, 300));
    pvoes.push_back(Pvo(Point(20,10,0), 150, 300));
    updateRewardPvo();
    //инициализация финиша
    finish = Point(Enviropment::Xgrid-(int)Enviropment::Xgrid/10, Enviropment::Ygrid-(int)Enviropment::Ygrid/8, 0);
    findState(finish)->SetReward(50);
    //инициализации агента
    agent = Agent(Point(2,2,0));
    //инициализации массива вознаграждений за движение -1 за движение в стороны и -1.4 (sqrt(-2)) при движении по диагонали
    double line = -5;
    double diag = -7.1;
    rewardforMove = {{Up, line},{UpLeft, diag},{Left, line},{DownLeft, diag},{Down, line},{DownRight, diag},{Right, line},{UpRight, diag},};
    connect(&algDpPol, SIGNAL(signalGetInfoState(State*, Action)), this, SLOT(slotGetInfoState(State*, Action)));
    connect(this, SIGNAL(signalReturnInfoState(InfoState)), &algDpPol, SLOT(slotReturnInfoState(InfoState)));
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
                stateItem.SetReward(stateItem.GetReward()-10);
            if(_distance < pvoItem.R1)
                stateItem.SetReward(stateItem.GetReward()-30);
        }
    }
}

double LogicWork::agentMoveGetReward(Action act, bool move)
{
    Point movePoint = moveToPoint(&agent, act);
    if(move)
        agent.SetPosition(movePoint);

    return findState(movePoint)->GetReward() + rewardforMove.at(act);
}

template <class TempAgentState>
Point LogicWork::moveToPoint(const TempAgentState &st, Action act)
{
    Point movePoint = Point(st->X, st->Y, st->Z);
    if(movePoint == finish)
        return movePoint;

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
    InfoState iSt = InfoState(_st->GetReward(), _st->GetVpOpt(), rewardforMove.at(act));
    emit signalReturnInfoState(iSt);
}
