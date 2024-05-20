//
// Created by kelse on 5/7/2024.
//

#include "Portfolio.h"
void Portfolio::deposit(double amount, std::string account){
    if (account == "S"){
        this->saving.deposit(amount);
    }
    else if (account == "C"){
        this->checking.deposit(amount);
    }
}
void Portfolio::withdraw(double amount, std::string account){
    if (account == "S"){
        this->saving.withdraw(amount);
    }
    else if (account == "C"){
        this->checking.withdraw(amount);
    }
}
void Portfolio::transfer(double amount, std::string account){
    if (account == "C"){
        this->checking.withdraw(amount);
        this->saving.deposit(amount);
    }
    else if (account == "S"){
        this->saving.withdraw(amount);
        this->checking.deposit(amount);
    }
}
void Portfolio::print_balances(){
    std::cout << "Balance of account at " << (void *)(this) << std::endl;
    std::cout << "Savings Balance:" << this->saving.get_balance() << std::endl;
    std::cout << "Checkings Balance:" << this->checking.get_balance() << std::endl << std::endl;
}