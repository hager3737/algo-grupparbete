#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class BankAccount {
    std::string accountNumber;
    float balance;

public:
    BankAccount();
    BankAccount(std::string accountNumber, float balance = 0);
    std::string getAccountNumber() const;
};

#endif // BANK_ACCOUNT_H
