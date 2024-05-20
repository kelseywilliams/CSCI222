
#include "ComboLock.h"
int overflow_tick(int ticks){
    while(ticks < 0) ticks += 40;
    while (ticks > 40) ticks -= 40;
    return ticks;
}
ComboLock::ComboLock(int secret1, int secret2, int secret3){
    this->secret.push_back(secret1);
    this->secret.push_back(secret2);
    this->secret.push_back(secret3);
    this->reset();
}
void ComboLock::reset(){
    this->dial = 0;
    this->state = 0;
}
void ComboLock::turn_left(int ticks){
    this->dial += overflow_tick(ticks);
    if (this->secret[this->state] == this->dial) state++;
    this->open();
}
void ComboLock::turn_right(int ticks){
    this->dial += overflow_tick(ticks);
    if (this->secret[this->state] == this->dial) state++;
    this->open();
}
bool ComboLock::open() const {
    if (this->state >= 3) return true;
    else return false;
}
void ComboLock::printDial(){
    for (int i = 0; i < 40; i++){
        if (i != this->dial) std::cout << i << "  ";
        else std::cout << "|" << i << "|  ";
    }
    std::cout << std::endl;
}