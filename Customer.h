//
// Created by student on 10.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_CUSTOMER_H
#define PROJECT2_AYSU_SAYIN_2016400051_CUSTOMER_H


class Customer {
    int id;
    double arrivalTime;
    double leavingTime=-1;
    double orderTime;
    double brewTime;
    double price;
public:
    Customer();
    Customer(int id, double arrivalTime, double orderTime, double brewTime, double price);
    Customer(const Customer &customer);
    virtual ~Customer();
    Customer& operator=(const Customer &customer);
    double getArrivalTime() const;

    double getLeavingTime() const;

    double getOrderTime() const;

    double getBrewTime() const;

    double getPrice() const;

    int getId() const;

    void setLeavingTime(double leavingTime);

    bool operator<(const Customer &rhs) const;

    bool operator>(const Customer &rhs) const;

    bool operator<=(const Customer &rhs) const;

    bool operator>=(const Customer &rhs) const;
};


#endif //PROJECT2_AYSU_SAYIN_2016400051_CUSTOMER_H
