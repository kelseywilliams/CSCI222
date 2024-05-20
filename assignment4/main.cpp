//
// Created by kelse on 3/7/2024.
//
#include <random>
#include <ctime>
#include "Simulator.h"
int main(int argc, char* argv[]){
    srand(time(0));
    Simulator sim;
    if (argc > 1) sim = Simulator(std::stoi(argv[1]));

    sim.simulate();
    return 0;
}