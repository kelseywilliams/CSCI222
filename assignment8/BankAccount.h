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

#ifndef BANKACOUNT_H
#define BANKACOUNT_H


class BankAccount {
    double balance;
public:
    BankAccount();
    BankAccount(double initial_balance);
    void deposit(double amount);
    void withdraw(double amount);
    void add_interest(double rate);
    double get_balance() const;

};


#endif
