#include <iostream>
#include "Account.h"
#include <vector>
using namespace std;

//Declaring static interest variable
double Account::annualInterestRate = 0;

//No argument constructor, no inputs, no outputs
Account::Account()
{
	id = 0;
	balance = 0;
	annualInterestRate = 0;
}

//Constructor with inputs of the account id, name of the account holder, and the beginning balance
Account::Account(int newid, string newname, double newBal)
{
	id = newid;
	name = newname;
	balance = newBal;
}

//Getter function for id, no inputs, output of id value
int Account::getId()
{
	return id;
}

//Setter function for id, input of new id, no outputs
void Account::setId(int newId)
{
	id = newId;
}

//Getter function for account balance, no inputs, output of balance
double Account::getBalance()
{
	return balance;
}

//Setter function for account balance, input of new balance, no output
void Account::setBalance(double newBal)
{
	balance = newBal;
}

//Getter function for interest rate static varaible, no inputs, output of rate
double Account::getAnnualInterestRate()
{
	return annualInterestRate;
}

//Setter function for interest rate, input of new annual rate, no outputs
void Account::setAnnualInterestRate(double newAnn)
{
	annualInterestRate = newAnn;
}

//A function to return the monthly interest rate, no inputs, output of monthly rate
double Account::getMonthlyInterestRate()
{
	return annualInterestRate / 12.0;
}

//Function to complete withdrawal and add transaction to transactions vector, input of amount to be withdrawn, no output
void Account::withdraw(double wamount)
{
	//Setting up transaction object
	Date date;
	Transaction trans(date, 'W', wamount, balance, "Withdrawal");
	//Pushing object onto vector of objects for account object
	transactions.push_back(trans);
	//Decreasing total balance in account
	balance = balance - wamount;
}

//Function to complete deposit and add transaction for deposit to transactions vector, input of amount to deposit, no outputs
void Account::deposit(double damount)
{
	//Setting up transaction object
	Date date;
	Transaction trans(date, 'D', damount, balance, "Deposit");
	transactions.push_back(trans);
	//Adjusting balance
	balance = balance + damount;
}

//Getter function for name, no inputs, output of name
string Account::getName()
{
	return name;
}

//Getter function for transaction vector, no inputs, output of vector
vector<Transaction> Account::getTransac()
{
	return transactions;
}