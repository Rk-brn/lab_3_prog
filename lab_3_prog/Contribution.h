#pragma once
class Contribution {
private:
	int percent;     // Годовые проценты
	int minimum_deposit; // Минимальный взнос на вклад
	Contribution* next;
public:
	// Конструктор по умолчанию
	Contribution();

	// Конструктор с параметрами
	Contribution(int p, int min_dep);

	// Деструктор
	~Contribution();

	// Геттер для годовых процентов
	int getPercent() const;

	// Сеттер для годовых процентов
	void setPercent(int p);

	// Геттер для минимального взноса
	int getMinimumDeposit() const;

	// Сеттер для минимального взноса
	void setMinimumDeposit(int min_dep);

	// Метод для проверки, соответствует ли заданная сумма взноса минимальному требованию
	bool isValidDeposit(int deposit) const;
	// Метод для добавления нового вклада в список вкладов
	void addContribution(Contribution* newContribution);

	// Метод для удаления вклада из списка
	void removeContribution(Contribution* contributionToRemove);
	// Метод для подсчета заработанных процентов (в копейках)
	int calculateProfit(int deposit, int years) const;
};