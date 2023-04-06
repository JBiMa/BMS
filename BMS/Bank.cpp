#include "Bank.h"

using namespace std;

void Bank::addAccount(Account* account) {
    if (account == nullptr) {
        throw invalid_argument("account cannot be nullptr");
    }
    this->accounts.push_back(account);
}

Account* Bank::getAccount(int accountNumber) {
    for (auto account : this->accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account;
        }
    }

    return nullptr;
}

void Bank::addCustomer(Customer* customer) {

    if (customer == nullptr) {
        throw invalid_argument("customer cannot be nullptr");
    }
    this->customers.push_back(customer);
}

Customer* Bank::getCustomer(string username) {
    for (auto customer : this->customers) {
        if (customer->getUsername() == username) {
            return customer;
        }
    }
    return nullptr;
}

const vector<Customer*>& Bank::getAllCustomers() const
{
    return customers;
}
