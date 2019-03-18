#include "Truck.h"

//Truck constructor
Truck::Truck(string ma, string mo, string col, int y, int m, int a) :
    Car(ma ,mo ,col, y, m),axles(a)  { };

//Truck toString method
string  Truck::toString()     {
  ostringstream output;
  ostringstream make_model;
  make_model << make << " " << model;

  output << "TRUCK:"<<"\t" << setw(7) << colour << " " << year << " " << setw(17);
  output << make_model.str() << " (" << mileage << "km)" <<", "<< axles<<" axles"<< endl;

  string temp = output.str();
  return temp;
 }
