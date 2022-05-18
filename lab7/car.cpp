#include "car.h"


QString Car::to_string() {
    return("Number: " +QString::number (n) + " Model: " + model
           + " Color: " + QString::number(color)  + " Year: " + QString::number(year) );
}
