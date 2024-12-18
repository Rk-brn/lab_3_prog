// lab_3_prog.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Loan.h"
#include "Conversion.h"
#include "Goal.h"
#include "Category.h"
#include "Transaction.h"
#include "Contribution.h"
#include "Account.h"
#include "User.h"
#include "Analytics.h"
#include "PremiumAccount.h"

#include "LongGoal.h"
#include "BankAccount.h"

#include <iomanip> // для std::setw
#include <memory> // для std::unique_ptr и std::shared_ptr
#include <iostream>
#include <cstring>
#include <locale.h>
#include <string>

using namespace std;





// Дружественная функция для форматированного вывода
void printTransaction(const Transaction& t) {
    std::cout << std::setw(20) << t.description << " | "
        << std::setw(10) << t.amount << " | "
        << std::setw(10) << t.date << " | "
        << std::setw(10) << t.type << " | ";
    if (t.category) {
        std::cout << t.category->getNameReference();
    }
    else {
        std::cout << "N/A";
    }
    std::cout << std::endl;
}


int Account::accountCount = 0; // Инициализация статического поля




class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int initialBalance = 0) : balance(initialBalance) {}
    ~SavingsAccount() override = default;
    void deposit(int amount) override { balance += amount; }
    void withdraw(int amount) override {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            std::cout << "Недостаточно средств!\n";
        }
    }
    void printBalance() override { std::cout << "Баланс накопительного счёта: " << balance << "\n"; }
    std::string getAccountType() const override { return "Накопительный счёт"; }

private:
    int balance;
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int initialBalance = 0) : balance(initialBalance) {}
    ~CheckingAccount() override = default;
    void deposit(int amount) override { balance += amount; }
    void withdraw(int amount) override { balance -= amount; }
    void printBalance() override { std::cout << "Баланс текущего счёта: " << balance << "\n"; }
    std::string getAccountType() const override { return "Текущий счёт"; }

private:
    int balance;
};



class AccountManager : public BankAccount {
public:
    AccountManager() : currentAccount(new SavingsAccount()) {}
    ~AccountManager() override { delete currentAccount; }

    void deposit(int amount) override { currentAccount->deposit(amount); }
    void withdraw(int amount) override { currentAccount->withdraw(amount); }
    void printBalance() override { currentAccount->printBalance(); }
    std::string getAccountType() const override { return currentAccount->getAccountType(); }

    void switchToSavings() {
        delete currentAccount;
        currentAccount = new SavingsAccount();
    }

    void switchToCheckings() {
        delete currentAccount;
        currentAccount = new CheckingAccount();
    }

private:
    BankAccount* currentAccount;
};







int main()
{
    setlocale(LC_ALL, "Rus");

    AccountManager manager;

    std::cout << "Начальный тип счёта: " << manager.getAccountType() << std::endl;
    manager.deposit(1000);
    manager.printBalance();
    manager.withdraw(500);
    manager.printBalance();

    manager.switchToCheckings();
    std::cout << "Счёт после изменения вида: " << manager.getAccountType() << std::endl;
    manager.deposit(200);
    manager.printBalance();
    manager.withdraw(300); 
    manager.printBalance();
    
    //Category cat1("Продукты");

    //Account acc1("Личный счет");

    //
    //acc1.printBalance();

    //SavingsAccount savings("Сберегательный", 5); // 5% годовых
    //savings.addTransaction("Пополнение", 100000, "28-10-2024", "income", &cat1);
    //
    ////// Демонстрация PremiumAccount
    //PremiumAccount premiumAccount("Премиум", 1000);
    //premiumAccount.addTransaction("Покупка", 50000, "10-10-2024", "expense", &cat1, 50);
    //cout << "\nБаланс бонусных баллов на премиум аккаунте: " << premiumAccount.getBonusPoints() << endl;

    //savings.printBalance();
    //premiumAccount.printBalance();

    //// Вызов через указатели
    //Account* accountPtr;

    //accountPtr = &acc1;
    //accountPtr->printBalance(); // Выведет 0.0

    //accountPtr = &savings;
    //accountPtr->printBalance(); 

    //accountPtr = &premiumAccount;
    //accountPtr->printBalance(); 


    ////Conversion convUSD("USD", 75);
    ////
    ////LongTermGoal longTermGoal("Дом", 2000000, convUSD, 7); // 7% годовых (демонстрация вызова конструктора базоваго класса)
    ////longTermGoal.convertTargetAmount(convUSD);
    //


    //Conversion conv1("USD", 75);
    ////Goal* goal1 = new Goal("Отпуск", 150000, convUSD);

    //// Поверхностное клонирование
    ////Goal* goal2 = goal1->shallowCopy();
    ////std::cout << "\nПоверхностное клонирование:\n";
    ////std::cout << "goal1: " << goal1->getName() << ", targetAmount: " << goal1->getTargetAmount() << std::endl;
    ////std::cout << "goal2: " << goal2->getName() << ", targetAmount: " << goal2->getTargetAmount() << std::endl;

    ////// Глубокое клонирование
    ////Goal* goal3 = goal1->deepCopy();
    ////std::cout << "\nГлубокое клонирование:\n";
    ////std::cout << "goal1: " << goal1->getName() << ", targetAmount: " << goal1->getTargetAmount() << ", валюта: " << goal1->getConversionCurrency() << ", курс: " << goal1->getConversionRate() << std::endl;
    ////std::cout << "goal3: " << goal3->getName() << ", targetAmount: " << goal3->getTargetAmount() << ", валюта: " << goal3->getConversionCurrency() << ", курс: " << goal3->getConversionRate()<< std::endl;



    //Conversion conv2("EUR", 85);

    //Goal* goal1 = new Goal("Купить машину", 1500000, conv1);
    //LongTermGoal* goal2 = new LongTermGoal("Собрать на квартиру", 5000000, conv2, 5); // 5% годовых

    //// Присваивание объекта Goal объекту LongTermGoal
    //LongTermGoal goal3("Путешествие", 200000, conv1, 0); //Создаем объект LongTermGoal для присваивания
    //goal3 = *goal1; // Присваиваем goal1 goal3, используя перегруженный оператор =


    //std::cout << "Цель 1: " << goal1->getName() << ", сумма: " << goal1->getTargetAmount() << " руб., валюта: " << goal1->getConversionCurrency() << std::endl;
    //std::cout << "Цель 2: " << goal2->getName() << ", сумма: " << goal2->getTargetAmount() << " руб., валюта: " << goal2->getConversionCurrency() << std::endl;
    //std::cout << "Цель 3 (после присваивания): " << goal3.getName() << ", сумма: " << goal3.getTargetAmount() << " руб., валюта: " << goal3.getConversionCurrency() << ", процент: " << goal3.getInRate() << std::endl;


    //goal1->convertTargetAmount(conv1);
    //goal2->convertTargetAmount(conv2);
    //goal3.convertTargetAmount(conv1);

    


     //Демонстрация важности виртуального деструктора
    


    //Category cat1("Продукты");
    //
    //
    //Category cat2("Продукты");
    //Category cat3("Развлечения");


    //Category cat4 = cat1; // Используем конструктор копирования Category
    //std::cout << "Категория 1: " << cat1.getNameReference() << std::endl;
    //std::cout << "Категория 4: " << cat4.getNameReference() << std::endl;

    //Transaction transaction1("Покупка продуктов", 1000, "2024-10-27", "расход", &cat1);
    //Transaction transaction2("Покупка хлеба", 1000, "2024-10-27", "расход", &cat2);
    //Transaction transaction3("Покупка продуктов", 1000, "2024-10-27", "расход", &cat3);


   
   

    //// Печатаем имя категории через указатель
    //std::cout << "Имя категории через указатель: " << *cat1.getNamePointer() << std::endl;

    //// Печатаем имя категории через ссылку
    //std::cout << "Имя категории через ссылку: " << cat1.getNameReference() << std::endl;


    //std::cout << "\nОтформатированные транзакции:\n";
    //printTransaction(transaction1);
    //printTransaction(transaction2);
    //printTransaction(transaction3);


    //Contribution contrib1(5, 1000);
    //Contribution contrib2(3, 1500);

    //// Пример использования перегрузки оператора сложения
    //Contribution contrib3 = contrib1 + contrib2;
    //std::cout << "\n\nСложенный вклад: " << contrib3 << std::endl;

    //// Пример использования перегрузки оператора вывода
    //std::cout << "Вклад 1: " << contrib1 << std::endl;
    //std::cout << "Вклад 2: " << contrib2 << std::endl;

    //// Пример использования перегрузки оператора присваивания
    //Contribution contrib4;
    //contrib4 = contrib1;
    //std::cout << "Присваивание вкладу №4 значения вклада №1: " << contrib4 << std::endl;


    //Conversion convUSD("USD", 75);
    //Goal goal1("Отпуск в Испании", 150000, convUSD);

   
    //std::cout << "Подстрока названия: " << goal1.extractSubName(0, 10) << std::endl;
    //std::cout << "Содержит ли \"Испании\": " << (goal1.containsKeyword("Испании") ? "Да" : "Нет") << std::endl;
    //goal1.toUpperName();
    //std::cout << "Название в верхнем регистре: " << goal1.getName() << std::endl;

    //
    //Goal goal2("Отпуск", 15000, convUSD);

    //std::cout << "Цель 1: " << goal2.getName() << ", сумма: " << goal2.getTargetAmount()
    //    << ", валюта: " << goal2.getConversionCurrency() << ", курс: " << goal2.getConversionRate() << std::endl;

    //Goal goal3 = goal2; // Используем конструктор копирования

    //std::cout << "Цель 2: " << goal3.getName() << ", сумма: " << goal3.getTargetAmount()
    //    << ", валюта: " << goal3.getConversionCurrency() << ", курс: " << goal3.getConversionRate() << std::endl;

    //
   
    //Account* acc1 = new Account("Счет 1");
    //Account* acc2 = new Account("Счет 2");
    //std::cout << "Количество счетов: " << Account::getAccountCount() << std::endl;

    //
    //
    //std::cout << "Количество счетов после удаления: " << Account::getAccountCount() << std::endl;
    //return 0;
    //
  
    //

    //// Демонстрация работы с динамическим массивом объектов класса Loan
    //cout << "Демонстрация работы с динамическим массивом объектов класса Loan:" << endl;
    //int numLoans;
    //cout << "Введите количество кредитов: ";
    //cin >> numLoans;

    //// Выделение памяти под массив объектов Loan
    //Loan* loans = new Loan[numLoans];

    //// Ввод данных о кредитах
    //for (int i = 0; i < numLoans; ++i) {
    //    int amount, rate;
    //    cout << "Введите сумму кредита " << i + 1 << ": ";
    //    cin >> amount;
    //    cout << "Введите процентную ставку " << i + 1 << ": ";
    //    cin >> rate;
    //    loans[i].setAmount(amount);
    //    loans[i].setInterestRate(rate);
    //}

    //// Вывод информации о кредитах
    //for (int i = 0; i < numLoans; ++i) {
    //    cout << "Кредит " << i + 1 << ": " << endl;
    //    cout << "Сумма: " << loans[i].getAmount() << " копеек" << endl;
    //    cout << "Процентная ставка: " << loans[i].getInterestRate() << "%" << endl;
    //}

    //// Освобождение памяти, выделенной под массив объектов Loan
    //delete[] loans;

    //// Демонстрация работы с массивом динамических объектов класса Account
    //cout << endl << "Демонстрация работы с массивом динамических объектов класса Account:" << endl;
    //int numAccounts;
    //cout << "Введите количество счетов: ";
    //cin >> numAccounts;

    //// Создание массива указателей на Account
    //Account** accounts = new Account * [numAccounts];

    //// Создание объектов Account
    //for (int i = 0; i < numAccounts; ++i) {
    //    char accountName[50];
    //    cout << "Введите название счета " << i + 1 << ": ";
    //    cin >> accountName;
    //    accounts[i] = new Account(accountName);
    //}

    //// Ввод данных о транзакциях
    //for (int i = 0; i < numAccounts; ++i) {
    //    cout << "Счет " << i + 1 << ": " << endl;
    //    cout << "Введите количество транзакций: ";
    //    int numTransactions;
    //    cin >> numTransactions;
    //    for (int j = 0; j < numTransactions; ++j) {
    //        char description[100];
    //        int amount;
    //        char date[11];
    //        char type[10];
    //        cout << "Введите описание транзакции: ";
    //        cin >> description;
    //        cout << "Введите сумму: ";
    //        cin >> amount;
    //        cout << "Введите дату (DD-MM-YYYY): ";
    //        cin >> date;
    //        cout << "Введите тип (доход/расход): ";
    //        cin >> type;
    //        // Создание категории для транзакции
    //        Category* category = new Category("Продукты");
    //        accounts[i]->addTransaction(description, amount, date, type, category);
    //    }
    //}

    //// Вывод информации о транзакциях на счетах
    //for (int i = 0; i < numAccounts; ++i) {
    //    cout << "Счет: " << accounts[i]->getName() << endl;
    //    cout << "Количество транзакций: " << accounts[i]->getTransactionCount() << endl;
    //    Transaction* currentTransaction = accounts[i]->getTransactions();
    //    while (currentTransaction != nullptr) {
    //        cout << "Описание: " << currentTransaction->getDescription() << endl;
    //        cout << "Сумма: " << currentTransaction->getAmount() << endl;
    //        cout << "Дата: " << currentTransaction->getDate() << endl;
    //        cout << "Тип: " << currentTransaction->getType() << endl;
    //        // Вывод названия категории, если она задана
    //        if (currentTransaction->getCategory() != nullptr) {
    //            cout << "Категория: " << currentTransaction->getCategory()->getNamePointer() << endl;
    //        }
    //        currentTransaction = currentTransaction->getNext();
    //    }
    //}

    //// Освобождение памяти, выделенной под объекты Account
    //for (int i = 0; i < numAccounts; ++i) {
    //    delete accounts[i];
    //}
    //delete[] accounts;

    //// Работа со ссылками
    //cout << endl << "Демонстрация работы с оператором работы со ссылками:" << endl;
    //User user1(1, "JohnDoe", "password123", 10000);
    //User user2(2, "JaneDoe", "password456", 20000);
    //User* pUser = &user1;

    //// Изменение баланса пользователя через ссылку
    //cout << "Баланс user1 перед изменением: " << pUser->getBalance() << endl;
    //int newBalance = 15000;
    //pUser->setBalance(newBalance);
    //cout << "Баланс user1 после изменения: " << pUser->getBalance() << endl;

    //// Демонстрация работы с объектами классов через ссылки
    //cout << "Демонстрация работы с объектами классов через ссылки:" << endl;
    //Category* category = new Category("Продукты");
    //Account* account = new Account("Основной");
    //account->addTransaction("Зарплата", 50000, "01-01-2024", "доход", category);
    //account->addTransaction("Покупка продуктов", 10000, "02-01-2024", "расход", category);

    //// Вывод информации о транзакциях на счете через ссылку
    //cout << "Информация о транзакциях на счете " << account->getName() << ":" << endl;
    //Transaction* currentTransaction = account->getTransactions();
    //while (currentTransaction != nullptr) {
    //    cout << "Описание: " << currentTransaction->getDescription() << endl;
    //    cout << "Сумма: " << currentTransaction->getAmount() << endl;
    //    cout << "Дата: " << currentTransaction->getDate() << endl;
    //    cout << "Тип: " << currentTransaction->getType() << endl;
    //    // Вывод названия категории, если она задана
    //    if (currentTransaction->getCategory() != nullptr) {
    //        cout << "Категория: " << currentTransaction->getCategory()->getNamePointer() << endl;
    //    }
    //    currentTransaction = currentTransaction->getNext();
    //}
    ////Освобождение памяти, выделенной под объекты Account и Category
    //delete account;
    //delete category;
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
