#include "logicwork.h"
#include <math.h>

LogicWork::LogicWork()
{
    for (int i = Enviropment::Ygrid - 1; i > -1; i--)
        for (int j = 0; j < Enviropment::Xgrid; j++)
            states.push_back(State(Point(j,i,0),new StateUi()));

    pvoes.push_back(Pvo(Point(17,17,0), 150, 300));
    pvoes.push_back(Pvo(Point(13,13,0), 150, 300));
    finish = Point(Enviropment::Xgrid - int(Enviropment::Xgrid/10), Enviropment::Ygrid - int(Enviropment::Ygrid/5), 0);
    findState(finish)->SetReward(1000);
    agent = Agent(Point(2,2,0));
    updateRewardPvo();
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
                stateItem.SetReward(stateItem.GetReward()-15);
            if(_distance < pvoItem.R1)
                stateItem.SetReward(stateItem.GetReward()-30);
        }
    }
}

double LogicWork::agentMoveGetReward(Action act, bool move)
{
    Point movePoint;
    switch(act)
    {
        case Up:
        movePoint = Point(agent.X, agent.Y + 1, agent.Z);
        break;
        case UpRight:
        movePoint = Point(agent.X + 1, agent.Y + 1, agent.Z);
        break;
        case Right:
        movePoint = Point(agent.X + 1, agent.Y, agent.Z);
        break;
        case DownRight:
        movePoint = Point(agent.X + 1, agent.Y - 1, agent.Z);
        break;
        case Down:
        movePoint = Point(agent.X, agent.Y - 1, agent.Z);
        break;
        case DownLeft:
        movePoint = Point(agent.X - 1, agent.Y - 1, agent.Z);
        break;
        case Left:
        movePoint = Point(agent.X - 1, agent.Y, agent.Z);
        break;
        case UpLeft:
        movePoint = Point(agent.X - 1, agent.Y + 1, agent.Z);
        break;
    }

    if(move)
        agent.SetPosition(movePoint);

    return findState(movePoint)->GetReward();
}
