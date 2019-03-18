#include <string>
#include "Person.h"
using namespace std;

//Person Constructor
Person::Person(string fname, string lname, string add , string pnum){

  firstName   = fname;
  lastName    = lname;
  address     = add;
  phoneNumber = pnum;

}


//Person Getter Fucntions
string        Person::getFname() const        { return firstName; }
string        Person::getLname() const        { return lastName; }
string        Person::getAddress() const      { return address; }
string        Person::getPhoneNumber() const   { return phoneNumber; }
