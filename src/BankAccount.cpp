#include "../include/BankAccount.h"

BankAccount::BankAccount() {}

BankAccount::BankAccount(std::string accountNumber, float balance)
    : accountNumber(accountNumber), balance(balance) {}

std::string BankAccount::getAccountNumber() {
    return accountNumber;
}
