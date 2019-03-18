#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

typedef struct {

	// ADD MEMBER VARIABLES
  //Init detail variables of a Vehicle
  char make[MAX_STR];
  char model[MAX_STR];
  char colour[MAX_STR];
  int year;
  int mileage;

} VehicleType;

typedef struct {

	// ADD MEMBER VARIABLES
  //Init detail vaiables of a Customer
  char firstName[MAX_STR];
  char lastName[MAX_STR];
  int numVehicles;
  VehicleType ownedVehicles[MAX_VEHICLES];

} CustomerType;

void print_vehicle(VehicleType *v) {
  //if vehicle is provided, print all vehicle details
  if( v != NULL){
    printf("%d %s %s, %s, %dKM\n",v->year,v->make,v->model,v->colour,v->mileage);
}
}

void print_customer(CustomerType *c) {
  //if customer provided, print customer details
  if(c != NULL){
    int currentNum = c->numVehicles;
    printf("\n%s %s, %d vehicle(s)\n",c->firstName,c->lastName,c->numVehicles);
    //Loop through customer vehicles to then print vehicle details
    for(int i=0; i<currentNum;i++){
      print_vehicle(&(c->ownedVehicles[i]));
    }
}

}

int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
  //If customer vehicles are not maxed, add 1 to number of vehicles and add the vehicle to ownedVehicles array
  int currentNum = customer->numVehicles;
  if(currentNum<MAX_VEHICLES){
    (customer->ownedVehicles[currentNum]) = *vehicle;
    (customer->numVehicles) = (customer->numVehicles)+1;
  }
  else{
    return -1;
  }
  return 0;
}

CustomerType create_customer(char* fname, char* lname) {
  //Create a new CustomerType
  CustomerType new_customer;
  //Copy in provided customer details
  strcpy(new_customer.firstName,fname);
  strcpy(new_customer.lastName,lname);
  new_customer.numVehicles = 0;
  //Return the new_customer
  return new_customer;
}


VehicleType create_vehicle(char* make, char* model, char* colour,
                            int year, int mileage) {
  //Create a new VehicleType
  VehicleType new_vehicle;
  //Copy in provided vehicle details
  strcpy(new_vehicle.make,make);
  strcpy(new_vehicle.model,model);
  strcpy(new_vehicle.colour,colour);
  new_vehicle.year = year;
  new_vehicle.mileage = mileage;
  //Return the new vehicle
  return new_vehicle;
}


int main() {
    //Create custmers using the create_customer function
    CustomerType customers[MAX_CUSTOMERS] = {create_customer("Justin","Ward"),create_customer("John","Smith"),create_customer("John","Doe"),create_customer("Adam","White"),create_customer("Joe","Shmoe"),create_customer("Amanda","Land")};

    //Create Vehicles using the create_vehicle function
    VehicleType HondaCivic = create_vehicle("Honda","Civic","Black",2006,175000);
    VehicleType ToyotaCorolla = create_vehicle("Toyota","Corolla","Grey",2004,176000);
    VehicleType AstonMartin = create_vehicle("Aston Martin", "Vanquish","Silver", 2012, 8599);
    VehicleType JeepWrangler = create_vehicle("Jeep","Wrangler","Brown",2011,65000);
    VehicleType HondaAccord = create_vehicle("Honda","Accord","Red",2014, 42000);
    VehicleType KiaForte = create_vehicle("Kia","Forte", "White",2017, 6000);
    VehicleType HyundaiElantra = create_vehicle("Hyundai","Elantra", "Blue",2018, 2000);
    VehicleType ToyotaCamry = create_vehicle("Toyota","Camry", "Gold",2009, 95000);
    VehicleType BuickEnclave = create_vehicle("Buick", "Enclave", "White",2013,75000);
    VehicleType AudiA4 = create_vehicle("Audi","A4","Black",2012,156000);
    VehicleType BMW335i = create_vehicle("BMW","335i","Red",2009,113000);
    VehicleType ToyotaPrius = create_vehicle("Toyota","Prius","Yellow",2008,201056);
    VehicleType RenaultClio = create_vehicle("Reanult","Clio","Red",2006,264321);

    //Add Vehicles to the customers using the add_vehicle function
    //Customer 0
    add_vehicle(&customers[0],&AstonMartin);
    //Customer 1
    add_vehicle(&customers[1],&HondaCivic);
    add_vehicle(&customers[1],&ToyotaCorolla);
    //Customer 2
    add_vehicle(&customers[2],&JeepWrangler);
    add_vehicle(&customers[2],&HondaAccord);
    add_vehicle(&customers[2],&KiaForte);
    //Customer 3
    add_vehicle(&customers[3],&HyundaiElantra);
    add_vehicle(&customers[3],&ToyotaCamry);
    add_vehicle(&customers[3],&BuickEnclave);
    add_vehicle(&customers[3],&AudiA4);
    add_vehicle(&customers[3],&BMW335i);
    //ADD 5th
    add_vehicle(&customers[3],&ToyotaPrius);
    //Customer 4
    add_vehicle(&customers[4],&RenaultClio);
    //Customer 5
    add_vehicle(&customers[5],&ToyotaPrius);



    //Iterate and print customer
    for(int i=0; i<MAX_CUSTOMERS; i++){
      print_customer(&customers[i]);
    }
    print_customer(NULL);
    return 0;
}
