#ifndef BINARY_SEARCH_STORAGE_H
#define BINARY_SEARCH_STORAGE_H

#include "IAccountStorage.h"
#include  <vector>
#include <algorithm>
#include <random>

class BinarySearchStorage : public IAccountStorage {
    std::vector<BankAccount> accounts;

public:
void addAccount(BankAccount account) override;
BankAccount* findAccount(std::string accountNumber) override;
bool findAccountBinaryAlgorithm(std::string accountNumber) override;
std::vector<BankAccount> getFiveFirstAccounts() override;
std::vector<BankAccount> sortAccounts() override;
std::vector<BankAccount> shuffleAccounts() override;
};

#endif //BINARY_SEARCH_STORAGE_H