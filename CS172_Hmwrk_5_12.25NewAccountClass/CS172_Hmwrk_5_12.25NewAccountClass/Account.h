#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include "Date.h"
#include "Transaction.h"
using namespace std;

class Account
{
private:
	//Private variables for class
	int id;
	double balance;
	//Static variable for intrest
	static double annualInterestRate;
	string name;
	//Vector for transactions log
	vector<Transaction> transactions;
public:
	//No arg constructor
	Account();
	//Constructor which takes in id, name, and origninal balance
	Account(int newid, string newname, double newBal);
	//Getter and setter functions for id number
	int getId();
	void setId(int newId);
	//Getter and setter functiosn for balance
	double getBalance();
	void setBalance(double newBal);
	//Getter and setter static functions for the static interest variable
	static double getAnnualInterestRate();
	static void setAnnualInterestRate(double newAnn);
	//Function to find monthly rate from static interest rate
	static double getMonthlyInterestRate();
	//Withdrawal and deposit functions, which add a transaction to the transaction object vector, and adjust the original balance as needed
	void withdraw(double wamount);
	void deposit(double damount);
	//Getter functions for name and transactions vector
	string getName();
	vector<Transaction> getTransac();
};

#endif

