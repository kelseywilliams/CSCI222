//
// Created by kelse on 3/2/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>

#ifndef NIM_H
#define NIM_H


class Nim {
    int pile_size;
public:
    Nim();
    Nim(int pile_size);
    static int randgen(int start, int end);
    static double log2(int x);
    void player_move(std::string player_name);
    void smart_move(std::string player_name);
    void stupid_move(std::string player_name);
    void play(int mode);
    void print_remaining();
};


#endif
