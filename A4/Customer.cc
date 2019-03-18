#include <iostream>
using namespace std;

#include <sstream>
#include <iomanip>
#include "Customer.h"


int Customer::nextId = 1000;

//Constructor for Customer
Customer::Customer(string fname, string lname, string add, string pnum)
       : id(Customer::nextId++), Person(fname,lname,add,pnum)
         {
    //Inherited from Person now
    /*
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
    */
}

int           Customer::getId() const           { return id; }

/*
//Inherited from Person now
string        Customer::getFname()         { return Person::getFname(); }
string        Customer::getLname()         { return Person::getLname(); }
string        Customer::getAddress()       { return Person::getAddress(); }
string        Customer::getPhoneNumber()   { return Person::getPhoneNumber();}
*/

int           Customer::getNumVehicles() const  { return vehicles.getSize(); }
VehicleList&  Customer::getVehicles()           { return vehicles; }


// += operator to add Vehicle to the VehicleList in Customer
void Customer::operator += (Vehicle* v){
  vehicles+=v;
}

//Two compartive operators ( < and >)  to compare Customer Objects by Last Name
bool Customer::operator < (Customer& c){
  if (getLname() < c.getLname()){
    return true;
  }
  return false;
}

bool Customer::operator > (Customer& c){
  if (getLname() > c.getLname()){
    return true;
  }
  return false;
}

// << Operator to print a customer object
ostream& operator << (ostream& output, Customer& c){
  
  ostringstream name;
  name << c.getFname() << " " << c.getLname();

  output << "Customer ID " << c.getId() << endl << endl
         << "    Name: " << setw(40) << name.str() << endl
         << "    Address: " << setw(37) << c.getAddress() << endl
         << "    Phone Number: " << setw(32) <<  c.getPhoneNumber() << endl;


         output << endl << "    " << c.getNumVehicles()
                   << " vehicle(s): " << endl << endl;

         if (c.getNumVehicles() > 0) {
             //Calls the << operator in VehicleList to print Vehicles
             output << c.getVehicles() << endl<<endl;
         }

  return output;
}
