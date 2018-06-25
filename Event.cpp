//
// Created by student on 10.11.2017.
//

#include "Event.h"

Event::Event(int custID, char event, double time) : customerID(custID), event(event), time(time) {}
Event::Event(const Event &copyEvent) {
    this->customerID = copyEvent.customerID;
    this->currentEmployeeID = copyEvent.currentEmployeeID;
    this->event=copyEvent.event;
    this->time=copyEvent.time;
}
Event& Event::operator=(const Event &copyEvent) {
    this->customerID = copyEvent.customerID;
    this->currentEmployeeID = copyEvent.currentEmployeeID;
    this->event=copyEvent.event;
    this->time=copyEvent.time;
    return *this;
}
Event::Event(int custID, char event, double time, int curEmpID): customerID(custID), event(event), time(time), currentEmployeeID(curEmpID) {}
Event::~Event() {}

bool Event::operator<(const Event &rhs) const {
    return time > rhs.time;
}

bool Event::operator>(const Event &rhs) const {
    return rhs.time > this->time;
}

bool Event::operator<=(const Event &rhs) const {
    return !(rhs.time > this->time);
}

bool Event::operator>=(const Event &rhs) const {
    return !(this->time > rhs.time);
}

bool Event::operator==(const Event &rhs) const {
    return event == rhs.event &&
           customerID == rhs.customerID;
}

bool Event::operator!=(const Event &rhs) const {
    return !(event == rhs.event &&
             customerID == rhs.customerID);
}

char Event::getEvent() const {
    return event;
}

double Event::getTime() const {
    return time;
}

int Event::getCustomerID() const {
    return customerID;
}
