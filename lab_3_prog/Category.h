#pragma once

#include <iostream>
#include <string>

class Category {
private:
	std::string name;
	Category* next;
public:
    // �����������
    Category(const std::string& categoryName) : name(categoryName), next(nullptr) {}

    // ����������
    ~Category() {}

    // ������
    void setName(const std::string& categoryName) {
        name = categoryName;
    }

    // ������ ����� ���������
    const std::string* getNamePointer() const {
        return &name; // ���������� ��������� �� ���
    }

    // ������ ����� ������
    const std::string& getNameReference() const {
        return name; // ���������� ������ �� ������ ������
    }
    
    Category(const Category& other) : name(other.name) {} // ����������� �����������

    // ����� ��� ���������� ��������� � ������
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

    // ����� ��� ��������� ����� ���������
    void changeCategoryName(const std::string& newName) {
        setName(newName);
    }

    // ����� ��� �������� ��������� ���������
    void removeNextCategory() {
        if (next != nullptr) {
            Category* temp = next; // �������� ��������� �� ��������� ���������
            next = next->next;     // �������������� ���������
            temp->next = nullptr;  // ��������� ��������� ���������
            delete temp;           // ����������� ������
        }
        else {
            std::cout << "��� ��������� ��� ��������." << std::endl;
        }
    }

    // ����� ��� ������ ����� ���������
    void print() const {
        std::cout << "Category Name: " << name << std::endl;
    }

    // ����� ��� ������ ���� ���������
    void printAll() const {
        const Category* current = this;
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
    }


	bool operator==(const Category& other) const { return name == other.name; } // �������� ���������

};
