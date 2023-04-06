#include "account.h"
using namespace std;

Account::Account(int accountNumber, int balance)
{
	this->accountNumber = accountNumber;
	this->balance = balance;
}

void Account::preview()
{
	cout << "Account Number: " << this->accountNumber << endl;
	cout << "Balance: " << this->balance << endl;
}

void Account::deposit(double amount) {
	if (amount <= 0) {
		throw invalid_argument("Invalid deposit amount.");
	}
	this->balance += amount;
}

void Account::withdraw(double amount) {
	if (amount <= 0) {
		throw invalid_argument("Invalid withdrawal amount.");
	}
	if (this->balance - amount < 0) {
		throw out_of_range("Insufficient funds.");
	}
	this->balance -= amount;
}


int Account::getAccountNumber() {
	return this->accountNumber;
}

double Account::getBalance() {
	return this->balance;
}

Account::~Account()
{
}

Account Account::operator+(const Account& other) const {
	Account result(*this);
	result.balance += other.balance;
	return result;
}