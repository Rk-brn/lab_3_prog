#pragma once
#include "Transaction.h"

class Account {
private:
	char name[50];    // Название счета
	Transaction* transactions; // Список транзакций
	Account* next;
	int transactionCount;

public:
	// Конструктор
	Account(const char* accountName);

	// Деструктор
	~Account();

	// Геттер для имени счета
	const char* getName() const;

	// Метод для получения указателя на следующий счет
	Account* getNext() const;

	Transaction* getTransactions() const;

	// Сеттер для имени счета
	void setName(const char* accountName);

	void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat);


	// Метод для добавления нового счета в список
	void addAccount(Account* newAccount);

	// Метод для удаления счета из списка
	void removeAccount(Account* accountToRemove);

	// Метод для изменения названия текущего счета
	void changeAccountName(const char* newAccountName);


	// Метод для получения количества транзакций
	int getTransactionCount() const;
};