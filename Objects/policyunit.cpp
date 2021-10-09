#include "policyunit.h"

PolicyUnit::PolicyUnit()
{
    probalityAction = {
        {Up, 0.125},
        {UpRight, 0.125},
        {Right, 0.125},
        {DownRight, 0.125},
        {Down, 0.125},
        {DownLeft, 0.125},
        {Left, 0.125},
        {UpLeft, 0.125},
    };
}

void PolicyUnit::SetProbality(Action act, double value)
{
    probalityAction.at(act) = value;
}

double PolicyUnit::GetProbality(Action act)
{
    return probalityAction.at(act);
}

bool operator== (const PolicyUnit &pu1, const PolicyUnit &pu2)
{
    return (pu1.probalityAction == pu2.probalityAction);
}

bool operator!= (const PolicyUnit &pu1, const PolicyUnit &pu2)
{
    return !(pu1 == pu2);
}
