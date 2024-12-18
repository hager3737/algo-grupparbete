#include "../include/VectorAccountStorage.h"

void VectorAccountStorage::addAccount(BankAccount account) {
    accounts.push_back(account);
}

BankAccount* VectorAccountStorage::findAccount(std::string accountNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}
