#pragma once
#include "Transaction.h"

class Account {
private:
	char name[50];    // �������� �����
	Transaction* transactions; // ������ ����������
	Account* next;
	int transactionCount;

public:
	// �����������
	Account(const char* accountName);

	// ����������
	~Account();

	// ������ ��� ����� �����
	const char* getName() const;

	// ����� ��� ��������� ��������� �� ��������� ����
	Account* getNext() const;

	Transaction* getTransactions() const;

	// ������ ��� ����� �����
	void setName(const char* accountName);

	void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat);


	// ����� ��� ���������� ������ ����� � ������
	void addAccount(Account* newAccount);

	// ����� ��� �������� ����� �� ������
	void removeAccount(Account* accountToRemove);

	// ����� ��� ��������� �������� �������� �����
	void changeAccountName(const char* newAccountName);


	// ����� ��� ��������� ���������� ����������
	int getTransactionCount() const;
};