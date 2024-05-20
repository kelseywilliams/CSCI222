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
#include "Term.h"

#ifndef ASSIGNMENT7_POLYNOMIAL_H
#define ASSIGNMENT7_POLYNOMIAL_H


class Polynomial {
    std::vector<Term> terms;
public:
    explicit Polynomial(std::vector<Term> terms);
    void addTerm(Term t);
    void add(Polynomial p);
    void multiply(Polynomial p);
    std::vector<Term> getPolynomial();
    void setPolynomial(std::vector<Term> terms);
    void printRPN();
    void print();
};


#endif //ASSIGNMENT7_POLYNOMIAL_H
