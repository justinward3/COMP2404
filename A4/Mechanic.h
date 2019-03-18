#ifndef Mechanic_H
#define Mechanic_H

#include <string>
#include "Person.h"

class Mechanic: public Person {
    friend ostream& operator<<(ostream&, Mechanic&);

    public:

        Mechanic(string="", string="", string="", string="", int=0);

        int getId() const;
        int getSalary() const;

    private:

        static int nextId;

        const int id;
        int salary;
};

#endif
