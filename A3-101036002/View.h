#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&);
        void pause();
        void getCustomerDetails(string&,string&,string&,string&);
        void getId(int&);
        void getVehicleDetails(string&,string&,string&,int&,int&);
        void printError(string);

    private:
        int readInt();
};

#endif
