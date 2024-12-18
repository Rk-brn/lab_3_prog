
#include <string>
class BankAccount {
public:
    virtual void deposit(int amount) = 0; 
    virtual void withdraw(int amount) = 0; 
    virtual void printBalance() = 0;       
    virtual ~BankAccount() = default;     
    virtual std::string getAccountType() const = 0;

};