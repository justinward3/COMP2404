#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "CustomerList.h"

//CustomerList Constructor
CustomerList::CustomerList() : head(0) { }

//CustomerList Deconstructr
CustomerList::~CustomerList()
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


//add Customer to List
void CustomerList::add(Customer* c)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = c;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;
  //iterate nodes, compare by lastName for proper order
  while (currNode != 0) {
    if (newNode->data->getLname() < currNode->data->getLname())
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

Customer* CustomerList::get(int id)
{
  Node *currNode;
  Node *foundNode;
  currNode = head;
  //iterate nodes, check if customer ids match
  while (currNode != 0) {
    if (currNode->data->getId() == id){
      //save matched node and return the customer
      foundNode = currNode;
      return foundNode->data;
    }
    currNode = currNode->next;
  }

return NULL;
}

int CustomerList::getSize()
{
  Node *currNode;
  currNode = head;
  int size = 0;
  //iterate nodes and add to size counter
  while (currNode != 0) {
    size++;
    currNode = currNode->next;
  }
//return size counter
return size;
}


//to string method for printing
void CustomerList::toString(string& outStr)
{
  Node* currNode;
  outStr += "CUSTOMERS: \n \n";
  for (Node* currNode=head;currNode != 0;currNode = currNode->next){
      //Converting Int to Strings
      string stringID;
      stringstream convert;
      convert << currNode->data->getId();
      stringID = convert.str();
      convert.str("");
      string numVehicles;
      convert << currNode->data->getNumVehicles();
      numVehicles = convert.str();

      //Append Customer Information to the String
      outStr += "Customer ID " + stringID + "\n" + "\n"
             + "    Name: " + currNode->data->getFname() + " " + currNode->data->getLname() + "\n"
             + "    Address: " +  currNode->data->getAddress() + "\n"
             + "    Phone Number: " + currNode->data->getPhoneNumber() + "\n";
      //Check if Customer has Vehicles
      if (currNode->data->getNumVehicles() > 0) {
        outStr = outStr + "\n"+ "    " + numVehicles
                       + " vehicle(s): " + "\n" + "\n";
             }
      //Call the toString function in the VehicleList for each customer
      currNode->data->getVehicles().toString(outStr);
    }
}
