#pragma once
#include <iostream>
#include <sstream>

class Contribution {
private:
    int percent;                // Годовые проценты
    int minimum_deposit;        // Минимальный взнос на вклад
    Contribution* next;         // Указатель на следующий вклад

public:
    // Конструктор по умолчанию
    Contribution() : percent(0), minimum_deposit(0), next(nullptr) {}

    // Конструктор с параметрами
    Contribution(int p, int min_dep) : percent(p), minimum_deposit(min_dep), next(nullptr) {}

    // Деструктор
    ~Contribution() {
        delete next; // Освобождаем память при удалении объектов из списка
    }

    // Геттер для годовых процентов
    int getPercent() const {
        return percent;
    }

    // Сеттер для годовых процентов
    void setPercent(int p) {
        percent = p;
    }

    // Геттер для минимального взноса
    int getMinimumDeposit() const {
        return minimum_deposit;
    }

    // Сеттер для минимального взноса
    void setMinimumDeposit(int min_dep) {
        minimum_deposit = min_dep;
    }

    // Метод для проверки, соответствует ли заданная сумма взноса минимальному требованию
    bool isValidDeposit(int deposit) const {
        return deposit >= minimum_deposit;
    }

    // Метод для добавления нового вклада в список вкладов
    void addContribution(Contribution* newContribution) {
        if (next == nullptr) {
            next = newContribution; // Добавляем, если текущий узел не занят
        }
        else {
            next->addContribution(newContribution); // Рекурсия для поиска следующего пустого узла
        }
    }

    // Перегрузка оператора сложения для суммирования процентов двух вкладов
    Contribution operator+(const Contribution& other) const {
        return Contribution(this->percent + other.percent, this->minimum_deposit);
    }

    // Перегрузка оператора вывода для отображения информации о вкладе
    friend std::ostream& operator<<(std::ostream& os, const Contribution& contribution) {
        os << "Contribution [Percent: " << contribution.percent << ", Minimum Deposit: " << contribution.minimum_deposit << "]";
        return os;
    }

    // Перегрузка оператора присваивания
    Contribution& operator=(const Contribution& other) {
        if (this != &other) { // Проверка на самоприсваивание
            this->percent = other.percent;
            this->minimum_deposit = other.minimum_deposit;
            // При копировании нужно обработать указатель next, если это нужно
            delete this->next; // Удаляем старый элемент
            this->next = (other.next != nullptr) ? new Contribution(*(other.next)) : nullptr; // Копируем указатель
        }
        return *this;
    }
};
