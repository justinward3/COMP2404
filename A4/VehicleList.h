#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  friend ostream& operator << (ostream& ,VehicleList&);
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
    void operator += (Vehicle*);
    void operator -= (Vehicle*);

    Vehicle* operator [] (int);
    int getSize() const;
  private:
    Node* head;
};

#endif
