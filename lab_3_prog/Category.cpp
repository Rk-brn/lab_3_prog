// Category.cpp
#include "Category.h"
#include <cstring>

Category::Category(const char* categoryName) : next(nullptr) {
    strncpy_s(name, categoryName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Category::setName(const char* categoryName) {
    strncpy_s(name, categoryName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

const char* Category::getName() const {
    return name;
}

void Category::addCategory(Category* newCategory) {
    newCategory->next = this;
    this->next = newCategory;
}

void Category::removeCategory(Category* categoryToRemove) {
    // ���� ��������� - ������ � ������
    if (this == categoryToRemove) {
        next = categoryToRemove->next;
        delete categoryToRemove;
        return;
    }

    // ���� ��������� � ������
    Category* current = this;
    while (current->next != nullptr) {
        if (current->next == categoryToRemove) {
            current->next = categoryToRemove->next;
            delete categoryToRemove;
            return;
        }
        current = current->next;
    }
}