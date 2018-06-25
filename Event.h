//
// Created by student on 10.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_EVENT_H
#define PROJECT2_AYSU_SAYIN_2016400051_EVENT_H


class Event {
    /* chars represent events type
        a:entry to starbucks
        c:exit from cashier
        q:exit from starbucks
       */
    char event;
    //time of the event
    double time;
    //the customer who is doing this event
    int customerID;
public:
    //the employee who is doing this event(if it is entry employee is -1)
    int currentEmployeeID=-1;


public:
    Event(int custID, char event, double time);
    Event(int custID, char event, double time, int curEmpID);
    Event(const Event &copyEvent);
    Event &operator=(const Event &copyEvent);

    char getEvent() const;

    double getTime() const;

    int getCustomerID() const;

    virtual ~Event();

    bool operator<(const Event &rhs) const;

    bool operator>(const Event &rhs) const;

    bool operator==(const Event &rhs) const;

    bool operator!=(const Event &rhs) const;

    bool operator<=(const Event &rhs) const;

    bool operator>=(const Event &rhs) const;

};


#endif //PROJECT2_AYSU_SAYIN_2016400051_EVENT_H
