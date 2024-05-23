
#include "VehicleQueue.h"

VehicleQueue::VehicleQueue(int random, Road* lane, bool debug){
    srand(time(0));
    this->random = random;
    this->direction = lane->getDirection();
    this->lane = lane;
    this->debug = debug;
}
void VehicleQueue::pushNew(){
    // Attempt to push a new vehicle into the queue but return if not possible
    Place* p;
    // Get first place object in lane and return if it is not free
    // Check if first spaces are clear so as not to clutter the lane;
    for (int i = 0; i < BUFF; i++) {
        p = this->lane->getAt(i);
        if (!p->isOpen()) return;
    }
    p = this->lane->getStart();

    // Randomly decide to push a new vehicle
    bool go = !Vehicle::randgen(0, this->random);
    if (go){
        // Decide vehicle at random
        int vehicle = Vehicle::randgen(1,2);
        switch(vehicle){
            case 1:{
                //Motorcycle m(this->lane, this->direction);
                auto m = new Motorcycle(this->lane, this->direction);
                this->vehicles.push_back(m);
                p->block(m->getChar());
                break;
            }
            case 2:
                auto t = new Truck(this->lane, this->direction);
                this->vehicles.push_back(t);
                p->block(t->getChar());
                break;

        }
    }
}

void VehicleQueue::cycle() {
    this->pushNew();
    for (auto v: this->vehicles) {
        int e = v->go();
        if(e < 0) {
            delete v;
            // Purge the vehicle from the Vehicle Queue
            auto it = std::find_if(this->vehicles.begin(), this->vehicles.end(), [v](auto w){return v == w;;});
            this->vehicles.erase(it);
            continue;
        }

        if(this->debug) v->toString();
    }
}