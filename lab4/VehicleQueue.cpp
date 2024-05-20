//
// Created by kelse on 5/10/2024.
//

#include "VehicleQueue.h"
VehicleQueue::VehicleQueue(int rand, Road* lane){
    srand(time(0));
    this->random = rand;
    this->direction = lane->getDirection();
    this->lane = lane;
}
void VehicleQueue::pushNew(){
    // Attempt to push a new vehicle into the queue but return if not possible

    // Get first place object in lane and return if it is not free
    Place* p = this->lane->getStart();
    if (!p->freeToMove(this->direction)) return;

    // Randomly decide to push a new vehicle
    bool go = !(Vehicle::randgen(1, this->random) % this->random);
    if (go){
        // Decide vehicle at random
        int vehicle = Vehicle::randgen(1,1);
        switch(vehicle){
            case 1:
                //Motorcycle m(this->lane, this->direction);
                auto m = new Motorcycle(this->lane, this->direction);
                this->vehicles.push_back(m);
                p->block();
                //this->vehicles.push_back(new Motorcycle(this->lane, this->direction));
        }
    }
}
void VehicleQueue::cycle() {
    this->pushNew();
    for (auto v: this->vehicles) {
        v->go();
        v->toString();
    }
}
std::vector<Vehicle*> VehicleQueue::getVehicles(){
    return this->vehicles;
}