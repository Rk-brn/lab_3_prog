#pragma once

#include <string>
#include "Account.h"
#include "Goal.h"
#include "Contribution.h"
#include "Loan.h"

class User {
private:
    int id;                       // Уникальный ID пользователя
    std::string username;         // Имя пользователя
    std::string password;         // Пароль пользователя
    int balance;                  // Баланс пользователя (в копейках)
    Account* primaryAccount;      // Основной счет пользователя
    Goal* goal;                   // Цель
    Contribution* contribution;    // Вклад
    Loan* loan;                   // Кредит
    User* next;
public:
    // Конструктор
    User(int userId, const std::string& userName, const std::string& userPassword, int userBalance);

    // Деструктор
    ~User();

    // Сеттеры
    void setUsername(const std::string& userName);

    void setPassword(const std::string& userPassword);

    void setBalance(int userBalance);

    void setPrimaryAccount(Account* account);

    void setGoal(Goal* userGoal);

    void setContribution(Contribution* userContribution);

    void setLoan(Loan* userLoan);

    // Геттеры
    int getId() const;

    std::string getUsername() const;

    std::string getPassword() const;

    int getBalance() const;

    Account* getPrimaryAccount() const;

    Goal* getGoal() const;

    Contribution* getContribution() const;

    Loan* getLoan() const;
    // Метод для добавления пользователя в список
    void addUser(User* newUser);

    // Метод для удаления пользователя из списка
    void removeUser(User* userToRemove);

    // Метод для изменения имени пользователя и пароля
    void changeCredentials(const std::string& newUsername, const std::string& newPassword);

    // Метод для конвертации баланса в другую валюту
    void convertBalance(Conversion* conversion) const;

    // Метод для обновления баланса пользователя
    void updateBalance();

};