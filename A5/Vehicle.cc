#include "Vehicle.h"

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) {
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }

ostream& operator<<(ostream& output, Vehicle& v)
{
    //cout <<v.toString() <<endl;
    output << v.toString() <<endl;
    return output;
}

bool Vehicle::operator<(Vehicle& v)
{
    return year < v.year;
}

bool Vehicle::operator>(Vehicle& v)
{
    return year > v.year;
}
