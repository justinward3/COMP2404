#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

//CustomerList Constructor
CustomerList::CustomerList() : head(0) { }

//CustomerList Deconstructor
CustomerList::~CustomerList()
{
  //cout<<"CustomerList DTOR"<<endl;
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;

    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}


//+= operator to add a Customer to the CustomerList
void CustomerList::operator +=(Customer* newCust){
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data))
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

//-= operator to remove a Customer from the CustomerList
void CustomerList::operator -= (Customer* delCust){
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == delCust){
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

//an [] operator to get a Customer from CustomerList at index i
Customer* CustomerList::operator [] (int i){
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


//<< print operator, to print Customers in CustomerList by calling Customer << operator
ostream& operator << (ostream& output, CustomerList& c){
  for (int i=0;i<c.getSize();i++) {
    output << (*(c[i])) <<endl;
  }
  return output;
}


Customer* CustomerList::get(int id)
{
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }

  return size;
}
