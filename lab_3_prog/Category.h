#pragma once

#include <iostream>
#include <string>

class Category {
private:
	std::string name;
	Category* next;
public:
    // Конструктор
    Category(const std::string& categoryName) : name(categoryName), next(nullptr) {}

    // Деструктор
    ~Category() {}

    // Сеттер
    void setName(const std::string& categoryName) {
        name = categoryName;
    }

    // Геттер через указатель
    const std::string* getNamePointer() const {
        return &name; // Возвращаем указатель на имя
    }

    // Геттер через ссылку
    const std::string& getNameReference() const {
        return name; // Возвращаем ссылку на полную строку
    }
    
    Category(const Category& other) : name(other.name) {} // Конструктор копирования

    // Метод для добавления категории в список
    void addCategory(Category* newCategory) {
        if (next == nullptr) {
            next = newCategory;
        }
        else {
            Category* current = next;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newCategory;
        }
    }

    // Метод для изменения имени категории
    void changeCategoryName(const std::string& newName) {
        setName(newName);
    }

    // Метод для удаления следующей категории
    void removeNextCategory() {
        if (next != nullptr) {
            Category* temp = next; // Сохраним указатель на следующую категорию
            next = next->next;     // Переподключаем указатель
            temp->next = nullptr;  // Изолируем удаляемую категорию
            delete temp;           // Освобождаем память
        }
        else {
            std::cout << "Нет категории для удаления." << std::endl;
        }
    }

    // Метод для вывода имени категории
    void print() const {
        std::cout << "Category Name: " << name << std::endl;
    }

    // Метод для печати всех категорий
    void printAll() const {
        const Category* current = this;
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
    }


	bool operator==(const Category& other) const { return name == other.name; } // Оператор равенства

};
