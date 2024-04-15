//
// Created by Andy Chen on 6/11/2022.
//

#ifndef FIN_ALGORITHM_MC_ASIANOPTION_H
#define FIN_ALGORITHM_MC_ASIANOPTION_H

#include "Payoff.h"
#include <cmath>
#include <algorithm>
using namespace std;

class AsianOption : public Payoff{
private:
    Simulator* simulator;
    char whichOption;
    double K, r, T;
public:
    AsianOption(Simulator *simulator, char whichOption, double k);
    virtual ~AsianOption();

public:
    virtual void calc() override;
    virtual void deletePrice() override;
};






#endif //FIN_ALGORITHM_MC_ASIANOPTION_H
