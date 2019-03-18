#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class LinkedList{
  template <class V>
  friend ostream& operator<<(ostream&, LinkedList<V>&);
  class Node
  {
    friend class LinkedList;
    private:
      T* data;
      Node*    next;
  };
public:
  LinkedList();
  ~LinkedList();
  int getSize() const;
  //T* get(int);
  LinkedList<T>& operator+=(T*);
  LinkedList<T>& operator-=(T*);
  T* operator[](int);

private:
  Node* head;
};

//Constructor
template <class T>
LinkedList<T>::LinkedList(): head(0) {};

//Deconstructor
template <class T>
LinkedList<T>::~LinkedList(){
    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != 0) {
      nextNode = currNode->next;
      delete currNode->data;
      delete currNode;
      currNode = nextNode;
    }
}

//Get Size
template <class T>
int LinkedList<T>::getSize() const{
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }

  return size;
}

//Overloaded += to add Obj
template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newObj)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newObj;
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

  return *this;
}

//Overloaded -= to remove Obj
template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T* Obj)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == Obj)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0)
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;

  return *this;
}

//Subscript operator
template <class T>
T* LinkedList<T>::operator[](int i) {
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node *currNode = head;

        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        return currNode->data;
    }
}

//Overloaded << to print
template <class T>
ostream& operator<<(ostream& output, LinkedList<T>& ll)
{

  for (int i = 0; i < ll.getSize(); i++)  {
    output << (*(ll[i]));
  }

  return output;

}

#endif
