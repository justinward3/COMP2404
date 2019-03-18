#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Moto.h"

using namespace std;


class VehicleFactory{
  public:
    //Car
    Vehicle* create(string,string,string,int,int);
    //Truck
    Vehicle* create(string,string,string,int,int,int);
    //MOTORCYCLE
    Vehicle* create(string,string,string,int,int,bool);
};

#endif
