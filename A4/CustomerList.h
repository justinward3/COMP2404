#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"

class CustomerList
{
  friend ostream& operator << (ostream& ,CustomerList&);
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
    void operator +=(Customer*);
    void operator -=(Customer*);
    Customer* operator [] (int);
    void toString(string&);
    int getSize() const;
    Customer* get(int);
  private:
    Node* head;
};

#endif
