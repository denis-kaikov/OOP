#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include <fstream>

class JsonReader : public AbstractReader
{
    std::ifstream fin;

public:
    JsonReader(const QString& filename);

    virtual std::vector<Car> readAll();
    virtual bool is_open() const {return fin.is_open(); };
};

#endif // JSONREADER_H
