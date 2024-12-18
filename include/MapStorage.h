#ifndef MAP_STORAGE_H
#define MAP_STORAGE_H

#include "IAccountStorage.h"
#include <map>

class MapStorage : public IAccountStorage {
    std::map<std::string, BankAccount> accounts;

public:
    void addAccount(BankAccount account) override;
    BankAccount* findAccount(std::string accountNumber) override;
};

#endif // MAP_STORAGE_H
