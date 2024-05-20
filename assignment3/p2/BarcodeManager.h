//
// Created by kelse on 3/3/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#ifndef BARCODEMANAGER_H
#define BARCODEMANAGER_H


class BarcodeManager {
    std::vector<std::vector<int>> barcode;
    const std::vector<std::vector<int>> code {
        {1, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 1}, 
        {0, 0, 1, 0, 1}, 
        {0, 0, 1, 1, 0}, 
        {0, 1, 0, 0, 1}, 
        {0, 1, 0, 1, 0}, 
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 0, 1}, 
        {1, 0, 0, 1, 0}, 
        {1, 0, 1, 0, 0}
    };
public:
    void newBarcode();
    int createBarcode(std::string input);
    void print();
};
#endif
