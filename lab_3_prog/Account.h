#pragma once
#include "Transaction.h"

class Account {
protected:
	char name[50];    // �������� �����
	Transaction* transactions; // ������ ����������
	Account* next;
	int transactionCount;
	int balance;
	static int accountCount; // ����������� ���� ��� �������� ������
public:
	// �����������
	Account(const char* accountName);

	// ����������
	virtual ~Account() = default; // ���������� �����������

	//Account(const Account& other) = delete; // ��������� ����������� �����������
	//Account& operator=(const Account& other) = delete; // ��������� �������� ������������

	// ������ ��� ����� �����
	const char* getName() const;

	// ����� ��� ��������� ��������� �� ��������� ����
	Account* getNext() const;

	Transaction* getTransactions() const;

	// ������ ��� ����� �����
	void setName(const char* accountName);

	void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat, int extraData);

	// ����� ��� ���������� ������ ����� � ������
	void addAccount(Account* newAccount);

	// ����� ��� �������� ����� �� ������
	void removeAccount(Account* accountToRemove);

	// ����� ��� ��������� �������� �������� �����
	void changeAccountName(const char* newAccountName);


	// ����� ��� ��������� ���������� ����������
	int getTransactionCount() const;

	virtual int getBalance() {
		return balance;
	}

	/*virtual bool canWithdraw(double amount) = 0;*/

	void printBalance() {
		std::cout << "������: " << getBalance() << std::endl;
	}

	static int getAccountCount() { return accountCount; } // ����������� �����


};