//
// Created by kelse on 5/10/2024.
//

#include "Vehicle.h"
#include "TrafficLight.h"

int Vehicle::randgen(int start, int stop){
    return rand() % (stop - start + 1) + start;
}
Vehicle::Vehicle(Road* lane, int length, int direction){
    this->x = 0;
    this->speed = 1;
    this->id = Vehicle::randgen(10, 99);
    this->length = length;
    this->weight = weight;
    this->direction = direction;

    this->lane = lane;
    this->front = lane->getStart();

    // If the tail is at a place greater than 0, set it.  Otherwise set it to null
    int tail = this->x - this->length - 1;
    this->tail = tail >= 0 ? lane->getAt(tail) : nullptr;
}
void Vehicle::removeVehicle(){
    for (int i = 0; i < this->length; i++){
        this->lane->getAt(this->x - i)->unblock();
    }
}
int Vehicle::lookAhead(){
    int i = 0;
    Place* p = this->front;
    while(p != nullptr) p = this->lane->getAt(this->x + ++i);
    return i;
}
int Vehicle::nextLight(){
    return ((LENGTH -2) / 2) - this->x;
//    int light_x = (LENGTH - 2) / 2;
//    if (this->x > light_x) return -1;
//    auto p = this->front;
//    auto n = p->next(this->direction);
//    int c = 0;
//    while (n != nullptr){
//        if (p->getLight() > 0) break;
//        c++;
//        n = n->next(this->direction);
//    }
//    return c;
}
int Vehicle::go(){
    int top = (LENGTH - 2) / 2;
    int color;
    int s = this->speed;
    // Calculate light.  Color and distance two
    int dist = this->nextLight();
    if (dist < BUFF && dist > 0){
        color = this->lane->getAt(this->x + dist)->getLight();
        switch(color){
            case RED:
                this->stop();
                break;
            case YEL:
                this->brake();
                break;
        }
    }
    // Look ahead to find free spaces
    int space = this->lookAhead();
    if (space - this->speed < BUFF - BUFF / 2) {
        this->stop();
        return 1;
    }
    else if (space - this->speed < BUFF || this->speed + space >= SPEED_LIMIT) this->brake();
    else { if (color == GRN && this->speed + 1 <= SPEED_LIMIT) this->gas();}
    int tail, front, i;

    for (i = 0; i < this->speed; i++){
        front = this->x + i + 1;
        tail = this->x - this->length + i + 1;

        // Vehicle has reached the end of the track. Schdule for deletion by the Vehicle Queue
        if (front >= LENGTH - 1) {
            this->x += i;
            return -1;
        }
        this->front = this->lane->getAt(front);
        if (!this->front->isOpen()) {
            this->crash();
        }
        else this->front->block(this->getChar());

        if (tail >= 0) {
            this->tail = this->lane->getAt(tail);
            this->tail->unblock();
        }
    }
    // Sub by one to maintain 0 based indexing
    this->x += i;
    return 0;
}
void Vehicle::crash(){
    std::cout << this->id << " has crashed on lane " << this->direction << ". He was going " << this->speed << " and was it happened right around " << this->x << " officer! I swear!";
    exit(1);
}
void Vehicle::stop(){
    this->speed = 0;
}
int Vehicle::getId(){
    return this->id;
}
void Vehicle::setLength(int length){
    this->length = length;
}
int Vehicle::getLength(){
    return this->length;
}
void Vehicle::setWeight(int weight){
    this->weight = weight;
}
int Vehicle::getWeight(){
    return this->weight;
}
int Vehicle::getX(){
    return this->x;
}
int Vehicle::getSpeed(){
    return this->speed;
}
void Vehicle::gas(){
    this->speed++;
}
void Vehicle::brake(){
    if (this->speed >= 0) this->speed--;
}