#pragma once
#include <cstring>

class Conversion {
private:
    char currency[50];         // Название валюты
    int currency_rate;         // Курс валюты к рублю
    Conversion* next;
public:
    // Конструктор
    Conversion(const char* curr, int rate);

    // Геттер для названия валюты
    const char* getCurrency() const;

    // Сеттер для названия валюты
    void setCurrency(const char* curr);

    // Геттер для курса валюты
    int getCurrencyRate() const;

    // Сеттер для курса валюты
    void setCurrencyRate(int rate);
    // Метод для добавления валюты в список конвертации
    void addConversion(Conversion* newConversion);

    // Метод для конвертации копеек в другую валюту
    int convert(int kopecks) const;
    // Метод для удаления валюты из списка конвертации
    void removeConversion(Conversion* conversionToRemove);

    Conversion& operator=(const Conversion& other) {
        if (this != &other) {
            strncpy_s(currency, other.currency, sizeof(currency));
            currency_rate = other.currency_rate;
            next = nullptr; // этот указатель не используется
        }
        return *this;
    }
};