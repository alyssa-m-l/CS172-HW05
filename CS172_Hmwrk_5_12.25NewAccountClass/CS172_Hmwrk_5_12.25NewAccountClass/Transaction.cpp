#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

//Constructor function specified for class, input of date, type, amount of transaction, overall balance, and description of action
Transaction::Transaction(Date date, char type, double amount, double balance, string description)
{
	this->date = date;
	this->type = type;
	this->amount = amount;
	this->balance = balance;
	this->description = description;
}

//Printer function for relevant values created for easier printing of transaction details for source.cpp portion of problem, no input, no output
void Transaction::printTransaction()
{
	cout << "Date: " << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
	cout << "Description: " << description << endl;
	cout << "Amount for transaction: " << amount << endl;
}