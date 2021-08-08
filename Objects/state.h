#ifndef STATE_H
#define STATE_H

#include "Controls/stateui.h"

class State
{
public:
    State(StateUi*);
    StateUi* GetStateUi();
    static int GetNumber(int x, int y, int sizeY);
private:
    StateUi* stUi;
};

#endif // STATE_H
