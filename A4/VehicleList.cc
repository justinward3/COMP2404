#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "VehicleList.h"

VehicleList::VehicleList() : head(0) { }


VehicleList::~VehicleList()
{
  //cout<<"VehicleList DTOR"<<endl;
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

// a <<, print operator to print out VehicleList by calling the << operator in a Vehicle object
ostream& operator << (ostream& output, VehicleList& v){
  //cout<<"IN VL"<<endl;
  int size = v.getSize();
  for (int i=0;i< size;i++) {
    output << (*(v[i])) <<endl;
  }
  return output;
}

//[] operator to find Vehicle in VehicleList at index i
Vehicle* VehicleList::operator [] (int i){
  //cout<<"[]"<<endl;
  Node *currNode = head;
  Node *foundNode = 0;
  int temp = 0;
  while (currNode != 0){
    if(i==temp){
      foundNode = currNode;
      break;
    }
    temp++;
    currNode = currNode->next;
  }

  if(foundNode != 0){

    return (foundNode->data);
  }
  else{
    return NULL;
  }
}

// a += operator to add a Vehicle to the VehicleList
void VehicleList::operator += (Vehicle* newVeh){
  Node *currNode, *prevNode;
  Node  *newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    Vehicle newVehicle = *(newNode->data);
    Vehicle currVeh = *(currNode->data);
    if (newVehicle > currVeh)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;
}

// a -= operator to remove a Vehicle from VehicleList
void VehicleList::operator -= (Vehicle* delVeh){
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == delVeh){
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }

    if (prevNode == 0) {
      head = currNode->next;
    }
    else {
      prevNode->next = currNode->next;
    }
    delete(currNode->data);
    delete(currNode);
}

int VehicleList::getSize() const {

  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    size++;
    currNode = currNode->next;
  }

  return size;
}
