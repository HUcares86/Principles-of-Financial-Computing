//
// Created by Andy Chen on 6/11/2022.
//

#ifndef FIN_ALGORITHM_MC_VANILLAOPTION_H
#define FIN_ALGORITHM_MC_VANILLAOPTION_H

#include "Payoff.h"
#include <cmath>
#include <algorithm>
using namespace std;

class VanillaOption : public Payoff{
private:
    Simulator* simulator;
    char whichOption;
    double K, r, T;

public:
    VanillaOption(Simulator *simulator, char whichOption, double k);
    virtual ~VanillaOption();

public:
    virtual void calc() override;
    virtual void deletePrice() override;
};

#endif //FIN_ALGORITHM_MC_VANILLAOPTION_H
