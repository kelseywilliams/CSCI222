
#include "BankAccount.h"
#ifndef PORTFOLIO_H
#define PORTFOLIO_H


class Portfolio {
    BankAccount saving;
    BankAccount checking;
public:
    void deposit(double amount, std::string account);
    void withdraw(double amount, std::string account);
    void transfer(double amount, std::string account);
    void print_balances();
};


#endif
