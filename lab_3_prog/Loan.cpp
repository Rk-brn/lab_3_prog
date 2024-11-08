// Loan.cpp
#include "Loan.h"
#include <cmath>

double Loan::calculateRepaymentTime(int monthlyPayment) const {
    // ���������� ������ � ���������� �������
    double rate = interestRate / 100.0;
    // ������������ �������� �������
    double monthlyInterest = rate / 12;
    // ������������ ���������� ������� ���������
    int months = (int)ceil((monthlyInterest * amount) / (monthlyPayment - monthlyInterest * amount));
    // ����������� ������ � ����
    return months / 12.0;
}

int Loan::calculateOverpayment(int monthlyPayment, double repaymentTime) const {
    // ������������ ����� ���������� ������� ���������
    int totalMonths = (int)(repaymentTime * 12);
    // ������������ ����� ����� ������
    int totalPayment = totalMonths * monthlyPayment;
    // ��������� ���������
    return totalPayment - amount;
}

void Loan::addLoan(Loan* newLoan) {
    newLoan->next = this;
    this->next = newLoan;
}

void Loan::removeTransaction(Loan* loanToRemove) {
    // ���� ���������� - ������ � ������
    if (this == loanToRemove) {
        next = loanToRemove->next;
        delete loanToRemove;
        return;
    }

    // ���� ���������� � ������
    Loan* current = this;
    while (current->next != nullptr) {
        if (current->next == loanToRemove) {
            current->next = loanToRemove->next;
            delete loanToRemove;
            return;
        }
        current = current->next;
    }
}