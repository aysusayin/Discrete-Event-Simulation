//
// Created by student on 10.11.2017.
//

#include "SecondModel.h"


SecondModel::SecondModel(int cashierNo, const vector<Customer> *customers) : cashierNo(cashierNo),
                                                                             customers(*customers) {
    createSimulator();
}

SecondModel::~SecondModel() {
}

void SecondModel::createSimulator() {
    //we get customer informations from input and add their entry event to the event queue

    int M= customers.size();
    for(int i=0; i<M; i++){
        Customer current= customers[i];
        Event arrival(current.getId(),'a',current.getArrivalTime());
        events.push(arrival);
    }
    //create cashiers, baristas and barista queues
    for(int i=0; i<cashierNo; i++)
        cashiers.push_back(Cashier(i));
    for(int i=0; i<cashierNo/3; i++){
        baristas.push_back(Barista(i));
        priority_queue<Customer> bq;
        baristaQueues.push_back(bq);
        maxBaristaQueueLength.push_back(0);
    }

    //the customer id who left the Starbucks last
    int lastCustomerID=-1;
    //stores the event that is popped from event queue
    Event *currentEvent;

    while(!events.empty()){
        /*a:entry to starbucks
         c:exit from cashier
         q:exit from starbucks
        */
        *currentEvent = events.top();
        events.pop();

        char eventType = currentEvent->getEvent();
        double time = currentEvent->getTime();
        int custID=currentEvent->getCustomerID();
        int currentEmpID=currentEvent->currentEmployeeID;

        if(eventType == 'a'){
            //entry event
            bool isFree=false;
            int i=0;
            //check if there is an available cashier
            for(; i<cashierNo && cashierQueue.empty(); i++){
                if(!cashiers[i].isBusy){
                    isFree=true;
                    break;
                }
                else isFree=false;
            }

            if(isFree){
                //a cashier is available
                double orderTime=customers[custID].getOrderTime();
                cashiers[i].runningTime+=orderTime;
                cashiers[i].isBusy=true;
                events.push(Event(custID,'c',time+orderTime,i));
            }else{
                //all cashiers are busy so we push customer to event queue
                cashierQueue.push(custID);
                if(maxCashierQueueLength<cashierQueue.size())
                    maxCashierQueueLength=cashierQueue.size();
            }

        }else if(eventType == 'c'){
            //exit from cashier event
            if(!cashierQueue.empty()){
                //Steps for taking customer from queue and allocating them to decent cashier
                int newCustomerID = cashierQueue.front();
                cashierQueue.pop();
                double orderTime=customers[newCustomerID].getOrderTime();
                cashiers[currentEmpID].runningTime+=orderTime;
                cashiers[currentEmpID].isBusy=true;
                events.push(Event(newCustomerID,'c',time+orderTime,currentEmpID));

            }else{
                //if no customers in queue then cashier is not busy
                cashiers[currentEmpID].isBusy=false;
            }

            //Steps for the customer who just exit cashier
            //check if the barista corresponding the cashier the customer who just left is free
            if(baristaQueues[currentEmpID/3].empty() && !baristas[currentEmpID/3].isBusy){
                double brewTime=customers[custID].getBrewTime();
                baristas[currentEmpID/3].runningTime+=brewTime;
                baristas[currentEmpID/3].isBusy=true;
                events.push(Event(custID,'q',time+brewTime,currentEmpID/3));

            }else{
                //if the barista is busy oush the customer to the baristas queue
                baristaQueues[currentEmpID/3].push(customers[custID]);
                if(maxBaristaQueueLength[currentEmpID/3]<baristaQueues[currentEmpID/3].size())
                    maxBaristaQueueLength[currentEmpID/3]=baristaQueues[currentEmpID/3].size();
            }

        } else if(eventType=='q'){
            //exit from starbucks event
            if(!baristaQueues[currentEmpID].empty()){
                //Steps for the new customer who was in barista queue
                Customer newCustomer = baristaQueues[currentEmpID].top();
                baristaQueues[currentEmpID].pop();
                int newCustomerID = newCustomer.getId();
                double brewTime=customers[newCustomerID].getBrewTime();
                baristas[currentEmpID].runningTime+=brewTime;
                events.push(Event(newCustomerID,'q',time+brewTime,currentEmpID));
            }else{
                //if no customers in queue then barista is not busy
                baristas[currentEmpID].isBusy=false;

            }

            //for the customer who just left barista
            lastCustomerID=custID;
            customers[custID].setLeavingTime(time);


        }

    }

    this->workingTime=customers[lastCustomerID].getLeavingTime()-customers[0].getArrivalTime();

}

const vector<Customer>& SecondModel::getCustomers() const {
    return this->customers;
}

const vector<Barista>& SecondModel::getBaristas() const {
    return this->baristas;
}

const vector<Cashier>& SecondModel::getCashiers() const {
    return this->cashiers;
}
int SecondModel::getMaxCashierQueueLength() const {
    return this->maxCashierQueueLength;
}
vector<int> SecondModel::getMaxBaristaQueueLengths() const {
    return this->maxBaristaQueueLength;
}
double SecondModel::getWorkingTime() const {
    return this->workingTime;
}