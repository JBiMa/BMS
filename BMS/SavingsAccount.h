#pragma once
#include "account.h"
class SavingsAccount :
    public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber,int balance, double interestRate);
    double getInterestRate();
    void addInterest();
};

