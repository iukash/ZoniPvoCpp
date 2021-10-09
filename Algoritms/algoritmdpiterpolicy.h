#ifndef ALGORITMDPITERPOLICY_H
#define ALGORITMDPITERPOLICY_H

#include "Objects/policyunit.h"
#include "Objects/state.h"
#include <vector>
#include <QtDebug>

class AlgoritmDpIterPolicy
{
public:
    AlgoritmDpIterPolicy();
    static void StartAlgoritmDpIterPolicy(std::vector <State>* );

private:
    static std::vector <PolicyUnit> currentPolicy;
    static std::vector <PolicyUnit> optimalPolicy;
    static double discount;
    static void UpdateVpStates(std::vector <State>*);
    static double CountVpState(State* st, PolicyUnit* pSt);
};

#endif // ALGORITMDPITERPOLICY_H
