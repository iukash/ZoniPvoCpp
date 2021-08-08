#ifndef STATE_H
#define STATE_H

#include "Controls/stateui.h"

class State
{
public:
    State(StateUi*);
    StateUi* GetStateUi();
private:
    StateUi* stUi;
};

#endif // STATE_H
