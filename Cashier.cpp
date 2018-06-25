//
// Created by student on 11.11.2017.
//

#include "Cashier.h"

Cashier::Cashier(int id) {
    this->id=id;
    this->runningTime=0;
}
Cashier::Cashier(const Cashier &cash) {
    this->id=cash.id;
    this->runningTime=cash.runningTime;
}
Cashier& Cashier::operator=(const Cashier &cash){
    this->id=cash.id;
    this->isBusy=cash.isBusy;
    this->runningTime=cash.runningTime;
    return *this;

}

Cashier::~Cashier() {
}
