#include "../include/MapStorage.h"

void MapStorage::addAccount(BankAccount account) {
    accounts[account.getAccountNumber()] = account;
}

BankAccount* MapStorage::findAccount(std::string accountNumber) {
    return &accounts[accountNumber];
}
