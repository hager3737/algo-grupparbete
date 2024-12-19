#ifndef DISTRIBUTED_VECTOR_ACCOUNT_STORAGE_H
#define DISTRIBUTED_VECTOR_ACCOUNT_STORAGE_H

#include "IAccountStorage.h"
#include <vector>

class DistributedVectorAccountStorage : public IAccountStorage {
    std::vector<BankAccount> accounts[10];

public:
    void addAccount(BankAccount account) override;
    BankAccount* findAccount(std::string accountNumber) override;
    std::vector<BankAccount> getAllAccounts() override; // Implemented method
};

#endif // DISTRIBUTED_VECTOR_ACCOUNT_STORAGE_H
