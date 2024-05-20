//
// Created by kelse on 5/10/2024.
//

#include "Vehicle.h"
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
int Vehicle::lookAhead(){
    auto p = this->front;
    auto n = p->next(this->direction);
    int c;
    while (n != nullptr){
        c++;
        n = n->next(this->direction);
    }
    return c;
}
void Vehicle::go(){
    // Look ahead to find free spaces
    int space = this->lookAhead();
    // Diff between two vehicles
    int diff = space - this->speed;

    // Speed up or slow down
    // Stop if the vehicles are about to collide
    if (diff <= 0) this->stop();
    // Slow the vehicle down if we are inside the buffer
    if (diff <= BUFF && this->speed > 0) this->speed--;
    // Speed up if the space ahead is greater than the buffer
    else if (diff > BUFF && this->speed <= SPEED_LIMIT) this->speed++;

    int tail, front, i;

    for (i = 0; i < this->speed; i++){
        front = this->x + i + 1;
        tail = this->x - this->length + i + 1;

        this->front = this->lane->getAt(front);
        this->front->block();
        this->front->setChar(this->getChar());

        if (tail >= 0) {
            this->tail = this->lane->getAt(tail);
            this->tail->unblock();
            this->tail->setChar(" ");
        }
    }
    // Sub by one to maintain 0 based indexing
    this->x += i;
}
void Vehicle::stop(){
    this->speed = 0;
}
int Vehicle::getId(){
    return this->id;
}
int Vehicle::getLength(){
    return this->length;
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
    this->speed--;
}