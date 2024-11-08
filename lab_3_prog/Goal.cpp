// Goal.cpp
#include "Goal.h"
#include <iostream>
using namespace std;

Goal::Goal(const char* goalName, int amount, const char* currency, int rate)
    : target_amount(amount), next(nullptr) {
    strncpy_s(name, goalName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    conversion = new Conversion(currency, rate);
}

Goal::~Goal() {
    delete conversion;
}

const char* Goal::getName() const {
    return name;
}

void Goal::setName(const char* goalName) {
    strncpy_s(name, goalName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

int Goal::getTargetAmount() const {
    return target_amount;
}

void Goal::setTargetAmount(int amount) {
    target_amount = amount;
}

Conversion* Goal::getConversion() const {
    return conversion;
}

void Goal::addGoal(Goal* newGoal) {
    newGoal->next = this;
    this->next = newGoal;
}

void Goal::removeGoal(Goal* goalToRemove) {
    // Если цель - первая в списке
    if (this == goalToRemove) {
        next = goalToRemove->next;
        delete goalToRemove;
        return;
    }

    // Ищем цель в списке
    Goal* current = this;
    while (current->next != nullptr) {
        if (current->next == goalToRemove) {
            current->next = goalToRemove->next;
            delete goalToRemove;
            return;
        }
        current = current->next;
    }
}

void Goal::convertTargetAmount(Conversion* conversion) const {
    if (conversion != nullptr) {
        int convertedAmount = conversion->convert(target_amount);
        std::cout << "Целевая сумма в " << conversion->getCurrency() << ": " << convertedAmount << std::endl;
    }
}