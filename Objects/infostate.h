#ifndef INFOSTATE_H
#define INFOSTATE_H


class InfoState
{
public:
    InfoState();
    InfoState(double, double, double);
    double Reward;
    double Vp;
    double MoveReward;
};

#endif // INFOSTATE_H
