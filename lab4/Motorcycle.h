
#include "Vehicle.h"

#ifndef LAB4_MOTORCYCLE_H
#define LAB4_MOTORCYCLE_H


class Motorcycle: public Vehicle{
    int length, direction;
    std::string vChar = "M";
    Road* lane;
public:
    Motorcycle(Road* lane, int direction);
    std::string getChar() override;
    void toString() override;
};


#endif //LAB4_MOTORCYCLE_H
