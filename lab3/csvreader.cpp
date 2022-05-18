#include "csvreader.h"

CSVReader::CSVReader(const string& filename)
{
 fin.open(filename);
}
CSVReader::~CSVReader(){
    fin.close();
}
vector<string> CSVReader::split(const string& str, char delim)
{
    vector<string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));

            start = end + 1;
        } while (end != string::npos);
    }

    return tokens;
}

vector<Car> CSVReader::readAll(){
    vector<Car> result;

            if(fin.is_open())
            {
                string line;


                while (getline(fin,line))
                   {
                    auto v = split(line, ';');

                    Car car;
                    car.n=stoi(v[0]);
                    car.model=QString::fromStdString(v[1]);

                    car.color=static_cast<Color>(stoi(v[2]));

                    car.year=stoi(v[3]);

                    result.push_back(car);
                   }
            }
            sort(result.begin(),result.end(),[](const Car &c1, const Car &c2){
                return c1.n<c2.n;});
            return result;
}
