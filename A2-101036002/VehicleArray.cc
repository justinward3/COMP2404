#include "VehicleArray.h"
#include "Vehicle.h"
#include "defs.h"

//Construcor
VehicleArray::VehicleArray(){
  size = 0;
}

//returns size
int VehicleArray::getSize(){ return size;}

//Loop through elements and return element at index j
Vehicle* VehicleArray::get(int j){
  if(0<=j<=MAX_VEHICLES){
    return elements[j];
  }
  return 0;
}

//if less than MAX_VEHICLES, add to array, increment the size and return
int VehicleArray::add(Vehicle* v){
  if(size<MAX_VEHICLES){
    elements[size] = v;
    size++;
    return C_OK;
  }
  //return NOK
  else{
    return C_NOK;
  }
}

//Deconstructor
VehicleArray::~VehicleArray(){
  for(int i=0; i<size;i++){
    delete elements[i];
  }
}
