//
// Created by Andy Chen on 6/10/2022.
//

#include "../includes/Payoff.h"


//void Payoff::getValue() {
//    simulator->getPrice();
//}
Payoff::Payoff() {}
Payoff::~Payoff() {}



vector<double>& Payoff::getValues() {
    return optionValues;
}

double Payoff::getMean() {
    double sumValue = 0;
    for(int i = 0; i < optionValues.size(); ++i){
        sumValue += optionValues[i];
    }
    double meanValue = sumValue / optionValues.size();
    return meanValue;
}

double Payoff::getStd() {
    double sumValue = 0;
    double sumSquare = 0;
    for(int i = 0; i < optionValues.size(); ++i) {
        sumValue += optionValues[i];
        sumSquare += pow(optionValues[i], 2);
    }
    double stdValue = (sumSquare - pow(sumValue, 2) / optionValues.size()) / (optionValues.size() - 1);
    return stdValue;
}

vector<double> Payoff::getRange() {
//    抱歉了sort
//  why要用地址???vector<double> RangeVec
    vector<double> RangeVec(2);
    double maxValue = optionValues[0];
    for(int i = 0; i < optionValues.size(); ++i) {
        if(optionValues[i] > maxValue){
            maxValue = optionValues[i];
        }
    }

    double minValue = optionValues[0];
    for(int i = 0; i < optionValues.size(); ++i) {
        if(optionValues[i] < minValue){
            minValue = optionValues[i];
        }
    }
    RangeVec.push_back(maxValue);
    RangeVec.push_back(minValue);

    return RangeVec;
}







