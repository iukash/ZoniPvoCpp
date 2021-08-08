#include "state.h"

State::State(StateUi* stateUi)
{
    stUi = stateUi;
}

StateUi* State::GetStateUi()
{
    return stUi;
}
