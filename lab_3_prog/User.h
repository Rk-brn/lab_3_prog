#pragma once

#include <string>
#include "Account.h"
#include "Goal.h"
#include "Contribution.h"
#include "Loan.h"

class User {
private:
    int id;                       // ���������� ID ������������
    std::string username;         // ��� ������������
    std::string password;         // ������ ������������
    int balance;                  // ������ ������������ (� ��������)
    Account* primaryAccount;      // �������� ���� ������������
    Goal* goal;                   // ����
    Contribution* contribution;    // �����
    Loan* loan;                   // ������
    User* next;
public:
    // �����������
    User(int userId, const std::string& userName, const std::string& userPassword, int userBalance);

    // ����������
    ~User();

    // �������
    void setUsername(const std::string& userName);

    void setPassword(const std::string& userPassword);

    void setBalance(int userBalance);

    void setPrimaryAccount(Account* account);

    void setGoal(Goal* userGoal);

    void setContribution(Contribution* userContribution);

    void setLoan(Loan* userLoan);

    // �������
    int getId() const;

    std::string getUsername() const;

    std::string getPassword() const;

    int getBalance() const;

    Account* getPrimaryAccount() const;

    Goal* getGoal() const;

    Contribution* getContribution() const;

    Loan* getLoan() const;
    // ����� ��� ���������� ������������ � ������
    void addUser(User* newUser);

    // ����� ��� �������� ������������ �� ������
    void removeUser(User* userToRemove);

    // ����� ��� ��������� ����� ������������ � ������
    void changeCredentials(const std::string& newUsername, const std::string& newPassword);

    // ����� ��� ����������� ������� � ������ ������
    void convertBalance(Conversion* conversion) const;

    // ����� ��� ���������� ������� ������������
    void updateBalance();

};