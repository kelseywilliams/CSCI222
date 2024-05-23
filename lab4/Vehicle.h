

#ifndef VEHICLE_H
#define VEHICLE_H
#define BUFF 4
#include "Road.h"
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
    virtual ~Vehicle() {};
    static int randgen(int start, int stop);
    int lookAhead();
    int nextLight();
    int go();
    void stop();
    int getX();
    int getSpeed();
    void gas();
    void brake();
    int getId();
    void setLength(int length);
    int getLength();
    void setWeight(int weight);
    int getWeight();
    void crash();
    void removeVehicle();
    virtual void toString()  = 0;
    virtual std::string getChar() = 0;
};


#endif //LAB4_VEHICLE_H
