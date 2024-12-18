#pragma once
#include <string>
#include "Conversion.h"
#include <stdexcept> // ��� ��������� ����������
#include <memory> //��� unique_ptr

class Goal {
protected:
    std::string name;
    int targetAmount;
    std::unique_ptr<Conversion> conversion; // ���������� unique_ptr ��� ��������������� ���������� �������
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
    
    //// ����� �������������� ������������
    //Goal* shallowCopy() const {
    //    return new Goal(*this); // ���������� ����������� �����������
    //}

    //// ����� ��������� ������������
    //Goal* deepCopy() const {
    //    Goal* newGoal = new Goal(name, targetAmount, *conversion); //����� ������������ Goal
    //    newGoal->next = nullptr; // ��������� �� ��������� ������ Goal -  ������
    //    return newGoal;
    //}
   

    //Goal(const Goal& other) = delete; // ������ ������������ �����������
    //Goal& operator=(const Goal& other) = delete; // ������ ��������� ������������

    std::string extractSubName(size_t startPos, size_t length) const;
    bool containsKeyword(const std::string& keyword) const;
    void toUpperName();
    void addGoal(Goal* newGoal);       // ����� �����
    void removeGoal(Goal* goalToRemove); // ����� �����
    virtual void convertTargetAmount(const Conversion& conversion) const; // ����� �����
    
    
    const char* getConversionCurrency() const {
        if (conversion) return conversion->getCurrency();
        else return ""; //��������� nullptr
    }
    int getConversionRate() const {
        if (conversion) return conversion->getCurrencyRate();
        else return 0; //��������� nullptr
    }
};  
