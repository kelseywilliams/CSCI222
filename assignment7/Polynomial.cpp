//
// Created by kelse on 5/6/2024.
//

#include "Polynomial.h"
Polynomial::Polynomial(std::vector<Term> terms){
    this->setPolynomial(terms);
}
void Polynomial::addTerm(Term t){
    this->terms.push_back(t);
}
void Polynomial::add(Polynomial p){
    std::vector<Term> newp = p.getPolynomial();
    std::vector<Term> curp = this->getPolynomial();
    for (int i = 0; i < curp.size(); i++){
        int coef = curp[i].getCoef();
        int pow = curp[i].getPow();

        auto it = std::find_if(newp.begin(), newp.end(), [pow](Term t){
            if (pow == t.getPow()) return true;
            else return false;
        });
        if (it != newp.end()){
            int sum = coef + it->getCoef();
            curp[i].setCoef(sum);
            newp.erase(it);
        }
    }
    for (Term t: newp) curp.push_back(t);
    this->setPolynomial(curp);
}
void Polynomial::multiply(Polynomial p){
    std::vector<Term> newp = p.getPolynomial();
    std::vector<Term> curp = this->getPolynomial();
    std::vector<Term> buff;
    for (Term t: curp){
        for (Term u: newp){
            int coef = t.getCoef() * u.getCoef();
            int pow = t.getPow() + u.getPow();
            buff.push_back(Term(coef, pow));
        }
    }
    this->setPolynomial(buff);
}
std::vector<Term> Polynomial::getPolynomial(){
    return this->terms;
}
void Polynomial::setPolynomial(std::vector<Term> terms){
    this->terms = terms;
}
void Polynomial::printRPN(){
    std::ostringstream output;
    bool sig = true;
    for (Term t: this->getPolynomial()){
        int coef = t.getCoef();
        int pow = t.getPow();


        if (coef >= 0){
            if (!sig) {
                output << '-';
                sig = true;
            }
        }
        if (coef < 0) {
            if (sig){
                output << '+';
                sig = false;
            }
        }
        output << "(" << coef << "," << pow << ")";
    }
    std::cout << output.str() << (sig ? '+' : '-') <<  std::endl;
}
void Polynomial::print(){
    for (Term t: this->terms){
        std::cout << "(" << t.getCoef() << "," << t.getPow() << ")";
    }
    std::cout << std::endl;
}