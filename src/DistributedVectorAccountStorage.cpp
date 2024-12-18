#include "../include/DistributedVectorAccountStorage.h"

void DistributedVectorAccountStorage::addAccount(BankAccount account) {
    int index = account.getAccountNumber().at(0) - '0';
    accounts[index].push_back(account);
}

BankAccount* DistributedVectorAccountStorage::findAccount(std::string accountNumber) {
    int index = accountNumber.at(0) - '0';
    for (auto& account : accounts[index]) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}
