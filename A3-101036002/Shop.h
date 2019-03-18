#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerList.h"

class Shop{

    public:
        int addCustomer(Customer*);
        Customer* getCustomer(int);
        CustomerList& getCustomers();


    private:
        CustomerList customers;

};

#endif
