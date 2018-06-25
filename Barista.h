//
// Created by student on 11.11.2017.
//

#ifndef PROJECT2_AYSU_SAYIN_2016400051_BARISTA_H
#define PROJECT2_AYSU_SAYIN_2016400051_BARISTA_H


class Barista {
    int id;

public:
    double runningTime;
    bool isBusy=false;

    Barista();
    Barista(int id);
    Barista(const Barista &brst);
    Barista& operator=(const Barista &brst);
    virtual ~Barista();
};


#endif //PROJECT2_AYSU_SAYIN_2016400051_BARISTA_H
