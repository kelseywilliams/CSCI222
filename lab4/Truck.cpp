
#include "Truck.h"

Truck::Truck(Road* lane, int direction): Truck::Vehicle(lane, 5, direction){
    this->lane = lane;
    this->direction = direction;
}
Truck::~Truck(){
    this->removeVehicle();
}
std::string Truck::getChar() {
    return this->vChar;
}
void Truck::toString() {
    std::cout << "Truck: { id: "<< this->getId() << ", speed: " << this->getSpeed() << ", direction: " << this->direction << ", lane: " << (void*)this->lane << ", x: " << this->getX() << ", place: " << (void*)this->lane->getAt(this->getX()) << "}" << std::endl;
}