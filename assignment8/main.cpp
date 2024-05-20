#include <iomanip>
#include <iostream>
#include "BankAccount.h"
#include "Portfolio.h"
#include "ComboLock.h"
int main(){

//    BankAccount harrys_account(1000);
//    harrys_account.deposit(500);
//    harrys_account.withdraw(2000);
//    harrys_account.add_interest(1);
//    std::cout << std::fixed << std::setprecision(2) << harrys_account.get_balance() << std::endl;
    Portfolio p;
    p.deposit(2000, "S");
    p.deposit(1500, "C");
    p.print_balances();

    p.withdraw(500, "C");
    p.print_balances();

    p.transfer(1000, "C");
    p.print_balances();

    ComboLock cl(1,2,4);

    // eff with the lock
    std::cout << "Combo lock pass code: 124" << std::endl << "Open: " << (cl.open() ? "true" : "false") << std::endl;
    for (int i = 0; i < 2; i++) {
        cl.turn_right(1);
        cl.printDial();
        std::cout << "Open: " << (cl.open() ? "true" : "false") << std::endl;
    }
    // Sick little dial spin ftw
    cl.turn_right(42);
    cl.printDial();
    std::cout << "Open: " << (cl.open() ? "true" : "false") << std::endl;

    return 0;
}
