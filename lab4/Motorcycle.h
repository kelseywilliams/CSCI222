
#include "Vehicle.h"


#ifndef LAB4_MOTORCYCLE_H
#define LAB4_MOTORCYCLE_H
#define M_L 1

class Motorcycle: public Vehicle{
    int direction;
    std::string vChar = "M";
    Road* lane;
public:
    Motorcycle(Road* lane, int direction);
    ~Motorcycle() override;
    std::string getChar() override;
    void toString() override;
};


#endif //LAB4_MOTORCYCLE_H
