// Account.cpp
#include "Account.h"
#include <cstring>

Account::Account(const char* accountName) : next(nullptr) {
    strncpy_s(name, accountName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    transactions = nullptr;
    transactionCount = 0;
}

Account::~Account() {
    Transaction* current = transactions;
    while (current != nullptr) {
        Transaction* next = current->getNext();
        delete current;
        current = next;
    }
}

const char* Account::getName() const {
    return name;
}

Account* Account::getNext() const {
    return next;
}

Transaction* Account::getTransactions() const {
    return transactions;
}

void Account::setName(const char* accountName) {
    strncpy_s(name, accountName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Account::addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat) {
    Transaction* newTransaction = new Transaction(desc, amt, dt, typ, cat);

    if (transactions == nullptr) {
        transactions = newTransaction;
    }
    else {
        Transaction* current = transactions;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newTransaction);
    }

    transactionCount++;
}

void Account::addAccount(Account* newAccount) {
    newAccount->next = this;
    this->next = newAccount;
}

void Account::removeAccount(Account* accountToRemove) {
    // Если счет - первый в списке
    if (this == accountToRemove) {
        next = accountToRemove->next;
        delete accountToRemove;
        return;
    }

    // Ищем счет в списке
    Account* current = this;
    while (current->next != nullptr) {
        if (current->next == accountToRemove) {
            current->next = accountToRemove->next;
            delete accountToRemove;
            return;
        }
        current = current->next;
    }
}

void Account::changeAccountName(const char* newAccountName) {
    strncpy_s(name, newAccountName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

int Account::getTransactionCount() const {
    return transactionCount;
}