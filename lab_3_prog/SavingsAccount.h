#include "Account.h"

class SavingsAccount : public Account {
protected:
    int interestRate;

public:
    SavingsAccount(const char* accountName, int rate) : Account(accountName), interestRate(rate) {}
    ~SavingsAccount() = default;

    //���������� ������ addTransaction �� �������� ������ (��� ������ ������ �������� ������).
    void addTransaction(const char* desc, int amt, const char* dt, const char* typ, Category* cat) {
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
        std::cout << "���������� ��������� �� �������������� ���� 2(��� ������ �������� ������).\n";
    }

    int getBalance() override {
        // ��������� �������� � �������� �������
        int interest = (balance * interestRate) / 100;  //  �������� ��������� ��� (������ * ���������� ������) / 100
        return balance + interest;
    }

    

};