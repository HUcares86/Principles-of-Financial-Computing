//
// Created by Andy Chen on 6/11/2022.
//

#include "../includes/AsianOption.h"


AsianOption::AsianOption(Simulator *simulator, char whichOption, double k) : simulator(simulator),
whichOption(whichOption), K(k), r(simulator->getR()), T(simulator->getT()) {
    calc();
    deletePrice();
}

AsianOption::~AsianOption() {}

void AsianOption::calc() {
    const array3d& totalPrice = simulator->getPrice();
    for(int i = 0; i < totalPrice.size(); ++i) {
        double sumPayoff = 0;
        for (int j = 0; j < totalPrice[0].size(); ++j) {
            double sumPrice = 0;
            for(int m = 0; m < totalPrice[0][0].size(); ++m){
                sumPrice += totalPrice[i][j][m];
            }
            double avePrice = sumPrice / totalPrice[0][0].size();
            if(whichOption == 'C'){
                sumPayoff += max<double>(avePrice - K, 0);
            } else if(whichOption == 'P'){
                sumPayoff += max<double>(K - avePrice, 0);
            }
        }
        double avePayoff = sumPayoff / totalPrice[0].size();
        double discountedValue = avePayoff * exp(-r * T);
        optionValues.push_back(discountedValue);

    }

}

void AsianOption::deletePrice() {
    delete simulator;
}



