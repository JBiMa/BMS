#pragma once
#include <iostream>
#include <string>
#include "Bank.h"
#include "Admin.h"
#include "Customer.h"
#include "User.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "account.h"

bool menu(string enteredUsername, string enteredPassword, Customer* customer);
bool login(Bank& bank,Account* account1, Customer* customer1, Account* account2, Customer* customer2, Admin* admin);
