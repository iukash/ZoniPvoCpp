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
    void SetReward(double reward);
    double GetReward();
    void SetVpOpt(double vp);
    double GetVpOpt();
private:
    double VpOpt, Reward;
    StateUi* stUi;
};

#endif // STATE_H
