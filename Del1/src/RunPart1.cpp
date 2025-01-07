#include "include/Bank.h"
#include "include/UtilityFunctions.h"
#include "include/BinarySearchStorage.h"
#include <iostream>
#include <chrono>
#include "include/Constants.h"
#include "../include/RunPart1.h"

void runPart1() {
    BinarySearchStorage storage;
    Bank bank(&storage);

    std::cout << "Time for generating random accounts starting" << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();

    addBankAccounts(bank, AMOUNT_OF_ACCOUNTS);

    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Time for generating random accounts completed. It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << "ns" << std::endl;

    std::cout << "Five first accounts unsorted:" << std::endl;
    
    bank.shuffleAllAccounts();
    bank.displayFiveFirstAccounts();

    std::cout << "Time for sorting random accounts starting" << std::endl;
    startTime = std::chrono::high_resolution_clock::now();

    // sorting
    bank.sortAllAccounts();

    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << " ns\n";

    std::cout << "Five first accounts sorted:" << std::endl;

    bank.displayFiveFirstAccounts();

    std::cout << "Time for finding one account starting" << std::endl;
    startTime = std::chrono::high_resolution_clock::now();

    BankAccount *p = bank.getAccount("00001337");
    if(p != nullptr) {
        std::cout << "Account found." << std::endl;
    }
    else {
        std::cout << "Account not found." << std::endl;
    }

    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Finding account took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << " ns\n";

    std::cout << "Time for finding one account with binary algorithm starting" << std::endl;
    startTime = std::chrono::high_resolution_clock::now();

    if(bank.getAccountBinaryAlgorithm("00001337")) {
        std::cout << "Account found." << std::endl;
    }
    else {
        std::cout << "Account not found." << std::endl;
    }
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Finding account took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << " ns\n";

}
