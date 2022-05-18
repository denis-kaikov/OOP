#include "csvuploader.h"

CSVUploader::CSVUploader(const string& filename)
{
    fout.open(filename);
}

CSVUploader::~CSVUploader(){
    fout.close();
}

void CSVUploader::addAll(vector <Car> newcars){
    for (const auto &c: newcars)
    {
    fout<<c.n <<";" << c.model.toStdString()<< ";" <<c.color << ";" << c.year<<endl;
    }

}
