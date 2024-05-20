//
// Created by kelse on 5/9/2024.
//

#include "TrafficSim.h"
TrafficSim::TrafficSim(){
    this->ticks = 0;
    this->rand = 2;

    this->lanes.resize(0);
    for (int i = 0; i < 4; i++) {
        auto *r = new Road(i);
        this->lanes.push_back(r);
    }
    // Link two lanes together
    int length = (this->lanes[0]->getLength() - 1) / 2;
    for (int i = 0; i < 2; i++){
        Place* up;
        Place* across;
        for (int j = 2; j < 4; j++) {
            up = this->lanes[i]->getAt(length + j - 2);
            across = this->lanes[j]->getAt(length + i);
            switch (i) {
                case N:
                    across->north = up;
                    break;
                case S:
                    across->south = up;
                    break;
            }
            switch (j) {
                case W:
                    up->west = across;
                    break;
                case E:
                    up->east = across;
            }
            up->lnk = across;
            across->lnk = up;
        }
    }
    for (int i = 0; i < 4; i++) {
        auto vq = new VehicleQueue(this->rand, this->lanes[i]);
        this->queues.push_back(vq);
    }
}
void TrafficSim::simulate(){
    for (auto q: this->queues){
        q->cycle();
    }
//    for (int i = 0; i < 4; i++){
//        std::cout << "lane" << i << ": [";
//        for (int j = 0; j < LENGTH; j++){
//
//            if (!this->lanes[i]->getAt(j)->isOpen()){
//                std::cout << j << ", ";
//            }
//
//
//        }
//        std::cout << "]" << std::endl;
//    }
}
void TrafficSim::print(){
    // Screen will be scanned left to right and top to bottom.  Therefore,
    // the north and west queues of traffic will have to be read backwards

    int top = (LENGTH - 2) / 2;

    // Print top pieces
    for (int i = 0; i < top; i++) {
        for (int j = 0; j < top ; j++) std::cout << "  ";
        std::cout << "|" << this->lanes[N]->getAt(LENGTH - i - 1)->getChar();
        std::cout << "|" << this->lanes[S]->getAt(i)->getChar();
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < LENGTH; j++) std::cout << "--"; std::cout << std::endl;
    for (int j = 0; j < LENGTH; j++) std::cout << "|" << this->lanes[W]->getAt(LENGTH - j - 1)->getChar(); std::cout << std::endl;
    for (int j = 0; j < LENGTH; j++) std::cout << "--"; std::cout << std::endl;
    for (int j = 0; j < LENGTH; j++) std::cout << "|" << this->lanes[E]->getAt(j)->getChar(); std::cout << std::endl;
    for (int j = 0; j < LENGTH; j++) std::cout << "--"; std::cout << std::endl;
}