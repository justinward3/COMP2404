#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "Mechanic.h"
#include "MechanicArray.h"
#include "CustomerList.h"
#include "defs.h"

class Shop{

    public:
        void operator +=(Customer*);
        void operator +=(Mechanic*);
        void operator -=(Customer*);
        Customer* getCustomer(int);
        CustomerList& getCustomers();
        MechanicArray& getMechanics();

    private:
        CustomerList customers;
        MechanicArray mechanics;

};

#endif
