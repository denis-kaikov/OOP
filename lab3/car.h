#ifndef CAR_H
#define CAR_H
#include <string>
#include <QString>
using namespace std;
enum Color {RED, GREEN,BLUE,BLACK};
class Car
{
public:
    int n;
    QString model;
    Color color;
    int year;

};

#endif // CAR_H
