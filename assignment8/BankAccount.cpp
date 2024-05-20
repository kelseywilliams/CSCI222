
#include "BankAccount.h"

BankAccount::BankAccount()
{
    balance = 0;
}
BankAccount::BankAccount(double initial_balance)
{
    balance = initial_balance;
}
void BankAccount::deposit(double amount)
{
    balance = balance + amount;
}
void BankAccount::withdraw(double amount)
{
    const double PENALTY = 10;
    if (amount > balance)
    {
        balance = balance - PENALTY;
    }
    else
    {
        balance = balance - amount;
    }
}
void BankAccount::add_interest(double rate)
{
    double amount = balance * rate / 100;
    deposit(amount);
}
double BankAccount::get_balance() const
{
    return balance;
}