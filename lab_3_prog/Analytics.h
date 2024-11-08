#pragma once
#include "User.h"
#include "Account.h"

class Analytics {
private:
	int totalIncome;   // ����� �����
	int totalExpense;  // ����� ������
	User* user;     // ��������� �� ������������
	Account* account;  // ��������� �� ����

public:
	// �����������
	Analytics(int income, int expense, User* userPtr, Account* accountPtr);

	// ����������
	~Analytics();

	// �������
	int getTotalIncome() const;

	int getTotalExpense() const;

	User* getUser() const;

	Account* getAccount() const;

	// �������
	void setTotalIncome(int income);

	void setTotalExpense(int expense);

	void setUser(User* userPtr);

	void setAccount(Account* accountPtr);

	// ����� ��� ��������� ����� (�������� ������ ������ � �������)
	void processAccount();

	// ����� ��� ��������� ������ � ������� � ������ ����������
	void analyzeAccount();
};
