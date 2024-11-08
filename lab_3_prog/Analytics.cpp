// Analytics.cpp
#include "Analytics.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;


Analytics::Analytics(int income, int expense, User* userPtr, Account* accountPtr)
    : totalIncome(income), totalExpense(expense), user(userPtr), account(accountPtr) {}

Analytics::~Analytics() {}

int Analytics::getTotalIncome() const {
    return totalIncome;
}

int Analytics::getTotalExpense() const {
    return totalExpense;
}

User* Analytics::getUser() const {
    return user;
}

Account* Analytics::getAccount() const {
    return account;
}

void Analytics::setTotalIncome(int income) {
    totalIncome = income;
}

void Analytics::setTotalExpense(int expense) {
    totalExpense = expense;
}

void Analytics::setUser(User* userPtr) {
    user = userPtr;
}

void Analytics::setAccount(Account* accountPtr) {
    account = accountPtr;
}

void Analytics::processAccount() {
    Transaction* currentTransaction = account->getTransactions();

    while (currentTransaction != nullptr) {
        if (strcmp(currentTransaction->getType(), "income") == 0) {
            totalIncome += currentTransaction->getAmount();
        }
        else if (strcmp(currentTransaction->getType(), "expense") == 0) {
            totalExpense += currentTransaction->getAmount();
        }

        currentTransaction = currentTransaction->getNext();
    }
}

void Analytics::analyzeAccount() {
    processAccount();

    if (totalIncome >= totalExpense) {
        cout << "Счет профицитный." << endl;
    }
    else {
        int difference = totalExpense - totalIncome;
        cout << "Счет непрофицитный. Необходимо иметь на счету " << difference << " копеек, чтобы разница между доходами и расходами была 0." << endl;
    }
}