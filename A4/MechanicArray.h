#ifndef MECHANICARRAY_H
#define MECHANICARRAY_H

#include "Mechanic.h"
#include "defs.h"

class MechanicArray
{
    friend ostream& operator << (ostream& ,MechanicArray&);

    public:
        MechanicArray();
        ~MechanicArray();
        void add(Mechanic*);
        Mechanic* get(int);
        int getSize();
    private:
        Mechanic* elements[MAX_MECHANICS];
        int size;
};

#endif
