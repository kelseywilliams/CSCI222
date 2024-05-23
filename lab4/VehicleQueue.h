
#ifndef LAB4_VEHICLEQUEUE_H
#define LAB4_VEHICLEQUEUE_H
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
#include <memory>
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Road.h"

class VehicleQueue {
    std::vector<Vehicle*> vehicles;
    int random;
    int direction;
    Road* lane;
    bool debug;
public:
    VehicleQueue(int rand, Road* lane, bool debug);
    void pushNew();
    void cycle();
};


#endif //LAB4_VEHICLEQUEUE_H
