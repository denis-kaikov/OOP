#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;

enum Color {RED, GREEN,BLUE,BLACK};

 struct Car{
     int n;
     string model;
     Color color;
     int year;
 };

vector<string> split(const string& str, char delim)
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

int main()
{

    vector<Car> cars;
    ifstream file("C:\\Users\\kaiko\\Desktop\\prog\\lab1\\cars.csv");

    if(file.is_open())
    {
        string line;


        while (getline(file,line))
           {
            auto v = split(line, ';');

            Car car;
            car.n=stoi(v[0]);
            car.model=v[1];

            car.color=static_cast<Color>(stoi(v[2]));

            car.year=stoi(v[3]);

            cars.push_back(car);
           }
    }
    file.close();

    for (const auto &c: cars)
    {
        if ((c.color == GREEN)&&(2022-c.year>4))
            cout<<c.n <<"," << c.model<< "," <<c.color << "," << c.year<<endl;
    }
    sort(cars.begin(),cars.end(),[](const Car &c1, const Car &c2){
        return c1.year>c2.year;
    });

    ofstream file2("C:\\Users\\kaiko\\Desktop\\prog\\lab1\\new_cars.csv");
    for (const auto &c: cars)
    {
    file2<<c.n <<"; " << c.model<< "; " <<c.color << "; " << c.year<<endl;
    }
    file2.close();
    return 0;
}
