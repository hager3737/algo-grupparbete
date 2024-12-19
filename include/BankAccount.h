#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class BankAccount {
    std::string accountNumber;
    float balance;

    //std::string padAccountNumber(const std::string& accountNumber);  Om vi vill använda <iomanip>

public:
    BankAccount();
    BankAccount(std::string accountNumber, float balance = 0);
    std::string getAccountNumber();
};

#endif // BANK_ACCOUNT_H
