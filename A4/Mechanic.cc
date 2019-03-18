#include <iostream>
using namespace std;

#include <sstream>
#include <iomanip>
#include "Mechanic.h"


//Similar to the Customer class

int Mechanic::nextId = 5000;

//Mechanics Construcor
Mechanic::Mechanic(string fname, string lname, string add, string pnum, int s)
       : id(Mechanic::nextId++), Person(fname,lname,add,pnum)
         {
           //set salary
           salary = s;
    /*
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
    */
}

int           Mechanic::getId() const           { return id; }
int           Mechanic::getSalary() const       {return salary; }

// << operator to print Mechanic
ostream& operator << (ostream& output, Mechanic& m){
  //cout<<"Mechanic Print"<<endl;
  ostringstream name;
  name << m.getFname() << " " << m.getLname();

  output << "Employee ID " << m.getId() << endl << endl
         << "    Name: " << setw(40) << name.str() << endl
         << "    Address: " << setw(37) << m.getAddress() << endl
         << "    Phone Number: " << setw(32) <<  m.getPhoneNumber() << endl;

         if (m.getSalary() > 0) {
             //currNode->data->getVehicles().toString(vehicle_output);
             output << "    Salary: " << setw(32) <<  m.getSalary() << endl;
         }

  return output;
}
