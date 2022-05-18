#ifndef PASSENGER_H
#define PASSENGER_H
#include "car.h"

class Passenger: public Car
{
public:
    int mileage;
    Passenger();

    QString to_string();
};

#endif // PASSENGER_H
