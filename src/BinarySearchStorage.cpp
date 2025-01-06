    #include "../include/BinarySearchStorage.h"

    void BinarySearchStorage::addAccount(BankAccount account) {
        accounts.push_back(account);
    }

    std::vector<BankAccount> BinarySearchStorage::sortAccounts() {
        std::sort(accounts.begin(), accounts.end(), [](BankAccount& a, BankAccount& b) {
            return a.getAccountNumber() < b.getAccountNumber();
        });

        return accounts;
    }

    std::vector<BankAccount> BinarySearchStorage::shuffleAccounts() {

        std::random_device random; 
        std::mt19937 gen(random());

        std::shuffle(accounts.begin(), accounts.end(), random);

        return accounts;
    }

    BankAccount* BinarySearchStorage::findAccount(std::string accountNumber) {
        int start = 0;
        int end = accounts.size() - 1;

        while (start <= end) {
            int current = (start + end) / 2; 

            if (accounts[current].getAccountNumber() == accountNumber) {
                return &accounts[current]; 
            } else if (accountNumber > accounts[current].getAccountNumber()) {
                start = current + 1; 
            } else {
                end = current - 1; 
            }
        }

        return nullptr; 
    }

    std::vector<BankAccount> BinarySearchStorage::getAllAccounts() {
        return accounts;
    }

    std::vector<BankAccount> BinarySearchStorage::getFiveFirstAccounts() {
        size_t count = std::min(accounts.size(), size_t(5));

        return std::vector<BankAccount>(accounts.begin(), accounts.begin() + count);
    }