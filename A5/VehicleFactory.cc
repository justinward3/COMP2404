#include "VehicleFactory.h"
using namespace std;

//Factory create for a Car
Vehicle* VehicleFactory::create(string ma,string mo, string col, int y, int m){
  Car* newCar;
  newCar = new Car(mo,ma,col,y,m);
  return newCar;
}

//Factory create for a MOTORCYCLE
Vehicle* VehicleFactory::create(string ma,string mo, string col, int y, int m, bool s){
  Moto* newMoto;
  newMoto = new Moto(mo,ma,col,y,m,s);
  return newMoto;
}

//Factory create for a Truck
Vehicle* VehicleFactory::create(string ma,string mo, string col, int y, int m, int a){
  Truck* newTruck;
  newTruck = new Truck(mo,ma,col,y,m,a);
  return newTruck;
}
