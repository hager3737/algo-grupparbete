#include "../include/BankAccount.h"

BankAccount::BankAccount() : accountNumber("0000"), balance(0) {}

BankAccount::BankAccount(std::string accountNumber, float balance)
    : balance(balance) {
        while (accountNumber.length() < 4) {
        accountNumber.insert(0, "0");
    }
    this->accountNumber = accountNumber;
    }

// BankAccount::BankAccount(std::string accountNumber, float balance)              Om vi vill använda <iomanip>
//     : accountNumber(padAccountNumber(accountNumber)), balance(balance) {}

std::string BankAccount::getAccountNumber() {
    return accountNumber;
}

// std::string BankAccount::padAccountNumber(const std::string& accountNumber) {        Om vi vill använda <iomanip>
//     std::ostringstream padded;
//     padded << std::setw(4) << std::setfill('0') << accountNumber; // Ensures padding to 10 digits
//     return padded.str();
// }