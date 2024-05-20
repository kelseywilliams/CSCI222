#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <array>
#include <tuple>

#ifndef COMBOLOCK_H
#define COMBOLOCK_H


class ComboLock {
    std::vector<int> secret;
    int dial;
    int state;
public:
    ComboLock(int secret1, int secret2, int secret3);
    void reset();
    void turn_left(int ticks);
    void turn_right(int ticks);
    bool open() const;
    void printDial();
};


#endif //ASSIGNMENT8_COMBOLOCK_H
