#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int accountNumber, int balance, double interestRate)
    :Account(accountNumber, balance)
{
    this->interestRate = interestRate;
}

double SavingsAccount::getInterestRate()
{
    return this->interestRate;
}

void SavingsAccount::addInterest()
{
    this->deposit(this->getBalance() * this->interestRate);
}
