//
// Created by student on 10.11.2017.
//

#include <iostream>
#include "Customer.h"

Customer::Customer(int id,double arrivalTime, double orderTime, double brewTime, double price) : id(id), arrivalTime(arrivalTime), orderTime(orderTime), brewTime(brewTime), price(price) {
}
Customer::Customer(const Customer &customer) {
    this->id=customer.id;
    this->arrivalTime=customer.arrivalTime;
    this->leavingTime=customer.leavingTime;
    this->brewTime=customer.brewTime;
    this->orderTime=customer.orderTime;
    this->price=customer.price;
}

Customer::~Customer() {
}

Customer& Customer::operator=(const Customer &customer) {
    this->id=customer.id;
    this->arrivalTime=customer.arrivalTime;
    this->leavingTime=customer.leavingTime;
    this->brewTime=customer.brewTime;
    this->orderTime=customer.orderTime;
    this->price=customer.price;
    return *this;
}

int Customer::getId() const {
    return this->id;
}

double Customer::getArrivalTime() const {
    return arrivalTime;
}

double Customer::getLeavingTime() const {
    return leavingTime;
}

double Customer::getOrderTime() const {
    return orderTime;
}

double Customer::getBrewTime() const {
    return brewTime;
}

double Customer::getPrice() const {
    return price;
}

void Customer::setLeavingTime(double leavingTime) {
    this->leavingTime = leavingTime;
}

Customer::Customer() {
}

bool Customer::operator<(const Customer &rhs) const {
    return price < rhs.price;
}

bool Customer::operator>(const Customer &rhs) const {
    return rhs.price < this->price;
}

bool Customer::operator<=(const Customer &rhs) const {
    return !(rhs.price < this->price);
}

bool Customer::operator>=(const Customer &rhs) const {
    return !(this->price < rhs.price);
}



