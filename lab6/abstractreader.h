#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>
#include <fstream>

#include <car.h>


#include <car.h>

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<Car> readAll() {std::vector<Car> car; return car;};
    virtual bool is_open() const = 0;
    virtual operator bool () = 0;
    virtual AbstractReader& operator>> (Car &c) = 0;
};

#endif // ABSTRACTREADER_H
