#include "truck.h"

Truck::Truck()
{

}

QString Truck::to_string() {
    return("Number: " +QString::number (n) + " Model: " + model
           + " Color: " + QString::number(color)  + "Year: " + QString::number(year)
           + " Max cargo " + QString::number(max_cargo_weight));
}
