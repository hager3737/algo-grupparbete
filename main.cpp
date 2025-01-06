#include "include/Bank.h"
#include "include/UtilityFunctions.h"
#include "include/BinarySearchStorage.h"
#include <iostream>
#include <chrono>
#include "include/Constants.h"

int main() {
    BinarySearchStorage storage;
    Bank bank(&storage);

    std::cout << "Time for generating random accounts starting..." << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();

    addBankAccounts(bank, AMOUNT_OF_ACCOUNTS);

    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Time for generating random accounts completed. It took " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;

    std::cout << "Five first accounts unsorted:" << std::endl;
    
    bank.shuffleAllAccounts();
    bank.displayFiveFirstAccounts();

    std::cout << "Time for sorting random accounts starting..." << std::endl;
    startTime = std::chrono::high_resolution_clock::now();

    // sorting
    bank.sortAllAccounts();

    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";

    std::cout << "Five first accounts sorted:" << std::endl;

    bank.displayFiveFirstAccounts();

}
