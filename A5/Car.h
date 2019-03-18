#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;
#include "Vehicle.h"

class Car : public Vehicle {

    public:
        Car(string="", string="", string="", int=0,int=0);
        virtual string toString();
    private:

};

#endif
