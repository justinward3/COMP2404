#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "VehicleList.h"

//VehicleList Constructor
VehicleList::VehicleList() : head(0) { }

//VehicleList Deconstructr
VehicleList::~VehicleList()
{
  Node *currNode, *nextNode;

  currNode = head;
    //Iterate nodes, free the data, then the node
  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}


//add Vehicle to List
void VehicleList::add(Vehicle* v)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = v;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;
  //iterate nodes, compare by year for proper order
  while (currNode != 0) {
    if (newNode->data->getYear() > currNode->data->getYear())
      break;
    //set nodes
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

Vehicle* VehicleList::get(int i)
{
  Node *currNode;
  Node *foundNode;
  currNode = head;
  int index = 0;
  //iterate node, check index
  while (currNode != 0) {
    if (index==i){
      foundNode = currNode;
      return foundNode->data;
    }
    currNode = currNode->next;
    index++;
  }
return NULL;
}

//getsize of list
int VehicleList::getSize()
{
  Node *currNode;
  currNode = head;
  int size = 0;
  //iterate and increment counter and node
  while (currNode != 0) {
    size++;
    currNode = currNode->next;
  }
//return counter
return size;
}

//to String method to print
void VehicleList::toString(string& outStr)
{
  Node* currNode;
  //Counter for number of cars
  int j=0;
  for (Node* currNode=head;currNode != 0;currNode = currNode->next){
      //Convert Int to String, using stringstream
      string stringYear;
      stringstream convert;
      convert << currNode->data->getYear();
      stringYear = convert.str();
      convert.str("");
      string stringKM;
      convert << currNode->data->getMilage();
      stringKM = convert.str();
      //INcrement counter for Number of Cars, then convert to String
      j++;
      convert.str("");
      convert << j;
      string stringj = convert.str();
      //Append to outStr
      outStr += "\t" + stringj + ") " + currNode->data->getColour() + " "
           + stringYear + " " + currNode->data->getMake() + " " + currNode->data->getModel()+ " ("
           + stringKM + "km)" + "\n";
    }

}
