#include "csvreader.h"


CSVReader::CSVReader(const QString& filename)
{
 fin.open(filename.toLatin1().data());
}
CSVReader::~CSVReader(){
    fin.close();
}



CSVReader& CSVReader::operator=(CSVReader&& orher){
    fin = std::move(orher.fin);
    return *this;
}

CSVReader::CSVReader(CSVReader&& orther){
    fin = std::move(orther.fin);
}

AbstractReader& CSVReader::operator>> (Car &car){

    if (fin.is_open() && !fin.eof()) {
        std::string line;
        getline(fin, line);

        if (!line.empty()){
            auto v = split(line, ';');

            car.n = std::stoi(v[0]);
            car.model = QString::fromStdString(v[1]);
            car.color = static_cast<Color>(stoi(v[2]));
            car.year = stoi(v[3]);
        }

    }
    return *this;
}
