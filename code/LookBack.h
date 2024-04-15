//
// Created by 林大中 on .
//

#ifndef FIN_ALGORITHM_MC_LOOKBACK_H
#define FIN_ALGORITHM_MC_LOOKBACK_H
#include "Payoff.h"

class LookBack final : public Payoff {
private:
    Simulator* simulator;
    char whichOption;
public:
    void calc() override;

    void deletePrice() override;

public:
    LookBack(Simulator *simulator, char whichOption);

    virtual ~LookBack();

};


#endif //FIN_ALGORITHM_MC_LOOKBACK_H

