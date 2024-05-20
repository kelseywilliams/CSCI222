//
// Created by kelse on 3/7/2024.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#ifndef GAME_H
#define GAME_H

class Simulator {
std::vector<std::vector<int>> state;
int gens;
public:
    explicit Simulator() : gens(50) { };
    explicit Simulator(int gens);
    void populate();
    static int randgen(int start, int stop);
    static std::string outChar(int x);
    static bool checkPulse(std::vector<std::vector<int>> vs);
    int newState();
    int countNeighbor(int x, int y);
    void simulate();
    void printNeighbors();
    void printBoard(int gen);
};


#endif
