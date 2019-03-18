#include "Moto.h"

//MOTORCYCLE constructor
Moto::Moto(string ma, string mo, string col, int y, int m, bool s) :
    Car(ma ,mo ,col, y, m),sidecar(s)  { };

//MOTORCYCLE toString method
string  Moto::toString()     {
  ostringstream output;
  ostringstream make_model;
  make_model << make << " " << model;

  output << "MOTORCYCLE:"<<"\t" << setw(7) << colour << " " << year << " " << setw(17);
  if(sidecar){
    output << make_model.str() << " (" << mileage << "km)" <<", "<< " has a sidecar"<< endl;
  }
  else{
  output << make_model.str() << " (" << mileage << "km)" <<", "<< " does not have a sidecar"<< endl;
  }

  string temp = output.str();
  return temp;
 }
