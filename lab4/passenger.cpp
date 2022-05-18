#include "passenger.h"

Passenger::Passenger()
{

}

QString Passenger::to_string() {
    return(" Number:  " +QString::number (n) + " Model: " + model
           + " Color: " + QString::number(color)  + " Year: " + QString::number(year)
           + " Mileage: " + QString::number(mileage));
}
