#include "include/Bank.h"
#include "include/MapStorage.h"
#include "include/DistributedVectorAccountStorage.h"
#include <iostream>
#include <chrono>

int main() {
    DistributedVectorAccountStorage storage;
    //MapStorage storage;
    Bank bank(&storage);

    const int AntalAccounts = 1000;

    std::string sFirst = "";
    std::string sLast = "";
    std::string sNotFound = "notfound";

    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < AntalAccounts; i++) {
        std::string accountNumber = std::to_string(i);
        if (i == 0) sFirst = accountNumber;
        if (i == AntalAccounts - 1) sLast = accountNumber;
        bank.addAccount(accountNumber);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Init took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";

    // First account
    startTime = std::chrono::high_resolution_clock::now();
    BankAccount* p = bank.getAccount(sFirst);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";

    // Last account
    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sLast);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";

    // Not found
    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sNotFound);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Not found took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";
}
