#include <QtDebug>
#include "logicwork.h"

LogicWork::LogicWork(int xGrig, int yGrid, int xySt)
{
    Enviropment envi = Enviropment(xGrig, yGrid, xySt);
    //инициализация состояний
    for (int i = 0; i < Enviropment::GetYgrid(); i++)
        for (int j = 0; j < Enviropment::GetXgrid(); j++)
            states.push_back(State(Point(j,i,0),new StateUi()));

    //инициализация ПВО
    pvoes.push_back(Pvo(Point(17,14,0), 150, 300));
    pvoes.push_back(Pvo(Point(20,10,0), 150, 300));
    updateRewardPvo();
    //инициализация финиша
    finish = Point(Enviropment::GetXgrid()-(int)Enviropment::GetXgrid()/10, Enviropment::GetYgrid()-(int)Enviropment::GetYgrid()/8, 0);
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
    return &states.at(pnt.Y*Enviropment::GetXgrid() + pnt.X);
}

void LogicWork::updateRewardPvo(void)
{
    for (Pvo& pvoItem: pvoes)
    {
        for(State& stateItem: states)
        {
            double _distance = sqrt(pow(Enviropment::GetXYst()*(pvoItem.X - stateItem.X), 2) + pow(Enviropment::GetXYst()*(pvoItem.Y - stateItem.Y), 2));
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
        if(st->Y!=Enviropment::GetYgrid()-1)
            movePoint = Point(st->X, st->Y + 1, st->Z);
        break;
        case UpRight:
        if(st->X!=(Enviropment::GetXgrid()-1) && st->Y!=(Enviropment::GetYgrid()-1))
            movePoint = Point(st->X + 1, st->Y + 1, st->Z);
        break;
        case Right:
        if(st->X!=(Enviropment::GetXgrid()-1))
            movePoint = Point(st->X + 1, st->Y, st->Z);
        break;
        case DownRight:
        if(st->X!=(Enviropment::GetXgrid()-1) && st->Y!=0)
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
        if(st->X!=0 && st->Y!=(Enviropment::GetYgrid()-1))
            movePoint = Point(st->X - 1, st->Y + 1, st->Z);
        break;
    }
    return movePoint;
}

void LogicWork::slotStartAlgoritm(Alg alg)
{
    if(alg == Alg::IterPolDP)
        algDpPol.StartAlgoritmDpIterPolicy(&states);

    drawRoute();
}

void LogicWork::slotGetInfoState(State* st, Action act)
{
    State* _st = findState(moveToPoint(st, act));
    InfoState iSt = InfoState(_st->GetReward(), _st->GetVpOpt(), rewardforMove.at(act));
    emit signalReturnInfoState(iSt);
}

void LogicWork::drawRoute(void)
{
    std::vector<State* > rezultVector;
    State* _nacState = findState(Point(agent.X, agent.Y, agent.Z));
    rezultVector.push_back(_nacState);
    State* _konState = findState(finish);
    bool finishState = false;
    while(!finishState)
    {
        std::vector<double> array;
        for(int i = 0; i < 8; i++)  //8 - количество элементов Action
        {
            State* _st = findState(moveToPoint(_nacState, (Action)i));
            array.push_back(_st->GetReward() + _st->GetVpOpt());
        }

        double maxValue = *max_element(array.begin(), array.end());
        std::vector<double> rezChet, rezNechet;
        for (std::size_t i = 0; i < array.size(); i++)
        {
            if(maxValue == array.at(i))
            {
                if(i%2==0)
                    rezChet.push_back(i);
                else
                    rezNechet.push_back(i);
            }
        }

        if(rezChet.size()>0)
            _nacState = findState(moveToPoint(_nacState, (Action)rezChet.at(rand() % rezChet.size())));
        else
            _nacState = findState(moveToPoint(_nacState, (Action)rezNechet.at(rand() % rezNechet.size())));

        rezultVector.push_back(_nacState);

        if(_nacState==_konState)
            finishState = true;
    }
    emit signalDrawRoute(rezultVector);
}
