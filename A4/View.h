#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"
#include "MechanicArray.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void promptVehicle(int&, Customer&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void printVehicles(Customer&);
        void printMechanic(MechanicArray&);
    private:
        int readInt() const;
};

#endif
