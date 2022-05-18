#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;
enum Color {RED, GREEN,BLUE,BLACK};
class Car
{
public:
    int n;
    string model;
    Color color;
    int year;

};

#endif // CAR_H
