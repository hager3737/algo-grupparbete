#include "../include/BinarySearchStorage.h"

void BinarySearchStorage::addAccount(BankAccount account) {
    accounts.push_back(account);
}

BankAccount* BinarySearchStorage::findAccount(std::string accountNumber) {
    int start = 0;
    int end = accounts.size() - 1;

    while (start <= end) {
        int current = (start + end) / 2; 

        if (accounts[current].getAccountNumber() == accountNumber) {
            return &accounts[current]; 
        } else if (accountNumber > accounts[current].getAccountNumber()) {
            start = current + 1; 
        } else {
            end = current - 1; 
        }
    }

    return nullptr; 
}

std::vector<BankAccount> BinarySearchStorage::getAllAccounts() {
    std::vector<BankAccount> allAccounts;
    for (auto& account : accounts) {
        allAccounts.insert(allAccounts.end(), account);
    }
    return allAccounts;
}