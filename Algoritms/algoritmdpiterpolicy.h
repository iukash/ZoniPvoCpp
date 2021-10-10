#ifndef ALGORITMDPITERPOLICY_H
#define ALGORITMDPITERPOLICY_H

#include "Objects/policyunit.h"
#include "Objects/state.h"
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
        void slotReturnInfoState(std::pair <double, double>);
private:
    std::vector <PolicyUnit> currentPolicy;
    std::vector <PolicyUnit> optimalPolicy;
    double discount;
    void UpdateVpStates(std::vector <State>*);
    double CountVpState(State* st, PolicyUnit* pSt);
    void UpdateCurrentPolicy(std::vector <State>* states);
    std::pair <double, double> pairState;
    signals:
        void signalGetInfoState(State*, Action);
};

#endif // ALGORITMDPITERPOLICY_H
