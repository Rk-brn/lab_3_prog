#include "Goal.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string> // для std::string




Goal::Goal(const std::string& goalName, int amount, const Conversion& conv) : name(goalName), targetAmount(amount), conversion(new Conversion(conv)), next(nullptr) {}

Goal::Goal(const Goal& other) : name(other.name), targetAmount(other.targetAmount), conversion(new Conversion(*other.conversion)), next(nullptr) {}



const std::string& Goal::getName() const {
    return name;
}

void Goal::setName(const std::string& goalName) {
    name = goalName;
}

int Goal::getTargetAmount() const {
    return targetAmount;
}

void Goal::setTargetAmount(int amount) {
    targetAmount = amount;
}






std::string Goal::extractSubName(size_t startPos, size_t length) const {
    if (startPos >= name.length() || startPos + length > name.length()) {
        throw std::out_of_range("Недопустимый диапазон для извлечения подстроки.");
    }
    return name.substr(startPos, length);
}

bool Goal::containsKeyword(const std::string& keyword) const {
    return name.find(keyword) != std::string::npos;
}

void Goal::toUpperName() {
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
}

void Goal::addGoal(Goal* newGoal) {
    if (newGoal == nullptr) {
        throw std::invalid_argument("Нельзя добавить пустой указатель.");
    }
    newGoal->next = this->next;
    this->next = newGoal;
}

void Goal::removeGoal(Goal* goalToRemove) {
    if (goalToRemove == nullptr) {
        throw std::invalid_argument("Нельзя удалить пустой указатель.");
    }
    if (this == goalToRemove) {
        if (this->next != nullptr) {
            Goal* temp = this->next;
            this->next = nullptr;
            delete this;
            return;
        }
        else {
            delete this;
            return;
        }
    }

    Goal* current = this;
    while (current->next != nullptr) {
        if (current->next == goalToRemove) {
            current->next = goalToRemove->next;
            delete goalToRemove;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error("Цель не найдена в списке.");
}

void Goal::convertTargetAmount(const Conversion& conv) const {
    if (!conv.getCurrency()) {
        throw std::runtime_error("Неверная валюта для конвертации.");
    }
    double rubles = targetAmount;
    double convertedAmount = rubles / conv.getCurrencyRate();
    std::cout << "Целевая сумма в " << conv.getCurrency() << ": " << convertedAmount << std::endl;
}

void Goal::copyFrom(const Goal& other) {
    name = other.name;
    targetAmount = other.targetAmount;
    conversion = std::make_unique<Conversion>(*other.conversion); // Глубокое копирование Conversion
    next = nullptr; // next не копируется
}
