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
void Place::block(){
    this->open = false;
    if (this->lnk != nullptr) this->lnk->open = false;
}
void Place::unblock(){
    this->open = true;
    if (this->lnk != nullptr) this->lnk->open = true;
}
void Place::setChar(std::string c){
    if (this->lnk != nullptr) this->lnk->vChar = c;
    this->vChar = c;
}
std::string Place::getChar(){
    return this->vChar;
}
