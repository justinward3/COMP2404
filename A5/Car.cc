#include "Car.h"

//Car constructor
Car::Car(string ma, string mo, string col, int y, int m) :
    Vehicle(ma ,mo ,col, y, m) { };

//toString methond
string  Car::toString()     {
  ostringstream output;
  ostringstream make_model;
  make_model << make << " " << model;

  output << "CAR:"<<"\t" << setw(7) << colour << " " << year << " " << setw(17);
  output << make_model.str() << " (" << mileage << "km)" << endl;

  string temp = output.str();
  return temp;
 }
