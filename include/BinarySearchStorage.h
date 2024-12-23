#ifndef BINARY_SEARCH_STORAGE_H
#define BINARY_SEARCH_STORAGE_H

#include "IAccountStorage.h"
#include  <vector>

class BinarySearchStorage : public IAccountStorage {
    std::vector<BankAccount> accounts;

public:
void addAccount(BankAccount account) override;
BankAccount* findAccount(std::string accountNumber) override;
std::vector<BankAccount> getAllAccounts() override; // Implemented method
};

#endif //BINARY_SEARCH_STORAGE_H