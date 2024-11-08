// Conversion.cpp
#include "Conversion.h"

Conversion::Conversion(const char* curr, int rate)
    : currency_rate(rate), next(nullptr) {
    strncpy_s(currency, curr, sizeof(currency));
    currency[sizeof(currency) - 1] = '\0';
}

const char* Conversion::getCurrency() const {
    return currency;
}

void Conversion::setCurrency(const char* curr) {
    strncpy_s(currency, curr, sizeof(currency));
    currency[sizeof(currency) - 1] = '\0';
}

int Conversion::getCurrencyRate() const {
    return currency_rate;
}

void Conversion::setCurrencyRate(int rate) {
    currency_rate = rate;
}

void Conversion::addConversion(Conversion* newConversion) {
    newConversion->next = this;
    this->next = newConversion;
}

int Conversion::convert(int kopecks) const {
    // ��������� ������� � �����
    double rubles = kopecks / 100.0;
    // ��������� ����� � ������ ������
    double convertedAmount = rubles * currency_rate;
    // ��������� ������� � �������
    return (int)(convertedAmount * 100);
}

void Conversion::removeConversion(Conversion* conversionToRemove) {
    // ���� ��������� ������ - ������ � ������
    if (this == conversionToRemove) {
        next = conversionToRemove->next;
        delete conversionToRemove;
        return;
    }

    // ���� ������ � ������
    Conversion* current = this;
    while (current->next != nullptr) {
        if (current->next == conversionToRemove) {
            current->next = conversionToRemove->next;
            delete conversionToRemove;
            return;
        }
        current = current->next;
    }
}