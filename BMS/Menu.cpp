#pragma once
#include "Menu.h"
#include <exception>
using namespace std;
Bank bank;


bool login(Bank& bank, Account* account1, Customer* customer1, Account* account2, Customer* customer2, Admin* admin)
{
    int menuOpt;
    cout << "1-Admin" << endl;
    cout << "2-Customer" << endl;
    cout << "3-Exit" << endl;
    cout << "Option: ";
    cin >> menuOpt;
    cout << endl;
    switch (menuOpt)
    {
    case 1:
        try {
            string enteredUsername, enteredPassword;
            cout << "Enter your username: ";
            cin >> enteredUsername;
            cout << "Enter your password: ";
            cin >> enteredPassword;

            if (admin != nullptr && admin->checkCredentials(enteredUsername, enteredPassword)) {
                cout << "Welcome, " << enteredUsername << "!" << endl;

                cout << "Your permission: $" << admin->getPermission() << endl;
                admin->checkCustomers(bank);
                Account account3 = (*account1 + *account2);
                cout << "Money sum in bank: "<< account3.getBalance() << endl;
                if (customer1 == customer2) {
                    cout << "there are duplicated accounts" << endl;
                }
                else {
                    cout << "there are no duplicated accounts" << endl;
                }
            }
            else
            {
                throw InvalidAccountLoginException();
            }

        }
        catch (InvalidAccountLoginException& e) {
            cout << e.what() << endl;
        }
        break;

    case 2:
        try {
            string enteredUsername, enteredPassword;
            cout << "Enter your username: ";
            cin >> enteredUsername;
            cout << "Enter your password: ";
            cin >> enteredPassword;

            Customer* customer = bank.getCustomer(enteredUsername);
            if (customer != nullptr && customer->checkCredentials(enteredUsername, enteredPassword)) {
                cout << "Welcome, " << enteredUsername << "!" << endl;
                cout << "Your account balance is: $" << customer->getAccount()->getBalance() << endl;
                if (!menu(enteredUsername, enteredPassword, customer))
                {
                    break;
                }
            }
            else
            {
                throw InvalidAccountLoginException();
            }

        }
        catch (InvalidAccountLoginException& e) {
            cout << e.what() << endl;
        }
        break;
    case 3:
        exit(1);
        break;
    default:
        cout << "Problem with menu option" << endl;
        break;
    }
}
bool menu(string enteredUsername, string enteredPassword, Customer* customer)
{

    double data;
    int menuOpt = 1;

    while (menuOpt)
    {
        cout << "1-Deposit" << endl;
        cout << "2-Withdraw" << endl;
        cout << "3-Balance" << endl;
        cout << "4-View Account" << endl;
        cout << "5-Logout" << endl;
        cout << "6-Exit" << endl;
        cout << "Option: ";
        cin >> menuOpt;
        cout << endl;
        switch (menuOpt)
        {
        case 1:
            cout << "How much you want to deposit: ";
            cin >> data;
            cout << endl;
            try {
                customer->getAccount()->deposit(data);
            }
            catch (exception& e){
                cout << e.what() << endl;
            }
            cout << "Your account balance now is: $" << customer->getAccount()->getBalance() << endl;
            break;
        case 2:
            cout << "How much you want to withdraw: ";
            cin >> data;
            cout << endl;    
            try {
                customer->getAccount()->withdraw(data);
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            cout << "Your account balance now is: $" << customer->getAccount()->getBalance() << endl;
            break;
        case 3:
            cout << "Your account balance is: $" << customer->getAccount()->getBalance() << endl;
            break;
        case 4:
            customer->getAccount()->preview();
            break;
        case 5:
            cout << "Logout" << endl;
            return false;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Problem with menu option" << endl;
            break;
        }
    }
}


