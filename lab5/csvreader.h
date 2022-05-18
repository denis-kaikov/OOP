#ifndef CSVREADER_H
#define CSVREADER_H
#include<algorithm>
#include <string>
#include <fstream>
#include <vector>
#include "car.h"
#include "function.h"
#include "abstractreader.h"

#include <QString>

using namespace std;

class CSVReader : public AbstractReader
{
    ifstream fin;

public:
    CSVReader(const QString& filename);
    ~CSVReader();
    CSVReader& operator= (CSVReader&& orther);
    CSVReader(CSVReader&& orther);

    bool is_open() const {return fin.is_open();};
    vector<Car> readAll();


};

#endif // CSVREADER_H
