#pragma once
#include <iostream>
#include <sstream>

class Contribution {
private:
    int percent;                // ������� ��������
    int minimum_deposit;        // ����������� ����� �� �����
    Contribution* next;         // ��������� �� ��������� �����

public:
    // ����������� �� ���������
    Contribution() : percent(0), minimum_deposit(0), next(nullptr) {}

    // ����������� � �����������
    Contribution(int p, int min_dep) : percent(p), minimum_deposit(min_dep), next(nullptr) {}

    // ����������
    ~Contribution() {
        delete next; // ����������� ������ ��� �������� �������� �� ������
    }

    // ������ ��� ������� ���������
    int getPercent() const {
        return percent;
    }

    // ������ ��� ������� ���������
    void setPercent(int p) {
        percent = p;
    }

    // ������ ��� ������������ ������
    int getMinimumDeposit() const {
        return minimum_deposit;
    }

    // ������ ��� ������������ ������
    void setMinimumDeposit(int min_dep) {
        minimum_deposit = min_dep;
    }

    // ����� ��� ��������, ������������� �� �������� ����� ������ ������������ ����������
    bool isValidDeposit(int deposit) const {
        return deposit >= minimum_deposit;
    }

    // ����� ��� ���������� ������ ������ � ������ �������
    void addContribution(Contribution* newContribution) {
        if (next == nullptr) {
            next = newContribution; // ���������, ���� ������� ���� �� �����
        }
        else {
            next->addContribution(newContribution); // �������� ��� ������ ���������� ������� ����
        }
    }

    // ���������� ��������� �������� ��� ������������ ��������� ���� �������
    Contribution operator+(const Contribution& other) const {
        return Contribution(this->percent + other.percent, this->minimum_deposit);
    }

    // ���������� ��������� ������ ��� ����������� ���������� � ������
    friend std::ostream& operator<<(std::ostream& os, const Contribution& contribution) {
        os << "Contribution [Percent: " << contribution.percent << ", Minimum Deposit: " << contribution.minimum_deposit << "]";
        return os;
    }

    // ���������� ��������� ������������
    Contribution& operator=(const Contribution& other) {
        if (this != &other) { // �������� �� ����������������
            this->percent = other.percent;
            this->minimum_deposit = other.minimum_deposit;
            // ��� ����������� ����� ���������� ��������� next, ���� ��� �����
            delete this->next; // ������� ������ �������
            this->next = (other.next != nullptr) ? new Contribution(*(other.next)) : nullptr; // �������� ���������
        }
        return *this;
    }
};
