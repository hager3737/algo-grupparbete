#ifndef I_ACCOUNT_STORAGE_H
#define I_ACCOUNT_STORAGE_H

#include "BankAccount.h"
#include <string>

class IAccountStorage {
public:
    virtual ~IAccountStorage() = default;
    virtual void addAccount(BankAccount account) = 0;
    virtual BankAccount* findAccount(std::string accountNumber) = 0;
    virtual std::vector<BankAccount> getFiveFirstAccounts() = 0;
    virtual std::vector<BankAccount> sortAccounts() = 0;
    virtual std::vector<BankAccount> shuffleAccounts() = 0;
    virtual bool findAccountBinaryAlgorithm(std::string accountNumber) = 0;
};

#endif // I_ACCOUNT_STORAGE_H
