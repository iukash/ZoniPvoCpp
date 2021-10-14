#ifndef LOGICWORK_H
#define LOGICWORK_H

#include "Objects/state.h"
#include "Objects/pvo.h"
#include "enviropment.h"
#include "Objects/agent.h"
#include "Algoritms/algoritmdpiterpolicy.h"
#include <vector>
#include <map>
#include <utility>
#include <functional>
#include <math.h>
#include "Objects/infostate.h"

class LogicWork: public QObject
{
    Q_OBJECT
public:
    LogicWork(int, int, int);
    ~LogicWork();
    std::vector <State> states;
    std::vector <Pvo> pvoes;
    Point finish;
    State* findState(Point pnt);
    Agent agent;
    double agentMoveGetReward(Action, bool);
    public slots:
        void slotStartAlgoritm(Alg alg);
        void slotGetInfoState(State*, Action);
private:
    void updateRewardPvo(void);
    void drawRoute(void);
    std::map<Action, double> rewardforMove;
    template <class TempAgentState>
    Point moveToPoint(const TempAgentState &st, Action act);
    AlgoritmDpIterPolicy algDpPol;
    signals:
        void signalReturnInfoState(InfoState);
        void signalDrawRoute(std::vector<State* >);
};

#endif // LOGICWORK_H
