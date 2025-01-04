#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
//enkel draft för jämförelse mellan egen och STL binarysearch som vi visade förra veckan
//Johann och jag håller på att få klart det sista på den andra verisonen
//Skall kolla med Stefan ang best practice ang sort och search


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
    // funktion för att se om sort,shuffle och generering funkar. Kan tas bort vid presentation.
    // går även skriva en issorted funktion
    void printFirstAndLastAccounts(){
        std::cout << "First 3 accounts " << std::endl;
        for (int i = 0; i < 3 && i < accounts.size(); i++)
        {
            std::cout << accounts[i] << std::endl;
        }
        std::cout << "Last 3 accounts " << std::endl;
        for (int i = accounts.size() - 3; i < accounts.size(); i++)
        {
            std::cout << accounts[i] << std::endl;
        }
        
    }

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

    //loop för att generera och padda konton med 00 och 10 tecken
    for (int i = 1; i <= AntalAccounts; i++) {
        std::ostringstream oss;
        oss << std::setw(10) << std::setfill('0') << i;
        storage.addAccount(oss.str());
    }

    storage.printFirstAndLastAccounts();

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

    storage.printFirstAndLastAccounts();


    // sorterar konton och mäter tiden
    std::cout << "Sorting acounts " << std::endl;
    startTime= std::chrono::high_resolution_clock::now();
    storage.sortAccounts();
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting done in "<< std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;

    storage.printFirstAndLastAccounts();

    // STL algo searchen för att jämföra mot våran egen
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