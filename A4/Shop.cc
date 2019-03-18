#include "Shop.h"
#include "defs.h"

// += operator to add Mechanic to the MechanicArray
void Shop::operator += (Mechanic* m){
  mechanics.add(m);
}

// += operator to add Customer to CustomerList
void Shop::operator +=(Customer* c){
  customers+=(c);
}
// -= operator to remove Customer from CustomerList
void Shop::operator -=(Customer* c){
  customers-=(c);
}

//Return reference to the MechanicArray
MechanicArray& Shop::getMechanics() {
  return mechanics;
}

Customer* Shop::getCustomer(int i)  { return customers.get(i); }

CustomerList& Shop::getCustomers() { return customers; }
