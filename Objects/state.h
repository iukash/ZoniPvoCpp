#ifndef STATE_H
#define STATE_H

#include "Controls/stateui.h"
#include "point.h"

class State : public Point
{
public:
    State(Point pnt, StateUi*);
    ~State();
    StateUi* GetStateUi();
    double VpOpt, Reward;
private:
    StateUi* stUi;
};

#endif // STATE_H
