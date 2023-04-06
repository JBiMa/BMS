#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include "Customer.h"
#include "User.h"
#include "account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;
class Bank
{
protected:
    vector<Account*> accounts;
    vector<Customer*> customers;
    

public:
    void addAccount(Account* account);
    Account* getAccount(int accountNumber);

    void addCustomer(Customer* customer);
    Customer* getCustomer(string username);

    const vector<Customer* >& getAllCustomers() const;
};


class InvalidAccountLoginException : public exception {
public:
    InvalidAccountLoginException() : exception("Invalid login or password") {}
};