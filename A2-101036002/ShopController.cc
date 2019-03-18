#include "ShopController.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

ShopController::ShopController() {

    initCustomers();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);

        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } /*else if (choice == 2) {

        } else if (choice == 3) {

        } else if (choice == 4) {

        } ... */

        else {
            break;
        }
    }
}


void ShopController::initCustomers() {

    //add data fill here
    Customer* c1;
    Customer* c2;
    Customer* c3;
    Customer* c4;
    Customer* c5;
    Customer* c6;
    c1 = new Customer("Maurice","Maurice","2600 Colonel By Dr.","(613)-728-9568");
    c2 = new Customer("Abigail","Abigail","43 Carling Dr.","(613)-345-6743");
    c3 = new Customer("Brook","Brook","1 Bayshore Dr.","(613)-123-7456");
    c4 = new Customer("Ethan","Ethan"," 245 Rideau St.","(613)234-9677 ");
    c5 = new Customer("Eve","Eve"," 75 Bronson Ave.","(613)456-2345 ");
    c6 = new Customer("Victor","Victor"," 425 O'Connor St. ","(613)432-7622 ");

    Vehicle* v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10,*v11,*v12;

    v1 = new Vehicle("Ford","Fiesta","Red",2007,100000);
    v2 = new Vehicle("Subaru","Forester","Green",2016,40000);
    v3 = new Vehicle("Honda","Accord","White",2018,5000);
    v4 = new Vehicle("Volkswagon","Beetle","White",1972,5000);
    v5 = new Vehicle("Toyota","Camry","Black",2010,50000);
    v6 = new Vehicle("Toyota","Corolla","Green",2013,80000);
    v7 = new Vehicle("Toyota","Rav4","Gold",2015,20000);
    v8 = new Vehicle("Toyota","Prius","Blue",2017,10000);
    v9 = new Vehicle("GM","Envoy","Purple",2012,60000);
    v10 = new Vehicle("GM","Escalade","Black",2016,40000);
    v11 = new Vehicle("GM","Malibu","Red",2015,20000);
    v12 = new Vehicle("GM","Trailblazer","Orange",2012,90000);
    c1->addVehicle(v1);
    c2->addVehicle(v2);
    c3->addVehicle(v3); c3->addVehicle(v4);
    c4->addVehicle(v5);
    c5->addVehicle(v6); c5->addVehicle(v7); c5->addVehicle(v8);
    c6->addVehicle(v9); c6->addVehicle(v10); c6->addVehicle(v11); c6->addVehicle(v12);
    mechanicShop.addCustomer(c1);
    mechanicShop.addCustomer(c2);
    mechanicShop.addCustomer(c3);
    mechanicShop.addCustomer(c4);
    mechanicShop.addCustomer(c5);
    mechanicShop.addCustomer(c6);

    


}
