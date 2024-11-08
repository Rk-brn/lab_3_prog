#pragma once
#include "User.h"
#include "Account.h"

class Analytics {
private:
	int totalIncome;   // Общий доход
	int totalExpense;  // Общий расход
	User* user;     // Указатель на пользователя
	Account* account;  // Указатель на счет

public:
	// Конструктор
	Analytics(int income, int expense, User* userPtr, Account* accountPtr);

	// Деструктор
	~Analytics();

	// Геттеры
	int getTotalIncome() const;

	int getTotalExpense() const;

	User* getUser() const;

	Account* getAccount() const;

	// Сеттеры
	void setTotalIncome(int income);

	void setTotalExpense(int expense);

	void setUser(User* userPtr);

	void setAccount(Account* accountPtr);

	// Метод для обработки счета (подсчета общего дохода и расхода)
	void processAccount();

	// Метод для сравнения дохода и расхода и вывода результата
	void analyzeAccount();
};
