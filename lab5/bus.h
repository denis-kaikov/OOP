#ifndef BUS_H
#define BUS_H
#include "car.h"


class Bus: public Car
{
public:
    int max_sits;
    Bus();

    QString to_string();
};

#endif // BUS_H
