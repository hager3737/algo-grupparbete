#include "../include/BankAccount.h"

BankAccount::BankAccount() : accountNumber("00000000"), balance(0) {}

BankAccount::BankAccount(std::string accountNumber, float balance)
    : balance(balance) {
        while (accountNumber.length() < 8) {
        accountNumber.insert(0, "0");
    }
    this->accountNumber = accountNumber;
    }

std::string BankAccount::getAccountNumber() {
    return accountNumber;
}

