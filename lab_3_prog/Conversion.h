#pragma once
#include <cstring>

class Conversion {
private:
    char currency[50];         // �������� ������
    int currency_rate;         // ���� ������ � �����
    Conversion* next;
public:
    // �����������
    Conversion(const char* curr, int rate);

    // ������ ��� �������� ������
    const char* getCurrency() const;

    // ������ ��� �������� ������
    void setCurrency(const char* curr);

    // ������ ��� ����� ������
    int getCurrencyRate() const;

    // ������ ��� ����� ������
    void setCurrencyRate(int rate);
    // ����� ��� ���������� ������ � ������ �����������
    void addConversion(Conversion* newConversion);

    // ����� ��� ����������� ������ � ������ ������
    int convert(int kopecks) const;
    // ����� ��� �������� ������ �� ������ �����������
    void removeConversion(Conversion* conversionToRemove);

    Conversion& operator=(const Conversion& other) {
        if (this != &other) {
            strncpy_s(currency, other.currency, sizeof(currency));
            currency_rate = other.currency_rate;
            next = nullptr; // ���� ��������� �� ������������
        }
        return *this;
    }
};