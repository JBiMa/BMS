#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Bank.h"
#include "User.h"

using namespace std;



class Admin :
    public User
{
private:
    int permission;

public:
    Admin(string username, string password, int permission);
    string getUsername();
    int getPermission();
    void checkCustomers(Bank& bank);
    void changePermission(int data);
};

