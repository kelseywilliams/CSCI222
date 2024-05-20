#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>

#ifndef UNIQUEWORDS_H
#define UNIQUEWORDS_H


class UniqueWords {
    std::vector<char*> words;
public:
    UniqueWords() : words(0) {};
    void readFile(std::string path);
    void printWords();
    void printAddrs();
};


#endif
