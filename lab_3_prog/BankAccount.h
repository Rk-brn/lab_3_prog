
#include <string>

class BankAccount {
public:
    virtual void deposit(int amount) = 0; // Чисто виртуальная функция
    virtual void withdraw(int amount) = 0; // Чисто виртуальная функция
    virtual void printBalance() = 0;       // Чисто виртуальная функция
    virtual ~BankAccount() = default;     //Виртуальный деструктор для корректного удаления объектов через указатель на абстрактный класс

    virtual std::string getAccountType() const = 0;

};