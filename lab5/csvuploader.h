#ifndef CSVUPLOADER_H
#define CSVUPLOADER_H
#include "csvreader.h"
#include <iostream>

class CSVUploader
{
    ofstream fout;
public:

    ~CSVUploader();

    void addAll(vector <Car> newcars);
    bool is_open() const {return fout.is_open();};
    CSVUploader(const QString& filename);
    CSVUploader& operator= (CSVUploader&& orther);
    CSVUploader(CSVUploader&& orther);

};

#endif // CSVUPLOADER_H
