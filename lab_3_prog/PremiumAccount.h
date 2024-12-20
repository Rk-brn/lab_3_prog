#pragma once
#include "Account.h"

class PremiumAccount : public Account {
private:
    int bonusPoints;

public:
    // �����������
    PremiumAccount(const char* accountName, int initialBonusPoints) : Account(accountName), bonusPoints(initialBonusPoints) {}

    ~PremiumAccount() = default;

    // ������ ��� �������� ������
    int getBonusPoints() const { return bonusPoints; }

    // ������ ��� �������� ������
    void setBonusPoints(int points) { bonusPoints = points; }

    //���������� ������ �������� ������ (� ������� �������� ������)
    void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat, int pointsEarned) {
        Account::addTransaction(desc, amt, dt, typ, cat, pointsEarned);
        bonusPoints += pointsEarned;
        std::cout << "���������� ��������� �� ������� ����(� ������� �������� ������).\n";
    }

    /*void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat, int pointsEarned) override {
        if (strlen(desc) == 0) {
            throw std::runtime_error("�������� ���������� �� ����� ���� ������");
        }
        Transaction* newTransaction = new Transaction(desc, amt, dt, typ, cat);
        if (!transactions) {
            transactions = newTransaction;
        }
        else {
            Transaction* current = transactions;
            while (current->getNext()) {
                current = current->getNext();
            }
            current->setNext(newTransaction);
        }
        bonusPoints += pointsEarned;
        std::cout << "���������� ��������� �� ������� ����(� ������� �������� ������).\n";
    }*/
    int getBalance() override { return balance + (bonusPoints / 10); }
};