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
#ifndef LAB4_PLACE_H
#define LAB4_PLACE_H
#define N 0
#define S 1
#define E 2
#define W 3


class Place {
    Place* north;
    Place* south;
    Place* east;
    Place* west;
    Place* lnk;
    std::string vChar;
    double x;
    bool open;
    friend class Road;
    friend class TrafficSim;
    friend class TrafficLight;
    int light;
public:
    explicit Place();
    bool freeToMove(int direction);
    Place* next(int direction);
    bool isOpen();
    void block(std::string c);
    void unblock();
    void setChar(std::string c);
    int getLight();
    void setLight(int color);
    void toggleLight();
    std::string getChar();
};


#endif //LAB4_PLACE_H
