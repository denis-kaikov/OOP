#ifndef CAR_H
#define CAR_H
#include <string>
#include <QString>
#include <iostream>
using namespace std;
enum Color {RED, GREEN,BLUE,BLACK};
class Car
{
public:
    int n;
    QString model;
    Color color;
    int year;

    QString to_string();
    // Создана для того, чтобы при сортировке не использывать лямба функции
    friend bool operator< (const Car& d1, const Car& d2){
        return d1.n < d2.n;
    }

    //Предназначен для вывода в поток упрощенным синтаксисом
    friend std::ostream& operator<< (std::ostream& out,  Car& car){
        out <<"Number: " << car.n << " Model: " << car.model.toStdString()<< " Color: " << car.color  << " Year: " << car.year ;
        return out;
    }
};

#endif // CAR_H
