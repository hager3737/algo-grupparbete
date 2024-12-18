#include "../include/Bank.h"

Bank::Bank(IAccountStorage* storage) : accountStorage(storage) {}

bool Bank::addAccount(std::string accountNumber) {
    accountStorage->addAccount(BankAccount(accountNumber));
    return true;
}

BankAccount* Bank::getAccount(std::string accountNumber) {
    return accountStorage->findAccount(accountNumber);
}
