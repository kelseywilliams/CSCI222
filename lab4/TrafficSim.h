
#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H

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
#include "TrafficLight.h"

class TrafficSim {
    int ticks;
    double rand;
    std::vector<Road*> lanes;
    std::vector<VehicleQueue*> queues;
    bool debug = true;
    TrafficLight* light;
public:
    TrafficSim(int ticks, int rand);
    void simulate();
    void print();
};


#endif
