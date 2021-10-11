#include "infostate.h"

InfoState::InfoState()
{
    Reward = 0;
    Vp = 0;
    MoveReward = 0;
}

InfoState::InfoState(double reward, double vp, double movereward)
{
    Reward = reward;
    Vp = vp;
    MoveReward = movereward;
}
