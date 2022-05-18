#include "bus.h"

Bus::Bus()
{

}

QString Bus::to_string() {
    return("Number: " +QString::number (n) + " Model: " + model + " Color: " + QString::number(color)  + " Year:  " + QString::number(year) + " Max sits: " + QString::number(max_sits));
}
