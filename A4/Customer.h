#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
#include "Person.h"

class Customer: public Person {
    friend ostream& operator<<(ostream&, Customer&);

    public:

        Customer(string="", string="", string="", string="");

        int getId() const;

        /*
        string getFname() ;
        string getLname() ;
        string getAddress() ;
        string getPhoneNumber() ;
        */

        int getNumVehicles() const;
        VehicleList& getVehicles();

        void operator += (Vehicle*);
        bool operator < (Customer&);
        bool operator > (Customer&);

    private:

        static int nextId;

        const int id;
        /*
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
        */
        VehicleList vehicles;
};

#endif
