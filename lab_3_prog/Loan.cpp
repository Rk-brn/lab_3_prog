// Loan.cpp
#include "Loan.h"
#include <cmath>

double Loan::calculateRepaymentTime(int monthlyPayment) const {
    // Процентная ставка в десятичном формате
    double rate = interestRate / 100.0;
    // Рассчитываем месячный процент
    double monthlyInterest = rate / 12;
    // Рассчитываем количество месяцев погашения
    double months = (amount * monthlyInterest) / (monthlyPayment - amount * monthlyInterest); // Без округления
    // Преобразуем месяцы в годы 
    return months / 12.0; // Делим на 12, чтобы получить годы
}

int Loan::calculateOverpayment(int monthlyPayment, double repaymentTime) const {
    // Рассчитываем общее количество месяцев погашения
    int totalMonths = (int)(repaymentTime * 12);
    // Рассчитываем общую сумму выплат
    int totalPayment = totalMonths * monthlyPayment;
    // Вычисляем переплату
    return totalPayment - amount;
}

void Loan::addLoan(Loan* newLoan) {
    newLoan->next = this;
    this->next = newLoan;
}

void Loan::removeTransaction(Loan* loanToRemove) {
    // Если транзакция - первая в списке
    if (this == loanToRemove) {
        next = loanToRemove->next;
        delete loanToRemove;
        return;
    }

    // Ищем транзакцию в списке
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