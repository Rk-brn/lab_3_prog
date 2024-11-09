// lab_3_prog.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <locale.h>
#include <string>
#include "Loan.h"
#include "Conversion.h"
#include "Goal.h"
#include "Category.h"
#include "Transaction.h"
#include "Contribution.h"
#include "Account.h"
#include "User.h"
#include "Analytics.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    // Демонстрация работы с динамическим массивом объектов класса Loan
        cout << "Демонстрация работы с динамическим массивом объектов класса Loan:" << endl;
    int numLoans;
    cout << "Введите количество кредитов: ";
    cin >> numLoans;

    // Выделение памяти под массив объектов Loan
    Loan* loans = new Loan[numLoans];

    // Ввод данных о кредитах
    for (int i = 0; i < numLoans; ++i) {
        int amount, rate;
        cout << "Введите сумму кредита " << i + 1 << ": ";
        cin >> amount;
        cout << "Введите процентную ставку " << i + 1 << ": ";
        cin >> rate;
        loans[i].setAmount(amount);
        loans[i].setInterestRate(rate);
    }

    // Вывод информации о кредитах
    for (int i = 0; i < numLoans; ++i) {
        cout << "Кредит " << i + 1 << ": " << endl;
        cout << "Сумма: " << loans[i].getAmount() << " копеек" << endl;
        cout << "Процентная ставка: " << loans[i].getInterestRate() << "%" << endl;
    }

    // Освобождение памяти, выделенной под массив объектов Loan
    delete[] loans;

    // Демонстрация работы с массивом динамических объектов класса Account
    cout << endl << "Демонстрация работы с массивом динамических объектов класса Account:" << endl;
    int numAccounts;
    cout << "Введите количество счетов: ";
    cin >> numAccounts;

    // Создание массива указателей на Account
    Account** accounts = new Account * [numAccounts];

    // Создание объектов Account
    for (int i = 0; i < numAccounts; ++i) {
        char accountName[50];
        cout << "Введите название счета " << i + 1 << ": ";
        cin >> accountName;
        accounts[i] = new Account(accountName);
    }

    // Ввод данных о транзакциях
    for (int i = 0; i < numAccounts; ++i) {
        cout << "Счет " << i + 1 << ": " << endl;
        cout << "Введите количество транзакций: ";
        int numTransactions;
        cin >> numTransactions;
        for (int j = 0; j < numTransactions; ++j) {
            char description[100];
            int amount;
            char date[11];
            char type[10];
            cout << "Введите описание транзакции: ";
            cin >> description;
            cout << "Введите сумму: ";
            cin >> amount;
            cout << "Введите дату (DD-MM-YYYY): ";
            cin >> date;
            cout << "Введите тип (доход/расход): ";
            cin >> type;
            // Создание категории для транзакции
            Category* category = new Category("Продукты");
            accounts[i]->addTransaction(description, amount, date, type, category);
        }
    }

    // Вывод информации о транзакциях на счетах
    for (int i = 0; i < numAccounts; ++i) {
        cout << "Счет: " << accounts[i]->getName() << endl;
        cout << "Количество транзакций: " << accounts[i]->getTransactionCount() << endl;
        Transaction* currentTransaction = accounts[i]->getTransactions();
        while (currentTransaction != nullptr) {
            cout << "Описание: " << currentTransaction->getDescription() << endl;
            cout << "Сумма: " << currentTransaction->getAmount() << endl;
            cout << "Дата: " << currentTransaction->getDate() << endl;
            cout << "Тип: " << currentTransaction->getType() << endl;
            // Вывод названия категории, если она задана
            if (currentTransaction->getCategory() != nullptr) {
                cout << "Категория: " << currentTransaction->getCategory()->getName() << endl;
            }
            currentTransaction = currentTransaction->getNext();
        }
    }

    // Освобождение памяти, выделенной под объекты Account
    for (int i = 0; i < numAccounts; ++i) {
        delete accounts[i];
    }
    delete[] accounts;

    // Работа со ссылками
    cout << endl << "Демонстрация работы с оператором работы со ссылками:" << endl;
    User user1(1, "JohnDoe", "password123", 10000);
    User user2(2, "JaneDoe", "password456", 20000);
    User* pUser = &user1;

    // Изменение баланса пользователя через ссылку
    cout << "Баланс user1 перед изменением: " << pUser->getBalance() << endl;
    int newBalance = 15000;
    pUser->setBalance(newBalance);
    cout << "Баланс user1 после изменения: " << pUser->getBalance() << endl;

    // Демонстрация работы с объектами классов через ссылки
    cout << "Демонстрация работы с объектами классов через ссылки:" << endl;
    Category* category = new Category("Продукты");
    Account* account = new Account("Основной");
    account->addTransaction("Зарплата", 50000, "01-01-2024", "доход", category);
    account->addTransaction("Покупка продуктов", 10000, "02-01-2024", "расход", category);

    // Вывод информации о транзакциях на счете через ссылку
    cout << "Информация о транзакциях на счете " << account->getName() << ":" << endl;
    Transaction* currentTransaction = account->getTransactions();
    while (currentTransaction != nullptr) {
        cout << "Описание: " << currentTransaction->getDescription() << endl;
        cout << "Сумма: " << currentTransaction->getAmount() << endl;
        cout << "Дата: " << currentTransaction->getDate() << endl;
        cout << "Тип: " << currentTransaction->getType() << endl;
        // Вывод названия категории, если она задана
        if (currentTransaction->getCategory() != nullptr) {
            cout << "Категория: " << currentTransaction->getCategory()->getName() << endl;
        }
        currentTransaction = currentTransaction->getNext();
    }
    //Освобождение памяти, выделенной под объекты Account и Category
    delete account;
    delete category;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
