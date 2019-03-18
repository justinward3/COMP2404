#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
  class Node
  {
    friend class CustomerList;
    private:
      Customer* data;
      Node*    next;
  };

  public:
    CustomerList();
    ~CustomerList();
    void add(Customer*);
    int getSize();
    Customer* get(int);
    void toString(string&);
  private:
    Node* head;
};

#endif
