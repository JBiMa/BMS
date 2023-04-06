#pragma once
#include <string>
#include "User.h"
#include "account.h"

class Customer :
    public User
{
private:
    Account* account;

public:
    Customer(string username, string password, Account* account);
    string getUsername() const;
    Account* getAccount() const;
    bool operator==(const Customer& other) const;
};

