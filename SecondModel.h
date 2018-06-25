//
// Created by student on 10.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_SECONDMODEL_H
#define PROJECT2_AYSU_SAYIN_2016400051_SECONDMODEL_H


#include <vector>
#include <queue>
#include "Customer.h"
#include "Cashier.h"
#include "Barista.h"
#include "Event.h"

using namespace std;

class SecondModel {
    int cashierNo;
    vector<Customer> customers;
    vector<Cashier> cashiers;
    vector<Barista> baristas;
    //barista queues stored in vector
    vector<priority_queue<Customer>> baristaQueues;
    vector<int> maxBaristaQueueLength;

    //customer id stored
    queue<int> cashierQueue;
    int maxCashierQueueLength=0;
    priority_queue<Event>events;
    double workingTime=0;

    void createSimulator();
public:
    const vector<Customer> &getCustomers() const;

    const vector<Cashier> &getCashiers() const;

    const vector<Barista> &getBaristas() const;

    int getMaxCashierQueueLength() const;

    vector<int> getMaxBaristaQueueLengths() const;

    double getWorkingTime() const;

    SecondModel(int cashierNo, const vector<Customer> *customers);
    SecondModel(const SecondModel &secondModel);
    virtual ~SecondModel();

};


#endif //PROJECT2_AYSU_SAYIN_2016400051_SECONDMODEL_H
