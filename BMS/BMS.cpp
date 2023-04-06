#include <iostream>
#include <exception> 
#include "Bank.h"
#include "Customer.h"
#include "User.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "account.h"
#include "Menu.h"
#include "Admin.h"



using namespace std;

int main()
{
    Bank bank;
    Account* account1 = new SavingsAccount(1, 44000, 0.1);
    Account* account2 = new CheckingAccount(2, 500, 25);
    Admin* admin1 = new Admin("Root", "asd", 3);
    Customer* customer1 = new Customer("A", "W", account1);
    Customer* customer2 = new Customer("K", "S", account2);
    bank.addCustomer(customer1);
    bank.addCustomer(customer2);
    

    while (true)
    {
        login(bank,account1, customer1, account2, customer2, admin1);
    }
}

