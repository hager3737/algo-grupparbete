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

void Bank::sortAllAccounts() {
    std::vector<BankAccount> accounts = accountStorage->sortAccounts();
}

void Bank::shuffleAllAccounts() {
    std::vector<BankAccount> accounts = accountStorage->shuffleAccounts();
}

void Bank::displayAllAccounts() {
    std::vector<BankAccount> accounts = accountStorage->getAllAccounts();
    for (BankAccount& account : accounts) {
        std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
    }
}

void Bank::displayFiveFirstAccounts() {
    std::vector<BankAccount> accounts = accountStorage->getFiveFirstAccounts();

    int count = 1;

    for(BankAccount& account : accounts) {
        std::cout << "Account number " << count << ": " << account.getAccountNumber() << std::endl;
        count++;
    }
}
