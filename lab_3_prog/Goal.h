#pragma once
#include "Conversion.h"

class Goal {
private:
	char name[100];       // Название цели
	int target_amount;     // Целевая сумма
	Conversion* conversion;   // Указатель на объект конвертации валюты
	Goal* next;
public:
	// Конструктор
	Goal(const char* goalName, int amount, const char* currency, int rate);

	// Деструктор для освобождения памяти
	~Goal();

	// Геттер для названия цели
	const char* getName() const;

	// Сеттер для названия цели
	void setName(const char* goalName);

	// Геттер для целевой суммы
	int getTargetAmount() const;

	// Сеттер для целевой суммы
	void setTargetAmount(int amount);

	// Геттер для конвертации
	Conversion* getConversion() const;
	// Метод для добавления цели в список
	void addGoal(Goal* newGoal);

	// Метод для удаления цели из списка
	void removeGoal(Goal* goalToRemove);

	// Метод для конвертации целевой суммы в разные валюты
	void convertTargetAmount(Conversion* conversion) const;

};