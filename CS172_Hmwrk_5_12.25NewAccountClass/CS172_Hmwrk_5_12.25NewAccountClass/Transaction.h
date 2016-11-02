#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "Date.h"
using namespace std;

class Transaction
{
private:
	//Private variables for class from problem requirements
	//Date of transaction
	Date date;
	//Type of transaction, ie, 'D' for deposit, 'W' for withdrawal, etc
	char type;
	//Amount involved in transaction
	double amount;
	//Account balance before transaction
	double balance;
	//Description of transaction, "withdrawal", "deposit", etc
	string description;
public:
	//Constructor function for transaction object, input of all variables in class
	Transaction(Date date, char type, double amount, double balance, string description);
	//Printing function not specified in problem, but needed for easier printing of transactions in Account for source.cpp, no input, no outputs
	void printTransaction();
};

#endif

