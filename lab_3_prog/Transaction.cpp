// Transaction.cpp
#include "Transaction.h"
#include <cstring>

Transaction::Transaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat)
    : amount(amt), category(cat), next(nullptr) {
    strncpy_s(description, desc, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
    strncpy_s(date, dt, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';
    strncpy_s(type, typ, sizeof(type) - 1);
    type[sizeof(type) - 1] = '\0';
}

void Transaction::setDescription(const char* desc) {
    strncpy_s(description, desc, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
}

void Transaction::setAmount(int amount) {
    amount = amount;
}

void Transaction::setDate(const char* dt) {
    strncpy_s(date, dt, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';
}

void Transaction::setType(const char* typ) {
    strncpy_s(type, typ, sizeof(type) - 1);
    type[sizeof(type) - 1] = '\0';
}

void Transaction::setCategory(Category* cat) {
    category = cat;
}

void Transaction::setNext(Transaction* newNext) {
    next = newNext;
}

const char* Transaction::getDescription() const {
    return description;
}

int Transaction::getAmount() const {
    return amount;
}

const char* Transaction::getDate() const {
    return date;
}

const char* Transaction::getType() const {
    return type;
}

Category* Transaction::getCategory() const {
    return category;
}

Transaction* Transaction::getNext() const {
    return next;
}

void Transaction::addTransaction(Transaction* newTransaction) {
    newTransaction->next = this;
    this->next = newTransaction;
}

void Transaction::removeTransaction(Transaction* transactionToRemove) {
    // Если транзакция - первая в списке
    if (this == transactionToRemove) {
        next = transactionToRemove->next;
        delete transactionToRemove;
        return;
    }

    // Ищем транзакцию в списке
    Transaction* current = this;
    while (current->next != nullptr) {
        if (current->next == transactionToRemove) {
            current->next = transactionToRemove->next;
            delete transactionToRemove;
            return;
        }
        current = current->next;
    }
}