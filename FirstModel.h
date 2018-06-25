//
// Created by student on 10.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_FIRSTMODEL_H
#define PROJECT2_AYSU_SAYIN_2016400051_FIRSTMODEL_H


#include "Customer.h"
#include "Event.h"
#include "Cashier.h"
#include "Barista.h"
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class FirstModel {
    int cashierNo;
    vector<Customer> customers;
    vector<Cashier> cashiers;
    vector<Barista> baristas;

    //customer id stored
    queue<int> cashierQueue;
    int maxCashierQueueLength=0;

    //customers stored
    priority_queue<Customer> baristaQueue;
    int maxBaristaQueueLength=0;

    priority_queue<Event>events;
    //working time of the Starbucks
    double workingTime=0;

    void createSimulator();

public:
    FirstModel(int N,vector<Customer> *input);
    FirstModel(const FirstModel &firstModel);
    virtual ~FirstModel();

    const vector<Customer> &getCustomers() const;

    const vector<Cashier> &getCashiers() const;

    const vector<Barista> &getBaristas() const;

    int getMaxCashierQueueLength() const;

    int getMaxBaristaQueueLength() const;

    double getWorkingTime() const;


};


#endif //PROJECT2_AYSU_SAYIN_2016400051_FIRSTMODEL_H
