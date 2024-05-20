#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <array>
#include <tuple>
#include <list>
#include <ctime>

#ifndef VEHICLE_H
#define VEHICLE_H
#define BUFF 2
#include "Road.h"

class Vehicle {
    std::tuple<int, int> location;
    int length, speed, weight, direction, total_time, waiting_time, moving_time, distance;
    Road* lane;
    Place* front;
    Place* tail;
    int x;
    int id;
public:
    Vehicle(Road* lane, int length, int direction);
    static int randgen(int start, int stop);
    int lookAhead();
    void go();
    void stop();
    int getX();
    int getSpeed();
    void gas();
    void brake();
    int getId();
    int getLength();
    virtual void toString()  = 0;
    virtual std::string getChar() = 0;
};


#endif //LAB4_VEHICLE_H
