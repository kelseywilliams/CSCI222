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
#include "Road.h"
#ifndef LAB4_VEHICLEQUEUE_H
#define LAB4_VEHICLEQUEUE_H


class VehicleQueue {
    std::vector<Vehicle*> vehicles;
    int random;
    int direction;
    Road* lane;
public:
    VehicleQueue(int rand, Road* lane);
    void pushNew();
    void cycle();
    std::vector<Vehicle*> getVehicles();

};


#endif //LAB4_VEHICLEQUEUE_H
