#include "../include/Bank.h"
#include <iostream>
#include <vector>

Bank::Bank(IAccountStorage* storage) : accountStorage(storage) {}

bool Bank::addAccount(std::string accountNumber) {
    accountStorage->addAccount(BankAccount(accountNumber));
    return true;
}

BankAccount* Bank::getAccount(std::string accountNumber) {
    return accountStorage->findAccount(accountNumber);
}

void Bank::displayAllAccounts() {
    std::vector<BankAccount> accounts = accountStorage->getAllAccounts();
    for (BankAccount& account : accounts) {
        std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
    }
}
