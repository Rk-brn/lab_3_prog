#pragma once
#include "Account.h"

class PremiumAccount : public Account {
private:
    int bonusPoints;

public:
    // Конструктор
    PremiumAccount(const char* accountName, int initialBonusPoints) : Account(accountName), bonusPoints(initialBonusPoints) {}

    ~PremiumAccount() = default;

    // Геттер для бонусных баллов
    int getBonusPoints() const { return bonusPoints; }

    // Сеттер для бонусных баллов
    void setBonusPoints(int points) { bonusPoints = points; }

    //Перегрузка метода базоваго класса (с вызовом базового класса)
    void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat, int pointsEarned) {
        Account::addTransaction(desc, amt, dt, typ, cat);
        bonusPoints += pointsEarned;
        std::cout << "Транзакция добавлена на премиум счет(с вызовом базового класса).\n";
    }
    int getBalance() override { return balance + (bonusPoints / 10); }
};