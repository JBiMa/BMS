#pragma once
#include <iostream>
#include "account.h"


class CheckingAccount :
    public Account
{
private:
    double overdraftFee;

public:
    CheckingAccount(int accountNumber,int balance,double overdraftFee);
    double getOverdraftFee();
    void withdraw(double amount);
};

