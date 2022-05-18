#include "jsonreader.h"

#include <iostream>

#include <QString>

JsonReader::JsonReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
    fin >> json;
}
JsonReader::~JsonReader(){
    fin.close();
}

AbstractReader& JsonReader::operator>>(Car &car){
    if (!(this->json[index].empty())){
            std::string tempStr;

            json[index].at("n").get_to(car.n);
            json[index].at("color").get_to(car.color);
            json[index].at("year").get_to(car.year);
            json[index].at("model").get_to(tempStr);
            car.model = QString::fromStdString(tempStr);

            index++;
        }else {
            fin.close();
        }

        return *this;
}
