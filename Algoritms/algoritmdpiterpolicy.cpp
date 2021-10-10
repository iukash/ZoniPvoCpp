#include "algoritmdpiterpolicy.h"
#include <algorithm>

AlgoritmDpIterPolicy::AlgoritmDpIterPolicy()
{
    discount = 0.9;
}

void AlgoritmDpIterPolicy::StartAlgoritmDpIterPolicy(std::vector <State>* states)
{
    for (auto i = states->begin(); i != states->end(); i++)
        currentPolicy.push_back(PolicyUnit());

    bool NotEquality = true;
    while (NotEquality)
    {
        optimalPolicy.clear();

        for (auto curPolItem = currentPolicy.begin(); curPolItem != currentPolicy.end(); curPolItem++)
            optimalPolicy.push_back(*curPolItem);

        UpdateVpStates(states);
        UpdateCurrentPolicy(states);

        NotEquality = false;
        if(currentPolicy!=optimalPolicy)
            NotEquality = true;
    }
}

void AlgoritmDpIterPolicy::UpdateVpStates(std::vector <State>* states)
{
    auto itemPolicySt = currentPolicy.begin();
    for (auto itemState = states->begin(); itemState != states->end(); itemState++, itemPolicySt++)
    {
        State* st = &(*itemState);
        PolicyUnit* pu = &(*itemPolicySt);
        st->SetVpOpt(round(CountVpState(st, pu)));
    }
}

double AlgoritmDpIterPolicy::CountVpState(State* st, PolicyUnit* pSt)
{
    double rezult = 0.0;
    for(int i = 0; i < 8; i++)  //8 - количество элементов Action
    {
        emit signalGetInfoState(st, (Action)i);
        std::pair <double, double> pairUp {pairState.first, pairState.second};
        rezult += pSt->GetProbality((Action)i)*(pairState.first + discount*pairState.second);
    }
    return rezult;
}

void AlgoritmDpIterPolicy::slotReturnInfoState(std::pair <double, double> par)
{
    pairState.first = par.first;
    pairState.second = par.second;
}

void AlgoritmDpIterPolicy::UpdateCurrentPolicy(std::vector <State>* states)
{
    auto itemPolicySt = currentPolicy.begin();
    for (auto itemState = states->begin(); itemState != states->end(); itemState++, itemPolicySt++)
    {
        std::vector<double> array;
        State* _st = &(*itemState);
        for(int i = 0; i < 8; i++)  //8 - количество элементов Action
        {
            emit signalGetInfoState(_st, (Action)i);
            std::pair <double, double> pairUp {pairState.first, pairState.second};
            array.push_back(pairState.first + discount*pairState.second);
        }

        double maxValue = *max_element(array.begin(), array.end());
        std::vector<double> results;
        for (std::size_t i = 0; i < array.size(); i++)
        {
            if(maxValue == array.at(i))
                results.push_back(i);
        }

        (*itemPolicySt).SetAllProbality0();

        double probability = 1 / (double)results.size();
        for (std::size_t i = 0; i < results.size(); i++)
        {
            (*itemPolicySt).SetProbality((Action)results[i], probability);
        }
    }
}
