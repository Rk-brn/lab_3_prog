#pragma once
#include "Goal.h"
#include <iostream>

class LongTermGoal : public Goal {
private:
    int interestRate;

public:
    LongTermGoal(const std::string& goalName, int amount, const Conversion& conv, int rate)
        : Goal(goalName, amount, conv), interestRate(rate) {}

    LongTermGoal& operator=(const Goal& other) {
        if (this == &other) return *this; // ����������������
        copyFrom(other);
        return *this;
    }

    void copyFrom(const Goal& other) override {
        Goal::copyFrom(other); // ����� �������� ������ ��� ����������� ����� ������

        if (const LongTermGoal* ltg = dynamic_cast<const LongTermGoal*>(&other)) {
            interestRate = ltg->interestRate; // ����������� interestRate, ���� ��� LongTermGoal
        }
        else {
            interestRate = 0; // �������� �� ���������, ���� ��� ������� Goal
        }
    }

    int getInRate() const {
        return interestRate;
    }

    // ���������� ������ convertTargetAmount (��� ������ ������ �������� ������)
    void convertTargetAmount(const Conversion& conv) const override {
        if (!conv.getCurrency()) {
            throw std::runtime_error("�������� ������ ��� �����������.");
        }
        int  rubles = targetAmount;
        int convertedAmount = rubles / conv.getCurrencyRate();
        // ��������� ������ ��������� � ������� �����.
        convertedAmount *= pow(1 + interestRate / 100.0, 1.0); 
        std::cout << "������� ����� � " << conv.getCurrency() << " � ������ ���������: " << convertedAmount << std::endl;
    }

    //LongTermGoal(const LongTermGoal& other) = delete;  //������ ������������ �����������
    //LongTermGoal& operator=(const LongTermGoal& other) = delete; //������ ��������� ������������

};