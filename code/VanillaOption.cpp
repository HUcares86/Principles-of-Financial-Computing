//
// Created by Andy Chen on 6/11/2022.
//

#include "../includes/VanillaOption.h"

VanillaOption::VanillaOption(Simulator* simulator, char whichOption, double k) : simulator(simulator),
whichOption(whichOption),K(k), r(simulator->getR()),T(simulator->getT()) {
    calc();
    deletePrice();
}
VanillaOption::~VanillaOption() {}

void VanillaOption::calc() {
    const array3d& totalPrice = simulator->getPrice();
    for(int i = 0; i < totalPrice.size(); ++i){
        double sumPayoff = 0;
        for(int j = 0; j < totalPrice[0].size(); ++j){
            if (whichOption == 'C'){
                sumPayoff += max<double>(totalPrice[i][j][totalPrice[0][0].size() - 1] - K, 0);
            } else if(whichOption == 'P'){
                sumPayoff += max<double>(K - totalPrice[i][j][totalPrice[0][0].size() - 1], 0);
            }
        }
        double avePayoff = sumPayoff / totalPrice[0].size();
        double discountedValue = avePayoff * exp( -r * T);
        optionValues.push_back(discountedValue);
    }
}

void VanillaOption::deletePrice() {
    delete simulator;
}










