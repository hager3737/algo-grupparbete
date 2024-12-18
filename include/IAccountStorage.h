#ifndef I_ACCOUNT_STORAGE_H
#define I_ACCOUNT_STORAGE_H

#include "BankAccount.h"
#include <string>

class IAccountStorage {
public:
    virtual ~IAccountStorage() = default;
    virtual void addAccount(BankAccount account) = 0;
    virtual BankAccount* findAccount(std::string accountNumber) = 0;
};

#endif // I_ACCOUNT_STORAGE_H
