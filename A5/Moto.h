#ifndef MOTO_H
#define MOTO_H

#include <iostream>
using namespace std;
#include "Car.h"
#include "Vehicle.h"

class Moto : public Car {

    public:
        Moto(string="", string="", string="", int=0,int=0,bool=false);
        virtual string toString();
    private:
        bool sidecar;

};

#endif
