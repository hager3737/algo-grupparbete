#include "../include/UtilityFunctions.h"
#include "../include/Constants.h"

  void addBankAccounts(Bank &bank, int AMOUNT_OF_ACCOUNTS) {

    for (int i = 0; i <= AMOUNT_OF_ACCOUNTS; i++) {
          std::string accountNumber = std::to_string(i);
          bank.addAccount(accountNumber);
      }

  }