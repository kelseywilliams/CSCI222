//
// Created by kelse on 3/2/2024.
//
#include <time.h>
#include <random>
#include "Nim.h"
int main(){
    srand(time(0));

    Nim nim;
    nim.play(1);
    return 0;
}