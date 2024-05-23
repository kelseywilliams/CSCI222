
#ifndef LAB4_ROAD_H
#define LAB4_ROAD_H
#define GRANULARITY 2
#define LENGTH (GRANULARITY * 20)
#define SPEED_LIMIT 1
#include "Place.h"

class Road {
    int direction;
    std::vector<Place*> places;
    int length;
public:
    Road(int direction);
    Place* getStart();
    Place* getAt(int x);
    int getLength();
    int getDirection();
};


#endif //LAB4_ROAD_H
