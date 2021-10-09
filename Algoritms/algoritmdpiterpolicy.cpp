#include "algoritmdpiterpolicy.h"

AlgoritmDpIterPolicy::AlgoritmDpIterPolicy()
{

}

std::vector <PolicyUnit> AlgoritmDpIterPolicy::currentPolicy;
std::vector <PolicyUnit> AlgoritmDpIterPolicy::optimalPolicy;
double AlgoritmDpIterPolicy::discount = 0.9;

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
        //UpdateCurrentPolicy(lstState, discont, lstPolicyCurrent);

        NotEquality = false;
        if(currentPolicy==optimalPolicy)
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
        st->SetVpOpt(CountVpState(st, pu));
    }
}

double AlgoritmDpIterPolicy::CountVpState(State* st, PolicyUnit* pSt)
{
    double rezult = 0.0;
//    rezult = pSt->GetProbality(Up) *
//                GetProbabilityAction(Act.LeftDown) * (st.GetReward(Act.LeftDown) + discont * EventsHelper.OnEventMoveState(st, Act.LeftDown).VpOpt) +
//             pSt.GetProbabilityAction(Act.Left) * (st.GetReward(Act.Left) + discont * EventsHelper.OnEventMoveState(st, Act.Left).VpOpt) +
//             pSt.GetProbabilityAction(Act.LeftUp) * (st.GetReward(Act.LeftUp) + discont * EventsHelper.OnEventMoveState(st, Act.LeftUp).VpOpt) +
//             pSt.GetProbabilityAction(Act.Up) * (st.GetReward(Act.Up) + discont * EventsHelper.OnEventMoveState(st, Act.Up).VpOpt) +
//             pSt.GetProbabilityAction(Act.RightUp) * (st.GetReward(Act.RightUp) + discont * EventsHelper.OnEventMoveState(st, Act.RightUp).VpOpt) +
//             pSt.GetProbabilityAction(Act.Right) * (st.GetReward(Act.Right) + discont * EventsHelper.OnEventMoveState(st, Act.Right).VpOpt) +
//             pSt.GetProbabilityAction(Act.RightDown) * (st.GetReward(Act.RightDown) + discont * EventsHelper.OnEventMoveState(st, Act.RightDown).VpOpt) +
//             pSt.GetProbabilityAction(Act.Down) * (st.GetReward(Act.Down) + discont * EventsHelper.OnEventMoveState(st, Act.Down).VpOpt);
    return rezult;
}
