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

#ifndef ASSIGNMENT7_TERM_H
#define ASSIGNMENT7_TERM_H


class Term {
    int coef;
    int pow;
public:
    Term(int coef, int pow);
    int getCoef() const;
    int getPow() const;
    void setCoef(int coef);
    void setPow(int pow);
};


#endif //ASSIGNMENT7_TERM_H
