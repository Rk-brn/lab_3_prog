#pragma once
#include "Conversion.h"

class Goal {
private:
	char name[100];       // �������� ����
	int target_amount;     // ������� �����
	Conversion* conversion;   // ��������� �� ������ ����������� ������
	Goal* next;
public:
	// �����������
	Goal(const char* goalName, int amount, const char* currency, int rate);

	// ���������� ��� ������������ ������
	~Goal();

	// ������ ��� �������� ����
	const char* getName() const;

	// ������ ��� �������� ����
	void setName(const char* goalName);

	// ������ ��� ������� �����
	int getTargetAmount() const;

	// ������ ��� ������� �����
	void setTargetAmount(int amount);

	// ������ ��� �����������
	Conversion* getConversion() const;
	// ����� ��� ���������� ���� � ������
	void addGoal(Goal* newGoal);

	// ����� ��� �������� ���� �� ������
	void removeGoal(Goal* goalToRemove);

	// ����� ��� ����������� ������� ����� � ������ ������
	void convertTargetAmount(Conversion* conversion) const;

};