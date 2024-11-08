#pragma once
#include "Category.h"

class Transaction {
private:
	char description[100]; // �������� ����������
	int amount;      // ����� ����������
	char date[11];    // ���� ���������� (DD-MM-YYYY)
	char type[10];    // ��� ���������� (�����/������)
	Category* category;  // ��������� �� ���������
	Transaction* next;
public:
	// �����������
	Transaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat);

	// ����������
	~Transaction() {}

	// �������
	void setDescription(const char* desc);

	void setAmount(int amt);

	void setDate(const char* dt);

	void setType(const char* typ);

	void setCategory(Category* cat);
	void setNext(Transaction* newNext);

	// �������
	const char* getDescription() const;

	int getAmount() const;

	const char* getDate() const;

	const char* getType() const;

	Category* getCategory() const;

	Transaction* getNext() const;
	// ����� ��� ���������� ���������� � ������
	void addTransaction(Transaction* newTransaction);

	// ����� ��� �������� ���������� �� ������
	void removeTransaction(Transaction* transactionToRemove);

};