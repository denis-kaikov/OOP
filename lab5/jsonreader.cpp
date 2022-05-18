#include "jsonreader.h"

#include <json.hpp>

#include <QString>

JsonReader::JsonReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

std::vector<Car> JsonReader::readAll(){

    std::vector<Car> result;
    nlohmann::json json;

    fin >> json;

    for (auto& e: json){
        Car c;
        e.at("n").get_to(c.n);
        e.at("color").get_to(c.color);
        e.at("year").get_to(c.year);
        std::string str;
        e.at("model").get_to(str);
        c.model = QString::fromStdString(str);
        result.push_back(c);
    }

    return result;
}
