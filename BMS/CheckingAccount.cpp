
#include "CheckingAccount.h"
using namespace std;


CheckingAccount::CheckingAccount(int accountNumber, int balance,double overdraftFee)
    :Account(accountNumber, balance)
{
    this->overdraftFee = overdraftFee;
}

double CheckingAccount::getOverdraftFee()
{
    return this->overdraftFee;
}

void CheckingAccount::withdraw(double amount)
{
    if (this->balance - amount >= -100) {
        this->balance -= amount;
    }
    else {
        cout << "Insufficient funds or overdraft limit exceeded." << endl;
    }
}


