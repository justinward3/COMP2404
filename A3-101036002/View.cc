#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Enter a new Customer\n\n";
    cout<< "        3. Enter a new Vehicle\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 3) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

void View::getCustomerDetails(string& fn, string& ln, string& ad, string& pN){
   cout << "First Name:" << endl;
   getline(cin, fn);
   cout << "Last Name :" << endl;
   getline(cin, ln);
   cout << "Address:" << endl;
   getline(cin, ad);
   cout << "Phone Number:" << endl;
   getline(cin, pN);
   }

void View::getVehicleDetails(string& make,string& model,string& color,int& year,int& KM){
     cout << "Make :" << endl;
     getline(cin, make);
     cout << "Model:" << endl;
     getline(cin, model);
     cout << "Color:" << endl;
     getline(cin, color);
     cout << "Year:" << endl;
     year = readInt();
     cout << "Mileage:" << endl;
     KM = readInt();

}

void View::getId(int& id){
    cout << "Customer ID :" << endl;
    id = readInt();
}

void View::printError(string s){
  cout << s << endl;
}
void View::printCustomers(CustomerList& list) {
    string text;
    list.toString(text);
    cout << text << endl;
    /*
    for (int i = 0; i < list.getSize(); i++) {

        Customer* cust = arr.get(i);
        ostringstream name;
        name << cust->getFname() << " " << cust->getLname();

        cout << "Customer ID " << cust->getId() << endl << endl
             << "    Name: " << setw(40) << name.str() << endl
             << "    Address: " << setw(37) << cust->getAddress() << endl
             << "    Phone Number: " << setw(32) <<  cust->getPhoneNumber() << endl;

        if (cust->getNumVehicles() > 0) {
             cout << endl << "    " << cust->getNumVehicles()
                  << " vehicle(s): " << endl << endl;
        }

        VehicleArray& varr = cust->getVehicles();
        for (int j = 0; j < varr.getSize(); j++) {
            Vehicle* v = varr.get(j);
            ostringstream make_model;
            make_model << v->getMake() << " " << v->getModel();

            cout << "\t" << j+1 << ") " << setw(7) << v->getColour() << " "
                 << v->getYear() << " " << setw(17) << make_model.str() << " ("
                 << v->getMilage() << "km)" << endl;
        }

        cout << endl << endl;
    }
    */
}



void View::pause() {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
