#include <random>
#include "TrafficSim.h"
int main(){
    auto ts = new TrafficSim(100, 6);
    ts->simulate();
    return 0;
}