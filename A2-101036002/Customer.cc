#include <iostream>
using namespace std;
#include "Customer.h"

//Constructor
Customer::Customer(string Fn ,string Ln, string Ad, string Pn){
  //Set parameters to passed in values
  firstName = Fn;
  lastName = Ln;
  address = Ad;
  phoneNumber = Pn;
  id = nextId;
  nextId++;
  //cout<<firstName<<endl<<lastName<<endl;
}
//Set nextId
int Customer::nextId = 1000;

//getters
int Customer::getId(){ return id;}
string Customer::getFname(){ return firstName;}
string Customer::getLname(){ return lastName;}
string Customer::getAddress(){ return address;}
string Customer::getPhoneNumber(){ return phoneNumber;}
int Customer::getNumVehicles(){ return vehicles.getSize();}
VehicleArray& Customer::getVehicles(){return vehicles;}
//Add vehicle to VehicleArray
int Customer::addVehicle(Vehicle* v){
  return vehicles.add(v);
}
