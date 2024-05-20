//
// Created by kelse on 5/6/2024.
//

#include "Polynomial.h"
#include "Term.h"

int main(){
    std::vector<Term> terms {
        Term(2, 1),
        Term(3, 2),
        Term(-4, 3)
    };
    Polynomial p(terms);
    Polynomial q(terms);

   // p.add(q);
    p.multiply(q);

    p.print();
    p.printRPN();
    return 0;
}
