#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "MechanicArray.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n";
    cout<< "        3. Add Vehicle\n\n";
    cout<< "        4. Remove Customer\n\n";
    cout<< "        5. Remove Vehicle\n\n";
    cout<< "        6. Print Mechanics\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 7) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

void View::displayInvalid() { cout << "Invalid choice." << endl << endl; }

void View::promptUserInfo(string &fname, string &lname, string &address, string &phone) {
    cout << "\nFirst name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone number: ";
    getline(cin, phone);
    cout<<endl;
}

void View::promptVehicleInfo(string &make, string &model, string &colour,
                                int &year, int &mileage) {
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    cout<<endl;
}

void View::promptUserId(int &id) {
    cout << "Customer ID: ";
    id = readInt();
    cout<<endl;
}

void View::promptVehicle(int &id, Customer& c) {
    cout << "Vehicle (Enter 0-"<< c.getNumVehicles() - 1 <<"#): ";
    id = readInt();
    cout<<endl;
}

void View::printCustomers(CustomerList& arr) const {
    cout << endl << "CUSTOMERS: " << endl << endl;

    stringstream output;

    cout << arr << endl;

    /*
    for (int i = 0; i < arr.getSize(); i++) {

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

//print the mechanics using the MechanicArray, << operator
void View::printMechanic(MechanicArray& arr){
  cout << endl << "MECHANICS: " << endl << endl;

    cout<<arr<<endl;

}

//print vehicles, using the VehicleList, << operator
void View::printVehicles(Customer& c){
  //cout<<"PRINT CARS"<<endl;
  cout<<c.getVehicles()<<endl;
}
void View::pause() const {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() const {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
