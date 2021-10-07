#ifndef LOGICWORK_H
#define LOGICWORK_H

#include "Objects/state.h"
#include "Objects/pvo.h"
#include "enviropment.h"
#include "Objects/agent.h"
#include <vector>

class LogicWork
{
public:
    LogicWork();
    ~LogicWork();
    std::vector <State> states;
    std::vector <Pvo> pvoes;
    Point finish;
    State* findState(Point pnt);
    Agent agent;
private:
    void updateRewardPvo(void);
};

#endif // LOGICWORK_H
