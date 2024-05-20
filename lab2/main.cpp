#include <array>
#include <random>
#include <ctime>
#include <stdlib.h>
#include "Railroad.h"

int main(){
    srand(time(0));

    // Railroad take parameters 
    // num ofrounds, num of trains, num of segments per track, and num of tracks
    Railroad rr(50, 4, 10, 2);
    rr.start();
    return(0);
}