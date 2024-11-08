// Contribution.cpp
#include "Contribution.h"

Contribution::Contribution() : percent(0), minimum_deposit(0), next(nullptr) {}

Contribution::Contribution(int p, int min_dep) : percent(p), minimum_deposit(min_dep), next(nullptr) {}

Contribution::~Contribution() {}

int Contribution::getPercent() const {
    return percent;
}

void Contribution::setPercent(int p) {
    percent = p;
}

int Contribution::getMinimumDeposit() const {
    return minimum_deposit;
}

void Contribution::setMinimumDeposit(int min_dep) {
    minimum_deposit = min_dep;
}

bool Contribution::isValidDeposit(int deposit) const {
    return deposit >= minimum_deposit;
}

void Contribution::addContribution(Contribution* newContribution) {
    newContribution->next = this;
    this->next = newContribution;
}

void Contribution::removeContribution(Contribution* contributionToRemove) {
    // Если вклад - первый в списке
    if (this == contributionToRemove) {
        next = contributionToRemove->next;
        delete contributionToRemove;
        return;
    }

    // Ищем вклад в списке
    Contribution* current = this;
    while (current->next != nullptr) {
        if (current->next == contributionToRemove) {
            current->next = contributionToRemove->next;
            delete contributionToRemove;
            return;
        }
        current = current->next;
    }
}

int Contribution::calculateProfit(int deposit, int years) const {
    int profit = 0;
    double annualInterest = percent / 100.0;
    for (int i = 0; i < years; ++i) {
        profit += (int)(deposit * annualInterest);
        deposit += (int)(deposit * annualInterest);
    }
    return profit;
}