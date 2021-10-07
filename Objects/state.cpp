#include "state.h"

State::State(Point pnt, StateUi* stateUi) : Point()
{
    X = pnt.X;
    Y = pnt.Y;
    Z = pnt.Z;
    stUi = stateUi;
    Reward = 0;
    VpOpt = 0;
}

StateUi* State::GetStateUi()
{
    return stUi;
}

State::~State()
{
    //delete stUi;
}

void State::SetReward(double reward)
{
    Reward = reward;
    stUi->SetTextLabel(QString::number(reward));
}
double State::GetReward()
{
    return Reward;
}
void State::SetVpOpt(double vp)
{
    VpOpt = vp;
}
double State::GetVpOpt()
{
    return VpOpt;
}
