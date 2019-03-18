#include "Vehicle.h"

#include <sstream>
#include <iomanip>

#include <iostream>
using namespace std;

//Vehicle Construcor
Vehicle::Vehicle(string ma, string mo, string col, int y, int m) {
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

//<<, print operator to print out Vehicle info
ostream& operator << (ostream& output, Vehicle& v){
  //cout<< "car print operator" <<endl;
  ostringstream make_model;
  make_model << v.getMake() << " " << v.getModel();
  output << "\t" << setw(7) << v.getColour() << " "
               << v.getYear() << " " << setw(17) << make_model.str() << " ("
               << v.getMilage() << "km)" << endl;
  return output;
}

//2 compartive operators to compare Vehicle Objects by Year
bool Vehicle::operator < (Vehicle& v){
  if(this->year < v.getYear()){
    return true;
  }
  return false;
}

bool Vehicle::operator > (Vehicle& v){
  if(this->year > v.getYear()){
    return true;
  }
  return false;
}

//Vehicle getters
string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }
