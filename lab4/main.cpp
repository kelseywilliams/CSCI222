#include <random>
#include "TrafficSim.h"
int main(){
    auto ts = new TrafficSim();
    for (int i = 0; i < 10; i++){
        ts->simulate();
        ts->print();
        std::cout << std::endl;
    }
    return 0;
}