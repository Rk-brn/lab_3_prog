#include "Account.h"

class SavingsAccount : public Account {
protected:
    int interestRate;

public:
    SavingsAccount(const char* accountName, int rate) : Account(accountName), interestRate(rate) {}
    ~SavingsAccount() = default;

    //Перегрузка метода addTransaction из базового класса (без вызова метода базового класса).
    void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat) {
        if (strlen(desc) == 0) {
            throw std::runtime_error("Описание транзакции не может быть пустым");
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
        std::cout << "Транзакция добавлена на сберегательный счет 2(без вызова базового класса).\n";
    }

    int getBalance() override {
        // Начисляем проценты к текущему балансу
        int interest = (balance * interestRate) / 100;  //  Проценты считаются как (баланс * процентная ставка) / 100
        return balance + interest;
    }

    

};