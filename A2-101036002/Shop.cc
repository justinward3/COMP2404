#include "Shop.h"
#include "defs.h"

//Add customer to CustomerArray
int Shop::addCustomer(Customer* c) { return customers.add(c); }
//Get customer from CustomerArray
Customer& Shop::getCustomer(int i)  { return *(customers.get(i)); }
//Get all customers from CustomerArray
CustomerArray& Shop::getCustomers() { return customers; }
