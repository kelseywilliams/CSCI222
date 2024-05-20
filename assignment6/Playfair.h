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

#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#define BUFF_CHAR 'x'
#define END_CHAR 'z'

class Playfair {
    std::vector<std::vector<char>> key;
    std::vector<std::string> encrypted;
    std::vector<std::string> decrypted;
public:
    Playfair(std::string key);
    void inputFile(std::string path);
    std::string encrypt(std::string data);
    std::string decrypt(std::string data);
    std::tuple<int, int> getCoords(char c);
    void printEncrypted();
    void printDecrypted();
};


#endif
