//
// Created by kelse on 5/9/2024.
//

#include "TrafficSim.h"
TrafficSim::TrafficSim(int ticks, int rand){
    this->ticks = ticks;
    this->rand = rand;
    this->lanes.resize(0);
    for (int i = 0; i < 4; i++) {
        auto *r = new Road(i);
        this->lanes.push_back(r);
    }
    // Link two lanes together
    int top = (LENGTH - 2) / 2;
    for (int i = 0; i < 2; i++){
        Place* up;
        Place* across;
        for (int j = 0; j < 2; j++) {
            up = this->lanes[i]->getAt(top + j);
            across = this->lanes[(i ^ j) + 2]->getAt(top + j);
            switch (i) {
                case N:
                    across->north = up;
                    break;
                case S:
                    across->south = up;
                    break;
            }
            switch (!(i ^ j) + 2) {
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
        auto vq = new VehicleQueue(this->rand, this->lanes[i], this->debug);
        this->queues.push_back(vq);
    }
    this->light = new TrafficLight(this->lanes);
}
void TrafficSim::simulate(){
    for (int i = 0; i < this->ticks; i++) {

        this->light->tick();
        for (auto q: this->queues) {
            q->cycle();
        }
        this->print();
    }
}
void TrafficSim::print(){
    // Screen will be scanned left to right and top to bottom.  Therefore,
    // the north and west queues of traffic will have to be read backwards
    int top = (LENGTH - 2) / 2;
    int color;
    Place* p;
    Place* q;
    std::string c;
    std::string s = "  ";
    std::string l = "|";
    std::string w = "--";
    std::ostringstream stream;
    std::ostringstream lightinfo;

    // Print top pieces
    for (int i = 0; i < top; i++) {
        p = this->lanes[N]->getAt(LENGTH - i - 1);
        q = this->lanes[S]->getAt(i);

        for (int j = 0; j < top ; j++) stream << s;
        stream << l << p->getChar();
        stream << l << q->getChar();
        stream << l << std::endl;
    }
    for (int i = 0; i < LENGTH; i++) (i != top && i != top + 1) ? stream << w : stream << s;
    stream << std::endl;
    for (int i = 0; i < LENGTH; i++) {
        p = this->lanes[W]->getAt(LENGTH - i - 1);
        c = p->getChar();
        stream << l << c;
    }
    stream << std::endl;
    for (int i = 0; i < LENGTH; i++)(i != top && i != top + 1) ? stream << w : stream << s;
    stream << std::endl;
    for (int i = 0; i < LENGTH; i++) {
        p = this->lanes[E]->getAt(i);
        c = p->getChar();
        stream << l << c;
    }
    stream << std::endl;
    for (int i = 0; i < LENGTH; i++) (i != top && i != top + 1) ? stream << w : stream << s;
    stream << std::endl;
    for (int i = top + 2; i < LENGTH; i++) {
        p = this->lanes[N]->getAt(LENGTH - i - 1);
        q = this->lanes[S]->getAt(i);

        for (int j = 0; j < top ; j++) stream << s;
        stream << l << p->getChar();
        stream << l << q->getChar();
        stream << l << std::endl;
    }
    for (int i = 0; i < 4; i++){
        std::string c;
        switch(i){
            case 0:
                c = "N";
                break;
            case 1:
                c = "S";
                break;
            case 2:
                c = "E";
                break;
            case 3:
                c = "W";
                break;
        }
        lightinfo << c << ":" << TrafficLight::getColorChar(this->lanes[i]->getAt((i < 2) ? top : top + 1)->getLight()) << std::endl;
    }
    stream << std::endl;
    std::cout << stream.str() << lightinfo.str();
}