#ifndef POLICYUNIT_H
#define POLICYUNIT_H

#include "enviropment.h"
#include <map>

class PolicyUnit
{
public:
    PolicyUnit();
    void SetProbality(Action, double);
    double GetProbality(Action);

    friend bool operator== (const PolicyUnit &pu1, const PolicyUnit &pu2);
    friend bool operator!= (const PolicyUnit &pu1, const PolicyUnit &pu2);
private:
    std::map<Action, double> probalityAction;
};

#endif // POLICYUNIT_H
