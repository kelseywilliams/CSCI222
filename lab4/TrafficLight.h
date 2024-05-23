//
// Created by kelse on 5/21/2024.
//

#ifndef LAB4_TRAFFICLIGHT_H
#define LAB4_TRAFFICLIGHT_H
#define RED 1
#define GRN 2
#define YEL 3
#include "Road.h"

class TrafficLight {
    int yellowd, greend, redd, count;
    std::map<int, Place*> intersection;
public:
    TrafficLight(std::vector<Road*> lanes);
    void tick();
    void toggleLight();
    static std::string getColorChar(int color);
};


#endif //LAB4_TRAFFICLIGHT_H
