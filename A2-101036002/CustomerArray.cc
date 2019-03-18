#include "CustomerArray.h"
#include "Customer.h"
#include "defs.h"

//Construcor
CustomerArray::CustomerArray(){
  size = 0;
}

//returns size
int CustomerArray::getSize(){ return size;}

//Loop through elements and return element at index j
Customer* CustomerArray::get(int j){
  if(0<=j<=MAX_CUSTOMERS){
    return elements[j];
  }
  return 0;
}

//if less than MAX_CUSTOMERS, add to array, increment the size and return
int CustomerArray::add(Customer* c){
  if(size<MAX_CUSTOMERS){
    elements[size] = c;
    size++;
    return C_OK;
  }
  else{
    //return NOK
    return C_NOK;
  }
}

//Deconstructor
CustomerArray::~CustomerArray(){
  for(int i=0; i<size;i++){
    delete elements[i];
  }
}
