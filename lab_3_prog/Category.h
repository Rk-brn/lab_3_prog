#pragma once
class Category {
private:
	char name[50];
	Category* next;
public:
	// �����������
	Category(const char* categoryName);

	// ����������
	~Category() {}

	// ������
	void setName(const char* categoryName);

	// ������
	const char* getName() const;
	// ����� ��� ���������� ��������� � ������
	void addCategory(Category* newCategory);

	// ����� ��� �������� ��������� �� ������
	void removeCategory(Category* categoryToRemove);

};
