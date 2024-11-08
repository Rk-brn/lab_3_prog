#pragma once
class Loan {
private:
    int amount;     // Сумма кредита
    int interestRate;  // Процентная ставка
    Loan* next;
public:
    // Конструктор по умолчанию
    Loan() : amount(0), interestRate(0), next(nullptr) {}
    // Конструктор
    Loan(int amt, int rate) : amount(amt), interestRate(rate), next(nullptr) {}

    // Деструктор
    ~Loan() {}
    // Геттер для суммы кредита
    int getAmount() const {
        return amount;
    }
    // Сеттер для суммы кредита
    void setAmount(int amt) {
        amount = amt;
    }
    // Геттер для процентной ставки
    int getInterestRate() const {
        return interestRate;
    }
    // Сеттер для процентной ставки
    void setInterestRate(int rate) {
        interestRate = rate;
    }
    // Метод для расчета времени погашения кредита
    double calculateRepaymentTime(int monthlyPayment) const;

    // Метод для расчета переплаты по кредиту
    int calculateOverpayment(int monthlyPayment, double repaymentTime) const;

    // Метод для добавления нового кредита в список
    void addLoan(Loan* newLoan);
    // Метод для удаления транзакции из списка
    void removeTransaction(Loan* loanToRemove);
};