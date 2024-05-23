//
// Created by kelse on 5/10/2024.
//

#include "Motorcycle.h"
Motorcycle::Motorcycle(Road* lane, int direction): Motorcycle::Vehicle(lane, M_L, direction){
    this->lane = lane;
    this->direction = direction;
    this->setWeight(1);
}
Motorcycle::~Motorcycle(){
    this->removeVehicle();
}
std::string Motorcycle::getChar() {
    return this->vChar;
}
void Motorcycle::toString() {
    std::cout << "Motorcycle: { id: "<< this->getId() << ", speed: " << this->getSpeed() << ", direction: " << this->direction << ", lane: " << (void*)this->lane << ", x: " << this->getX() << ", place: " << (void*)this->lane->getAt(this->getX()) << "}" << std::endl;
}