#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
using namespace std;
#include "Car.h"
#include "Vehicle.h"

class Truck : public Car {

    public:
        Truck(string="", string="", string="", int=0,int=0,int=0);
        virtual string toString();
    private:
        int axles;

};

#endif
