//
// Created by Andy Chen on 6/10/2022.
//

#ifndef FIN_ALGORITHM_MC_PAYOFF_H
#define FIN_ALGORITHM_MC_PAYOFF_H
#include "Simulator.h"
#include <cmath>
#include <algorithm>
using namespace std;

class Payoff {
public:
    // constructor and destructor
    Payoff();
    virtual ~Payoff();
    // store the option values for every simulation
    vector<double> optionValues;

    // override method
    virtual void calc() = 0;
    virtual void deletePrice() = 0;

    // get the simulation statistic summary result
    vector<double>& getValues();
    double getMean();
    double getStd();
    vector<double> getRange();


};



#endif //FIN_ALGORITHM_MC_PAYOFF_H
