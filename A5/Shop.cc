#include "Shop.h"
#include "defs.h"

Shop::Shop() : numMechanics(0) { }


//void Shop::addCustomer(Customer* c) { customers += c; }
Shop& Shop::operator+=(Customer* c) {
    customers += c;
    return *this;
}

Shop& Shop::operator-=(Customer* c) {
    customers -= c;
    return *this;
}

//rewritten getCustomer function
Customer* Shop::getCustomer(int i)  {
  for(int j=0; j<customers.getSize() ; j++){
    if (customers[j]->getId() == i){
      return customers[j];
    }
   }
}

LinkedList<Customer>& Shop::getCustomers() { return customers; }

//rewritten += operator to add mehanic to LinkedList
Shop& Shop::operator+=(Mechanic* m) {
    if(numMechanics < MAX_MECHANICS) {
        mechanics += m;
        numMechanics++;
    }

    return *this;
}

int Shop::getNumMechanics()     { return numMechanics; }
LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }
