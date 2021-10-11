#ifndef ALGORITMDPITERPOLICY_H
#define ALGORITMDPITERPOLICY_H

#include "Objects/policyunit.h"
#include "Objects/state.h"
#include "Objects/infostate.h"
#include <math.h>
#include <vector>
#include <QtDebug>

class AlgoritmDpIterPolicy: public QObject
{
    Q_OBJECT
public:
    AlgoritmDpIterPolicy();
    void StartAlgoritmDpIterPolicy(std::vector <State>*);
    public slots:
        void slotReturnInfoState(InfoState);
private:
    std::vector <PolicyUnit> currentPolicy;
    std::vector <PolicyUnit> optimalPolicy;
    double discount;
    void UpdateVpStates(std::vector <State>*);
    double CountVpState(State* st, PolicyUnit* pSt);
    void UpdateCurrentPolicy(std::vector <State>* states);
    InfoState infoState;
    signals:
        void signalGetInfoState(State*, Action);
};

#endif // ALGORITMDPITERPOLICY_H
