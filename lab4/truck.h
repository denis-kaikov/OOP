#ifndef TRUCK_H
#define TRUCK_H
#include "car.h"

class Truck: public Car
{
public:
    int max_cargo_weight;
    Truck();

    QString to_string();
};

#endif // TRUCK_H
