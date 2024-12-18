#pragma once
#include "Goal.h"
#include <iostream>

class LongTermGoal : public Goal {
private:
    int interestRate;

public:
    LongTermGoal(const std::string& goalName, int amount, const Conversion& conv, int rate)
        : Goal(goalName, amount, conv), interestRate(rate) {}

    LongTermGoal& operator=(const Goal& other) {
        if (this == &other) return *this; // Самоприсваивание
        copyFrom(other);
        return *this;
    }

    void copyFrom(const Goal& other) override {
        Goal::copyFrom(other); // Вызов базового метода для копирования общих данных

        if (const LongTermGoal* ltg = dynamic_cast<const LongTermGoal*>(&other)) {
            interestRate = ltg->interestRate; // Копирование interestRate, если это LongTermGoal
        }
        else {
            interestRate = 0; // Значение по умолчанию, если это обычный Goal
        }
    }

    int getInRate() const {
        return interestRate;
    }

    // Перегрузка метода convertTargetAmount (без вызова метода базового класса)
    void convertTargetAmount(const Conversion& conv) const override {
        if (!conv.getCurrency()) {
            throw std::runtime_error("Неверная валюта для конвертации.");
        }
        int  rubles = targetAmount;
        int convertedAmount = rubles / conv.getCurrencyRate();
        // Добавляем расчет процентов к целевой сумме.
        convertedAmount *= pow(1 + interestRate / 100.0, 1.0); 
        std::cout << "Целевая сумма в " << conv.getCurrency() << " с учетом процентов: " << convertedAmount << std::endl;
    }

    //LongTermGoal(const LongTermGoal& other) = delete;  //Запрет конструктора копирования
    //LongTermGoal& operator=(const LongTermGoal& other) = delete; //Запрет оператора присваивания

};