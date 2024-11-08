#pragma once
class Loan {
private:
    int amount;     // ����� �������
    int interestRate;  // ���������� ������
    Loan* next;
public:
    // ����������� �� ���������
    Loan() : amount(0), interestRate(0), next(nullptr) {}
    // �����������
    Loan(int amt, int rate) : amount(amt), interestRate(rate), next(nullptr) {}

    // ����������
    ~Loan() {}
    // ������ ��� ����� �������
    int getAmount() const {
        return amount;
    }
    // ������ ��� ����� �������
    void setAmount(int amt) {
        amount = amt;
    }
    // ������ ��� ���������� ������
    int getInterestRate() const {
        return interestRate;
    }
    // ������ ��� ���������� ������
    void setInterestRate(int rate) {
        interestRate = rate;
    }
    // ����� ��� ������� ������� ��������� �������
    double calculateRepaymentTime(int monthlyPayment) const;

    // ����� ��� ������� ��������� �� �������
    int calculateOverpayment(int monthlyPayment, double repaymentTime) const;

    // ����� ��� ���������� ������ ������� � ������
    void addLoan(Loan* newLoan);
    // ����� ��� �������� ���������� �� ������
    void removeTransaction(Loan* loanToRemove);
};