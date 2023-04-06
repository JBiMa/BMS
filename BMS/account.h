#pragma once
#include<iostream>
#include<exception>

class Account
{
protected:
	int accountNumber;
	double balance;

private:

public:
	Account(int accountNumber, int balance);
	~Account();
	void preview();
	void deposit(double amount);
	void withdraw(double amount);
	double getBalance();
	int getAccountNumber();
	Account operator+(const Account& other) const;
};

