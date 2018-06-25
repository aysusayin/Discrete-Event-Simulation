//
// Created by student on 11.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_CASHIER_H
#define PROJECT2_AYSU_SAYIN_2016400051_CASHIER_H


class Cashier {
    int id;

public:
    double runningTime;
    bool isBusy=false;

    Cashier(int id);
    Cashier(const Cashier &cash);
    Cashier& operator=(const Cashier &cash);
    virtual ~Cashier();
};


#endif //PROJECT2_AYSU_SAYIN_2016400051_CASHIER_H
