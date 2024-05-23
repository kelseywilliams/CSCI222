
#include "Vehicle.h"

#ifndef TRUCK_H
#define TRUCK_H


class Truck: public Vehicle{
    int direction;
    std::string vChar = "T";
    Road* lane;
public:
    Truck(Road* lane, int direction);
    ~Truck() override;
    std::string getChar() override;
    void toString() override;
};


#endif
