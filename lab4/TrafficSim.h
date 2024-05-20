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
#include "Road.h"
#include "VehicleQueue.h"
#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H

class TrafficSim {
    int ticks;
    double rand;
    std::vector<Road*> lanes;
    std::vector<VehicleQueue*> queues;
public:
    TrafficSim();
    void simulate();
    void print();
};


#endif //LAB4_TRAFFICSIM_H
