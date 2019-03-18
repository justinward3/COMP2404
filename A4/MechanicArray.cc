#include "MechanicArray.h"
#include "Mechanic.h"
#include "defs.h"
#include <iostream>


//Sourced from Assignment 2, to create MechanicArray

//Construcor
MechanicArray::MechanicArray(){
  size = 0;
}

//returns size
int MechanicArray::getSize(){ return size;}

//Loop through elements and return element at index j
Mechanic* MechanicArray::get(int j){
  if(0<=j<=MAX_MECHANICS){
    return elements[j];
  }
  return 0;
}

//operator for printing
ostream& operator << (ostream& output , MechanicArray& m){
  for (int i=0;i<m.getSize();i++) {
    output << (*(m.get(i))) <<endl;
  }
  return output;
}

//if less than MAX_CUSTOMERS, add to array, increment the size and return
void MechanicArray::add(Mechanic* m){
  if(size<MAX_MECHANICS){
    elements[size] = m;
    size++;
  }
}

//Deconstructor
MechanicArray::~MechanicArray(){
  for(int i=0; i<size;i++){
    delete elements[i];
  }
}
