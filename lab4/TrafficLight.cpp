//
// Created by kelse on 5/21/2024.
//

#include "TrafficLight.h"
#include "Road.h"
TrafficLight::TrafficLight(std::vector<Road*> lanes){
    this->yellowd = 6;
    this->greend = 6;
    this->redd = this->yellowd + this->greend;
    this->count = 0;

    int top = (LENGTH - 2) / 2;
    for (int i = 0; i < 4; i++){
        Place* p;
        if (i < 2) p = lanes[i]->getAt(top);
        else p = lanes[i]->getAt(top + 1);
        this->intersection[i] = p;
        if (i < 2) p->setLight(RED);
        else p->setLight(i + 2); // either 2 or 3, GRN and YEL
    }
}
void TrafficLight::tick(){
    if (!this->count % 3) toggleLight();
    this->count < 0 ? this->count++ : this->count = 0;
}
void TrafficLight::toggleLight(){
    bool red = false;
    int light;
    int light_across;
    for (int i = 0; i < 4; i++) {
        light = this->intersection[i]->getLight();
        light_across = this->intersection[(i > 1) ? i - 2 : i + 2]->getLight();
        red = light_across > 1;
        if (red) this->intersection[i]->setLight(RED);
        else if (light >= YEL) this->intersection[i]->setLight(RED);
        else (this->intersection[i]->setLight(light + RED)); // lmao.  traffic light gets red-shifted
    }
}
std::string TrafficLight::getColorChar(int color){
    switch(color){
        case RED:
            return "R";
        case GRN:
            return "G";
        case YEL:
            return "Y";
        default:
            return "x"; // broken light;
    }
}