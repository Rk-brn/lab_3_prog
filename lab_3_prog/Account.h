#pragma once
#include "Transaction.h"

class Account {
protected:
	char name[50];    // Название счета
	Transaction* transactions; // Список транзакций
	Account* next;
	int transactionCount;
	int balance;
	static int accountCount; // Статическое поле для подсчета счетов
public:
	// Конструктор
	Account(const char* accountName);

	// Деструктор
	virtual ~Account() = default; // деструктор виртуальный

	//Account(const Account& other) = delete; // Запрещаем конструктор копирования
	//Account& operator=(const Account& other) = delete; // Запрещаем оператор присваивания

	// Геттер для имени счета
	const char* getName() const;

	// Метод для получения указателя на следующий счет
	Account* getNext() const;

	Transaction* getTransactions() const;

	// Сеттер для имени счета
	void setName(const char* accountName);

	void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat, int extraData);

	// Метод для добавления нового счета в список
	void addAccount(Account* newAccount);

	// Метод для удаления счета из списка
	void removeAccount(Account* accountToRemove);

	// Метод для изменения названия текущего счета
	void changeAccountName(const char* newAccountName);


	// Метод для получения количества транзакций
	int getTransactionCount() const;

	virtual int getBalance() {
		return balance;
	}

	/*virtual bool canWithdraw(double amount) = 0;*/

	void printBalance() {
		std::cout << "Баланс: " << getBalance() << std::endl;
	}

	static int getAccountCount() { return accountCount; } // Статический метод


};