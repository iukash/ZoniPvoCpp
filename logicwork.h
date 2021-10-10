#ifndef LOGICWORK_H
#define LOGICWORK_H

#include "Objects/state.h"
#include "Objects/pvo.h"
#include "enviropment.h"
#include "Objects/agent.h"
#include "Algoritms/algoritmdpiterpolicy.h"
#include <vector>
#include <utility>
#include <functional>
#include <math.h>

class LogicWork: public QObject
{
    Q_OBJECT
public:
    LogicWork();
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
    template <class TempAgentState>
    Point moveToPoint(const TempAgentState &st, Action act);
    AlgoritmDpIterPolicy algDpPol;
    signals:
        void signalReturnInfoState(std::pair <double, double>);
};

#endif // LOGICWORK_H
