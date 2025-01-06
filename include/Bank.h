#ifndef BANK_H
#define BANK_H

#include "IAccountStorage.h"
#include <string>

class Bank {
    IAccountStorage* accountStorage;

public:
    Bank(IAccountStorage* storage);
    bool addAccount(std::string accountNumber);
    BankAccount* getAccount(std::string accountNumber);
    void displayAllAccounts();
    void sortAllAccounts();
    void displayFiveFirstAccounts();
    void shuffleAllAccounts();
};

#endif // BANK_H
