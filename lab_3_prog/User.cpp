// User.cpp
#include "User.h"
#include <cstring>
#include <iostream>


User::User(int userId, const std::string& userName, const std::string& userPassword, int userBalance)
    : id(userId), username(userName), password(userPassword), balance(userBalance),
    primaryAccount(nullptr), goal(nullptr), contribution(nullptr), loan(nullptr), next(nullptr) {}

User::~User() {
    delete primaryAccount;
    delete goal;
    delete contribution;
    delete loan;
}

void User::setUsername(const std::string& userName) {
    username = userName;
}

void User::setPassword(const std::string& userPassword) {
    password = userPassword;
}

void User::setBalance(int userBalance) {
    balance = userBalance;
}

void User::setPrimaryAccount(Account* account) {
    primaryAccount = account;
}

void User::setGoal(Goal* userGoal) {
    goal = userGoal;
}

void User::setContribution(Contribution* userContribution) {
    contribution = userContribution;
}

void User::setLoan(Loan* userLoan) {
    loan = userLoan;
}

int User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

int User::getBalance() const {
    return balance;
}

Account* User::getPrimaryAccount() const {
    return primaryAccount;
}

Goal* User::getGoal() const {
    return goal;
}

Contribution* User::getContribution() const {
    return contribution;
}

Loan* User::getLoan() const {
    return loan;
}

void User::addUser(User* newUser) {
    newUser->next = this;
    this->next = newUser;
}

void User::removeUser(User* userToRemove) {
    if (this == userToRemove) {
        next = userToRemove->next;
        delete userToRemove;
        return;
    }

    User* current = this;
    while (current->next != nullptr) {
        if (current->next == userToRemove) {
            current->next = userToRemove->next;
            delete userToRemove;
            return;
        }
        current = current->next;
    }
}

void User::changeCredentials(const std::string& newUsername, const std::string& newPassword) {
    setUsername(newUsername);
    setPassword(newPassword);
}

void User::convertBalance(Conversion* conversion) const {
    if (conversion != nullptr) {
        int convertedBalance = conversion->convert(balance);
        std::cout << "Баланс в " << conversion->getCurrency() << ": " << convertedBalance << std::endl;
    }
}

void User::updateBalance() {
    balance = 0;

    Account* currentAccount = primaryAccount;
    while (currentAccount != nullptr) {
        Transaction* currentTransaction = currentAccount->getTransactions();
        while (currentTransaction != nullptr) {
            if (strcmp(currentTransaction->getType(), "income") == 0) {
                balance += currentTransaction->getAmount();
            }
            else if (strcmp(currentTransaction->getType(), "expense") == 0) {
                balance -= currentTransaction->getAmount();
            }
            currentTransaction = currentTransaction->getNext();
        }
        currentAccount = currentAccount->getNext();
    }
}