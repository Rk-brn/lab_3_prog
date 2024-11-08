#pragma once
class Category {
private:
	char name[50];
	Category* next;
public:
	// Конструктор
	Category(const char* categoryName);

	// Деструктор
	~Category() {}

	// Сеттер
	void setName(const char* categoryName);

	// Геттер
	const char* getName() const;
	// Метод для добавления категории в список
	void addCategory(Category* newCategory);

	// Метод для удаления категории из списка
	void removeCategory(Category* categoryToRemove);

};
