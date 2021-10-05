#include "state.h"

State::State(Point pnt, StateUi* stateUi) : Point()
{
    X = pnt.X;
    Y = pnt.Y;
    Z = pnt.Z;
    stUi = stateUi;
}

StateUi* State::GetStateUi()
{
    return stUi;
}

State::~State()
{
    //delete stUi;
}
