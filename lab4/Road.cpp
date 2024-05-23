
#include "Road.h"
Road::Road(int direction){
    this->direction = direction;
    this->length = LENGTH;

    auto *head = new Place();
    this->places.push_back(head);
    for (int i = 1; i < this->length; i++){
        auto *p = new Place();
        switch(direction){
            case N:
                this->places[i - 1]->north = p;
                break;
            case S:
                this->places[i - 1]->south = p;
                break;
            case E:
                this->places[i - 1]->east = p;
                break;
            case W:
                this->places[i - 1]->west = p;
                break;
            default:
                exit(1);
                break;
        }
        p->x = i;
        this->places.push_back(p);
    }
}
Place* Road::getStart(){
    return *this->places.begin();
}
Place* Road::getAt(int x){
    if (x > LENGTH - 1 || x < 0) return nullptr;
    return this->places[x];
}
int Road::getLength(){
    return this->length;
}
int Road::getDirection(){
    return this->direction;
}