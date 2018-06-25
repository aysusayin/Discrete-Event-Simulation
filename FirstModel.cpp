//
// Created by student on 10.11.2017.
//

#include <iostream>
#include "FirstModel.h"

FirstModel::FirstModel(int N, vector<Customer> *input) : cashierNo(N), customers(*input) {
    createSimulator();
};
FirstModel::~FirstModel() {
}

void FirstModel::createSimulator() {
//we get customer informations from input and add their entry event to the event queue
    int M= customers.size();
    for(int i=0; i<M; i++){
        Customer current= customers[i];
        Event arrival(current.getId(),'a',current.getArrivalTime());
        events.push(arrival);
    }

    //create cashiers and baristas
    for(int i=0; i<cashierNo; i++)
        cashiers.push_back(Cashier(i));
    for(int i=0; i<cashierNo/3; i++)
        baristas.push_back(Barista(i));

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
                cashiers[i].runningTime+=orderTime;//increase cashiers running time
                cashiers[i].isBusy=true; //set cashier busy
                events.push(Event(custID,'c',time+orderTime,i));//create an exit from cashier event for current customer and push event queue
            }else{
                //all cashiers are busy so we push customer to event queue
                cashierQueue.push(custID);
                if(maxCashierQueueLength<cashierQueue.size())
                    maxCashierQueueLength=cashierQueue.size();
            }

        }else if(eventType == 'c'){
            //exit from cashier event
            if(!cashierQueue.empty()){
                //Steps for taking new customer from queue and allocating them to decent cashier
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
            bool isFree=false;
            int i=0;
            //check if baristas are busy
            for(; i<cashierNo/3 && baristaQueue.empty(); i++){
                if(!baristas[i].isBusy){
                    isFree=true;
                    break;
                }
                else isFree=false;
            }
            if(isFree){
                //a barista is available so create an exit from starbucks event and push event queue
                double brewTime=customers[custID].getBrewTime();
                baristas[i].runningTime+=brewTime;
                baristas[i].isBusy=true;
                events.push(Event(custID,'q',time+brewTime,i));

            }else{
                //all baristas are busy so push customer to barista queue
                baristaQueue.push(customers[custID]);
                if(maxBaristaQueueLength<baristaQueue.size())
                    maxBaristaQueueLength=baristaQueue.size();
            }

        } else if(eventType=='q'){
            //exit from starbucks event
            if(!baristaQueue.empty()){
                //Steps for the new customer who was in barista queue
                int newCustomerID = baristaQueue.top().getId();
                baristaQueue.pop();
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

const vector<Customer> &FirstModel::getCustomers() const {
    return customers;
}

const vector<Cashier> &FirstModel::getCashiers() const {
    return cashiers;
}

const vector<Barista> &FirstModel::getBaristas() const {
    return baristas;
}

int FirstModel::getMaxCashierQueueLength() const {
    return maxCashierQueueLength;
}

int FirstModel::getMaxBaristaQueueLength() const {
    return maxBaristaQueueLength;
}

double FirstModel::getWorkingTime() const {
    return workingTime;
}


