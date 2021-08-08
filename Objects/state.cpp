#include "state.h"

State::State(StateUi* stateUi)
{
    stUi = stateUi;
}

StateUi* State::GetStateUi()
{
    return stUi;
}

int State::GetNumber(int x, int y, int sizeY)
{
    return sizeY*y + x;
}
