#pragma once
class Contribution {
private:
	int percent;     // ������� ��������
	int minimum_deposit; // ����������� ����� �� �����
	Contribution* next;
public:
	// ����������� �� ���������
	Contribution();

	// ����������� � �����������
	Contribution(int p, int min_dep);

	// ����������
	~Contribution();

	// ������ ��� ������� ���������
	int getPercent() const;

	// ������ ��� ������� ���������
	void setPercent(int p);

	// ������ ��� ������������ ������
	int getMinimumDeposit() const;

	// ������ ��� ������������ ������
	void setMinimumDeposit(int min_dep);

	// ����� ��� ��������, ������������� �� �������� ����� ������ ������������ ����������
	bool isValidDeposit(int deposit) const;
	// ����� ��� ���������� ������ ������ � ������ �������
	void addContribution(Contribution* newContribution);

	// ����� ��� �������� ������ �� ������
	void removeContribution(Contribution* contributionToRemove);
	// ����� ��� �������� ������������ ��������� (� ��������)
	int calculateProfit(int deposit, int years) const;
};