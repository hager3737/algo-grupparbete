#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>

class BankAccount{
    std::string accountNumber;
    float balance;
public:
    BankAccount(){
    }

    BankAccount(std::string accountNumber, float balance = 0)
    :accountNumber(accountNumber),balance(balance)
    {
    }

    std::string getAccountNumber()
    {
	    return this->accountNumber;
    }
};

//INTERFACE - gränssnitt "standard"
class IAccountStorage {
public:    
    virtual void addAccount(BankAccount account) = 0;
	virtual BankAccount *findAccount(std::string accountNumber) = 0;        
};

class MapStorage : public IAccountStorage{
    std::map<std::string,BankAccount> accounts;
public:
    void addAccount(BankAccount account) override{
        accounts[account.getAccountNumber()] = account;
    }
    BankAccount *findAccount(std::string accountNumber){
        return &accounts[accountNumber];
    } 
    
};

class DistributedVectorAccountStorage : public IAccountStorage{
        std::vector<BankAccount> accounts0;
        std::vector<BankAccount> accounts1;
        std::vector<BankAccount> accounts2;
        std::vector<BankAccount> accounts3;
        std::vector<BankAccount> accounts4;
        std::vector<BankAccount> accounts5;
        std::vector<BankAccount> accounts6;
        std::vector<BankAccount> accounts7;
        std::vector<BankAccount> accounts8;
        std::vector<BankAccount> accounts9;
    
    public:
    void addAccount(BankAccount account) override{
        if(account.getAccountNumber().at(0) == '0'){
            accounts0.push_back(account);
        }       
        else if(account.getAccountNumber().at(0) == '1'){
            accounts1.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '2'){
            accounts2.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '3'){
            accounts3.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '4'){
            accounts4.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '5'){
            accounts5.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '6'){
            accounts6.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '7'){
            accounts7.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '8'){
            accounts8.push_back(account);
        }
        else if(account.getAccountNumber().at(0) == '9'){
            accounts9.push_back(account);
        }
    }

    BankAccount *findAccount( std::string accountNumber){
        BankAccount *ret = nullptr;
        std::vector<BankAccount> &accounts = accounts0;

        if(accountNumber.at(0) == '1'){
            accounts = accounts1;
        }
        if(accountNumber.at(0) == '2'){
            accounts = accounts2;
        }
        if(accountNumber.at(0) == '3'){
            accounts = accounts3;
        }
        if(accountNumber.at(0) == '4'){
            accounts = accounts4;
        }
        if(accountNumber.at(0) == '5'){
            accounts = accounts5;
        }
        if(accountNumber.at(0) == '6'){
            accounts = accounts7;
        }
        if(accountNumber.at(0) == '7'){
            accounts = accounts7;
        }
       if(accountNumber.at(0) == '8'){
            accounts = accounts8;
        }
          if(accountNumber.at(0) == '9'){
            accounts = accounts9;
        }


        for(BankAccount &account : accounts){
            if(account.getAccountNumber() == accountNumber ){
                //ret = &account;      
                return &account;                                  
            }
        }
        return ret;
  

    }

};

class VectorAccountStorage: public IAccountStorage{
        std::vector<BankAccount> accounts;
public:
    void addAccount(BankAccount account) override{
        accounts.push_back(account);
    }

    BankAccount *findAccount(std::string accountNumber){
        BankAccount *ret = nullptr;
        for(BankAccount &account : accounts){
            if(account.getAccountNumber() == accountNumber ){
                //ret = &account;      
                return &account;                                  
            }
        }
        return ret;
    }
    

};




class Bank
{
private:
	IAccountStorage * accountStorage;
public:
	Bank(IAccountStorage *storage):accountStorage(storage){

    }
	bool addAccount(std::string accountNumber){
        //validate
        //if something (accountNumber) return false
        accountStorage->addAccount(accountNumber);
        return true;
    }
	BankAccount *getAccount(std::string accountNumber){
        return accountStorage->findAccount(accountNumber);
    }
};


// Del 3 (Tarek): "RingQueue"
#include <iostream>
#include <string>
#include <array> // Standard library container for fixed-size arrays

// A template class for a ring buffer (or circular queue) implementation
// T is the data type of the elements (e.g., int, string), and N is the fixed capacity.
template <typename T, std::size_t N>
class RingQueue {
public:
    // Constructor: Initializes the ring buffer with head, tail, and full status
    RingQueue() : head(0), tail(0), full(false) {}

    // Adds a new element to the queue
    // If the queue is full, the oldest element will be overwritten.
    void enqueue(const T& value) {
        data[tail] = value;              // Add the new value at the tail position
        tail = (tail + 1) % N;           // Move the tail forward (wrap around using modulo)
        if (full) {
            head = (head + 1) % N;       // If the queue is full, move the head forward to overwrite
        }
        full = (tail == head);           // The queue is full if tail catches up to head
    }

    // Retrieves the value at a specific index relative to the head
    // Returns false if the index is invalid or the queue is empty.
    bool peek(std::size_t index, T& value) const {
        if (isEmpty() || index >= size()) return false; // Validate input
        value = data[(head + index) % N];               // Calculate the actual index in the buffer
        return true;
    }

    // Returns the current number of elements in the queue
    std::size_t size() const {
        if (full) return N;             // If the queue is full, size equals the total capacity
        if (tail >= head) return tail - head; // If no wrap-around, subtract head from tail
        return N - head + tail;         // If wrap-around occurred, calculate accordingly
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return !full && (head == tail); // Empty if not full and head equals tail
    }

private:
    std::array<T, N> data; // Fixed-size array to store elements
    std::size_t head;      // Index of the oldest element (start of the queue)
    std::size_t tail;      // Index where the next element will be inserted
    bool full;             // Indicates whether the queue is full
};


int main(int, char**){
    //VectorAccountStorage storage;
    //VectorAccountStorage storage;
    //MapStorage storage;
    DistributedVectorAccountStorage storage;
    //MapAccountStor age storage;
    Bank bank(&storage);

    const int AntalAccounts =  10000000;


    std::string sFirst = ""; 
    std::string sLast = ""; 
    std::string sNotFound = "notfound"; 

    std::cout << "INITIALIZE: " << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for(int i = 0;i < AntalAccounts; i++){
        std::string accountNumber =  std::to_string(i);
        if(i == 0){
            sFirst = accountNumber;
        }
        if(i == AntalAccounts-1){
            sLast = accountNumber;
        }
        bank.addAccount(accountNumber);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "INIT Took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    BankAccount *p = bank.getAccount(sFirst);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sLast);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sNotFound);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "NOT FOUND" << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    // Del 3: Ring Buffer (cirkulär kö):
    RingQueue<std::string, 10> queue;

    // Step 1: Enqueue elements and demonstrate overwriting
    std::cout << "\nDel 3: Ring Buffer (cirkulär kö) demonstration" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    
    std::cout << "Step 1: Enqueue elements and demonstrate overwriting" << std::endl;
    // Enqueue initial elements
    queue.enqueue("Anna");
    queue.enqueue("Bertil");
    queue.enqueue("Calle");
    queue.enqueue("David");
    queue.enqueue("Erik");
    queue.enqueue("Fredrik");
    queue.enqueue("Göran");
    queue.enqueue("Henrietta");
    queue.enqueue("Ivar");
    queue.enqueue("Jan");

    // Display initial elements
    std::cout << "- Queue list with initial elements (size " << queue.size() << "):" << std::endl;
    for (std::size_t i = 0; i < queue.size(); ++i) {
        std::string value;
        if (queue.peek(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
    }


    // Enqueue "Kenneth", which will overwrite "Anna"
    queue.enqueue("Kenneth");

    // Display updated queue elements
    std::cout << "\n- Queue list after enqueuing a new element (size " << queue.size() << "):" << std::endl;
    for (std::size_t i = 0; i < queue.size(); ++i) {
        std::string value;
        if (queue.peek(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
    }
    std::cout << std::endl;

    // Step 2: Search for "Henrietta" using a binary search-like method
    std::cout << "Step 2: Binary search\n";
    std::string search = "Henrietta";
    std::size_t start = 0;
    std::size_t end = queue.size() - 1;
    std::string current;
    bool found = false;

    std::cout << "Searching for \"" << search << "\"...\n" << std::endl;
    while (start <= end) {
        std::size_t currentIndex = (start + end) / 2;

        // Wrap-around and modular arithmetic handled by the peek method
        if (!queue.peek(currentIndex, current)) {
            std::cout << "Error accessing index " << currentIndex << std::endl;
            break;
        }

        std::cout << "Checking index " << currentIndex << ": " << current << std::endl;

        if (current == search) {
            found = true;
            break;
        }
        if (current < search) {
            start = currentIndex + 1;
        } else {
            end = currentIndex - 1;
        }
    }

    if (found) {
        std::cout << "\nFound: " << search << std::endl;
    } else {
        std::cout << "Not Found: " << search << std::endl;
    }

    return 0;
}
