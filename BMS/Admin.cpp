#include "Admin.h"

using namespace std;


Admin::Admin(string username, string password, int permission)
    : User(username, password) {
    this->permission = permission;
}

string Admin::getUsername()
{
    return this->username;
}

int Admin::getPermission()
{
    return this->permission;
}

void Admin::checkCustomers(Bank &bank)
{
    for_each(bank.getAllCustomers().begin(), bank.getAllCustomers().end(), [](Customer* const c) {
        cout << "Username: " << c->getUsername() << endl;
        cout << "Account Number: " << c->getAccount()->getAccountNumber() << endl;
        cout << "Account Balance: " << c->getAccount()->getBalance() << endl;
    });
}

void Admin::changePermission(int data)
{
    if (data < 0 && data >=4) {
        throw invalid_argument("Invalid provided permission");
    }
    else if (this->permission<=2) {
        throw invalid_argument("Yours permission are not enough");
    }
    this->permission = data;
}
