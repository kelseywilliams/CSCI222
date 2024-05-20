//
// Created by Kelsey Williams on 2/27/2024.
//
#ifndef RAILROAD_H
#define RAILROAD_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Segment.h"
class Railroad{
    std::vector<std::vector<Segment*>> rail;
    std::map<int, bool> trains;
    int rounds, TRAIN_NUM, TRACK_LEN, TRACKS;

public:
    Railroad(int rounds, int TAIN_NUM, int TRACK_LEN, int TRACKS);
    int randgen(int start, int end);
    static void crash();
    void assembleRail();
    void populateTrains();
    void swtch(Segment* seg);
    void move(Segment* seg);
    void crawlRail();
    void start();
    static std::string trainChar(Segment* seg);
    void toString(int round);
};
#endif
