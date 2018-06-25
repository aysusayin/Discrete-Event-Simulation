//
// Created by student on 11.11.2017.
//

#include "Barista.h"

Barista::Barista(int id) {
    this->id=id;
};
Barista::Barista(const Barista &brst) {
    this->id=brst.id;
    this->runningTime=brst.runningTime;
}
Barista& Barista::operator=(const Barista &brst) {
    this->id=brst.id;
    this->runningTime=brst.runningTime;
    return *this;
}

Barista::~Barista() {

}

Barista::Barista() {}
