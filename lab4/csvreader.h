#ifndef CSVREADER_H
#define CSVREADER_H
#include<algorithm>
#include <string>
#include <fstream>
#include <vector>
#include "car.h"
#include "function.h"

using namespace std;

class CSVReader
{
    ifstream fin;
public:
    CSVReader(const string& filename);
    ~CSVReader();
    CSVReader& operator= (CSVReader&& orther);
    CSVReader(CSVReader&& orther);

    bool is_open() const {return fin.is_open();};
    vector<Car> readAll();


};

#endif // CSVREADER_H
