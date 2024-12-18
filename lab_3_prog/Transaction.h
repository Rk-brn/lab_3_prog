#pragma once
#include "Category.h"
#include <iostream>
#include <string>
class Transaction {
protected:
	char description[100]; // Описание транзакции
	int amount;      // Сумма транзакции
	char date[11];    // Дата транзакции (DD-MM-YYYY)
	char type[10];    // Тип транзакции (доход/расход)
	Category* category;  // Указатель на категорию
	Transaction* next;
public:
	// Конструктор
	Transaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat);

	

	// Сеттеры
	void setDescription(const char* desc);

	void setAmount(int amt);

	void setDate(const char* dt);

	void setType(const char* typ);

	void setCategory(Category* cat);
	void setNext(Transaction* newNext);

	// Геттеры
	const char* getDescription() const;

	int getAmount() const;

	const char* getDate() const;

	const char* getType() const;

	Category* getCategory() const;

	Transaction* getNext() const;
	// Метод для добавления транзакции в список
	void addTransaction(Transaction* newTransaction);

	// Метод для удаления транзакции из списка
	void removeTransaction(Transaction* transactionToRemove);


	const std::string& getDescriptionRef() const { return description; }
	
	friend void printTransaction(const Transaction& t);
	
	
	/*const std::string* getTypePtr() const { return &type; }*/

	

	~Transaction() = default;
};