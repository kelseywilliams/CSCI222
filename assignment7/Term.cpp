//
// Created by kelse on 5/6/2024.
//

#include "Term.h"
Term::Term(int coef, int pow){
    this->coef = coef;
    this->pow = pow;
}

int Term::getCoef() const {
    return this->coef;
}

int Term::getPow() const {
    return this->pow;
}

void Term::setCoef(int coef){
    this->coef = coef;
}
void Term::setPow(int pow){
    this->pow = pow;
}
