#include "Shop.h"
#include "defs.h"

int Shop::addCustomer(Customer* c) { customers.add(c); }

Customer* Shop::getCustomer(int i)  { customers.get(i); }

CustomerList& Shop::getCustomers() { return customers; }
