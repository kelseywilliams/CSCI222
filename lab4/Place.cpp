#include "Place.h"
Place::Place(){
    this->north = nullptr;
    this->south = nullptr;
    this->east = nullptr;
    this->west = nullptr;
    this->lnk = nullptr;
    this->x = 0;
    this->open = true;
    this->vChar = " ";
    this->light = 0;
}
bool Place::freeToMove(int direction){
    switch(direction){
        case N:
            return (this->north != nullptr) && this->north->open;
        case S:
            return (this->south != nullptr) && this->south->open;
        case E:
            return (this->east != nullptr) && this->east->open;
        case W:
            return (this->west != nullptr) && this->west->open;
        default:
            return false;
    }
}
Place* Place::next(int direction){
    if (this->freeToMove(direction)) {
        switch(direction){
            case N:
                return this->north;
            case S:
                return this->south;
            case E:
                return this->east;
            case W:
                return this->west;
        }
    }
    else return nullptr;
}
bool Place::isOpen(){
    return this->open;
}
void Place::block(std::string c){
    this->setChar(c);
    this->open = false;
    if (this->lnk != nullptr) this->lnk->open = false;
}
void Place::unblock(){
    this->setChar(" ");
    this->open = true;
    if (this->lnk != nullptr) this->lnk->open = true;
}
void Place::toggleLight(){
    if (this->light >= 3) this->light = 1;
    this->light++;
}
int Place::getLight(){
    return this->light;
}
void Place::setLight(int color){
    this->light = color;
    if (this->lnk != nullptr) this->lnk->light = this->light;
}
void Place::setChar(std::string c){
    this->vChar = c;
    if (this->lnk != nullptr) this->lnk->vChar = this->vChar;
}
std::string Place::getChar(){
    return this->vChar;
}
