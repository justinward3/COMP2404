#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };

  public:
    VehicleList();
    ~VehicleList();
    void add(Vehicle*);
    int getSize();
    Vehicle* get(int);
    void toString(string&);
  private:
    Node* head;
};

#endif
