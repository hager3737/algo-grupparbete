#ifndef VECTOR_ACCOUNT_STORAGE_H
#define VECTOR_ACCOUNT_STORAGE_H

#include "IAccountStorage.h"
#include <vector>

class VectorAccountStorage : public IAccountStorage {
    std::vector<BankAccount> accounts;

public:
    void addAccount(BankAccount account) override;
    BankAccount* findAccount(std::string accountNumber) override;
};

#endif // VECTOR_ACCOUNT_STORAGE_H
