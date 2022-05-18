#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>


#include <car.h>

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<Car> readAll() {std::vector<Car> em; return em;};
    virtual bool is_open() const {return 1;};
};

#endif // ABSTRACTREADER_H
