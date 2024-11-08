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

};