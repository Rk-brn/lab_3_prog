#pragma once
#include <string>
#include "Conversion.h"
#include <stdexcept> // Для обработки исключений
#include <memory> //Для unique_ptr

class Goal {
protected:
    std::string name;
    int targetAmount;
    std::unique_ptr<Conversion> conversion; // Используем unique_ptr для автоматического управления памятью
    Goal* next;

    virtual void copyFrom(const Goal& other); 
public:
    Goal(const std::string& goalName, int amount, const Conversion& conv);
    Goal(const Goal& other);
    ~Goal() = default;
    const std::string& getName() const;
    void setName(const std::string& goalName);
    int getTargetAmount() const;
    void setTargetAmount(int amount);
    Goal* getNext() const { return next; }
    void setNext(Goal* newNext) { next = newNext; }
    
    //// Метод поверхностного клонирования
    //Goal* shallowCopy() const {
    //    return new Goal(*this); // Используем конструктор копирования
    //}

    //// Метод глубокого клонирования
    //Goal* deepCopy() const {
    //    Goal* newGoal = new Goal(name, targetAmount, *conversion); //Вызов конструктора Goal
    //    newGoal->next = nullptr; // Указатель на следующий объект Goal -  пустой
    //    return newGoal;
    //}
   

    //Goal(const Goal& other) = delete; // Запрет конструктора копирования
    //Goal& operator=(const Goal& other) = delete; // Запрет оператора присваивания

    std::string extractSubName(size_t startPos, size_t length) const;
    bool containsKeyword(const std::string& keyword) const;
    void toUpperName();
    void addGoal(Goal* newGoal);       // Новый метод
    void removeGoal(Goal* goalToRemove); // Новый метод
    virtual void convertTargetAmount(const Conversion& conversion) const; // Новый метод
    
    
    const char* getConversionCurrency() const {
        if (conversion) return conversion->getCurrency();
        else return ""; //обработка nullptr
    }
    int getConversionRate() const {
        if (conversion) return conversion->getCurrencyRate();
        else return 0; //обработка nullptr
    }
};  
