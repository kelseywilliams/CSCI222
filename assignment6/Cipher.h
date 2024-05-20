#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <fstream>

#ifndef CIPHER_H
#define CIPHER_H


class Cipher {
    std::map<char, double> cipher;
    int total = 0;
public:
    Cipher();
    void readFile(std::string path);
    void print();
};


#endif
