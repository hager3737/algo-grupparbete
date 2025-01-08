#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>



class BinarySearchStorage {
    std::vector<std::string> accounts;


    public:
    void addAccount(const std::string& newAccount) {
        accounts.push_back(newAccount);

    }
    
    bool binarySearch(const std::string& accountSearchedFor) {
        int start = 0;
        int end = accounts.size() - 1;
        while (start <=end){
            int current = start + (end -start) / 2;
            if (accounts[current] == accountSearchedFor)
            {
                return true;
            }
            if (accountSearchedFor > accounts[current]){
                start = current + 1;
            
            }
            else {
                end = current - 1;
            }
            
            
        }
        return false;
    }
    
    // void printFirstAndLastAccounts(){
    //     std::cout << "First 3 accounts " << std::endl;
    //     for (int i = 0; i < 3 && i < accounts.size(); i++)
    //     {
    //         std::cout << accounts[i] << std::endl;
    //     }
    //     std::cout << "Last 3 accounts " << std::endl;
    //     for (int i = accounts.size() - 3; i < accounts.size(); i++)
    //     {
    //         std::cout << accounts[i] << std::endl;
    //     }
        
    // }

    void sortAccounts(){
        std::sort(accounts.begin(), accounts.end());
    }
    
    std::vector<std::string>& getAccounts(){
        return accounts;
    }
};




int main(){
    BinarySearchStorage storage;

    int AntalAccounts = 10000000;

    
    for (int i = 1; i <= AntalAccounts; i++) {
        std::ostringstream oss;
        oss << std::setw(10) << std::setfill('0') << i;
        storage.addAccount(oss.str());
    }

    //storage.printFirstAndLastAccounts();

    std::string searchForAccount = "0000001337";
    std::cout << "Binary search for " << searchForAccount << std::endl;
    auto startTime= std::chrono::high_resolution_clock::now();
    bool found = storage.binarySearch(searchForAccount);
    auto endTime = std::chrono::high_resolution_clock::now();

    if (found == true) {
        std::cout << "Account found in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;
    }
    else {
        std::cout << "Account not found in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;
    }


    
    std::random_device rd;
    std::mt19937 g(rd());
    std::cout << "Shuffling accounts" << std::endl;
    std::shuffle(storage.getAccounts().begin(), storage.getAccounts().end(), g);

    //storage.printFirstAndLastAccounts();


    
    std::cout << "Sorting acounts " << std::endl;
    startTime= std::chrono::high_resolution_clock::now();
    storage.sortAccounts();
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting done in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;

    //storage.printFirstAndLastAccounts();

    
    std::cout << "Algoritmsearch for " << searchForAccount << std::endl;
    startTime= std::chrono::high_resolution_clock::now();
    bool sfound = std::binary_search(storage.getAccounts().begin(), storage.getAccounts().end(), searchForAccount);
    endTime = std::chrono::high_resolution_clock::now();

    if (sfound == true) {
        std::cout << "Account found in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl; 
    }
    else {
        std::cout << "Account not found in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;
    }

    return 0;


   
}