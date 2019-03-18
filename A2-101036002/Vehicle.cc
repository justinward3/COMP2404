#include "Vehicle.h"

//Constructor
Vehicle::Vehicle(string Mke,string Mdel,string Clr, int Yr, int Mlg){
  //Set parameters to passed in values
  make = Mke;
  model = Mdel;
  colour = Clr;
  year = Yr;
  mileage = Mlg;
}

//getters
string Vehicle::getMake(){return make;}
string Vehicle::getModel(){return model;}
string Vehicle::getColour(){return colour;}
int Vehicle::getYear(){return year;}
int Vehicle::getMilage(){return mileage;}
