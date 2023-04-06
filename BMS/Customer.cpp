#include "Customer.h"
using namespace std;

Customer::Customer(string username, string password, Account* account)
    : User(username, password) {
    this->account = account;
}
string Customer::getUsername() const
{
    return this->username;
}

Account* Customer::getAccount() const {

    return this->account;
}

bool Customer::operator==(const Customer& other) const {
    return this->username == other.username;
}