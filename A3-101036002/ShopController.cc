#include "ShopController.h"

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
        } else if (choice == 2) {
            addCustomer();
            view.pause();
        } else if (choice == 3) {
            addVehicle();
            view.pause();
        }
        /*else if (choice == 4) {

        } ... */

        else {
            break;
        }
    }
}

//to add a customer to Shop
void ShopController::addCustomer(){
  //init variables
  Customer* newCustomer;
  string FirstName;
  string LastName;
  string address;
  string phoneNumber;
  //Get user input from view
  view.getCustomerDetails(FirstName,LastName,address,phoneNumber);
  //Create new customer and add to shop
  newCustomer = new Customer(FirstName,LastName,address,phoneNumber);
  mechanicShop.addCustomer(newCustomer);
}

//to add a vehicle to Shop
void ShopController::addVehicle(){
  //init variables
  Vehicle* newVehicle;
  int id = 0;
  string make;
  string model;
  string color;
  int year;
  int KM;
  //Get Id from User in view
  view.getId(id);
  //If not NULL
  if(mechanicShop.getCustomer(id)){
    //Get Vehicle info from user from the view
    view.getVehicleDetails(make,model,color,year,KM);
    //Create new Vehicle and add to Customer in Shop
    newVehicle = new Vehicle(make,model,color,year,KM);
    mechanicShop.getCustomer(id)->addVehicle(newVehicle);
  }
  else{
    //Tell view to print "Invalid Customer"
    view.printError("Invalid Customer ID");
  }
}

void ShopController::initCustomers() {

    Customer* newCustomer;
    Vehicle* newVehicle;

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.",
                                        "(613)728-9568");
    newVehicle = new Vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.",
                                        "(613)345-6743");
    newVehicle = new Vehicle("Subaru", "Forester", "Green", 2016, 40000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.",
                                        "(613)123-7456");
    newVehicle = new Vehicle("Honda", "Accord", "White", 2018, 5000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Volkswagon", "Beetle", "White", 1972, 5000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.",
                                        "(613)234-9677");
    newVehicle = new Vehicle("Toyota", "Camry", "Black", 2010, 50000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.",
                                        "(613)456-2345");
    newVehicle = new Vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Toyota", "Prius", "Blue", 2017, 10000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.",
                                        "(613)432-7622");
    newVehicle = new Vehicle("GM", "Envoy", "Purple", 2012, 60000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Escalade", "Black", 2016, 40000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Malibu", "Red", 2015, 20000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Trailblazer", "Orange", 2012, 90000);
    newCustomer->addVehicle(newVehicle);
    //newVehicle = new Vehicle("GM", "Vue", "Blue", 2015, 20000);
    //newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);

}
