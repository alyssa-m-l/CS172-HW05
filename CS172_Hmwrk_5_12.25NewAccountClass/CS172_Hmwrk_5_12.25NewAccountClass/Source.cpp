//Name: Alyssa La Fleur
//Class CS172
//Homework #5
//Problem 12.25 New Account Class
//Purpose:  To create the Date, Transaction, and Account classes given in the book from class descriptions, then modify the Account class to use vectors to log all transactions

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

//Specified test of modified Account class
int main()
{
	//Declaring account, static interest rate variable
	Account newAcc(1122, "George", 1000);
	Account::setAnnualInterestRate(1.5);
	//Completing requested deposits and withdrawals
	newAcc.deposit(30);
	newAcc.deposit(40);
	newAcc.deposit(50);
	newAcc.withdraw(5);
	newAcc.withdraw(4);
	newAcc.withdraw(2);
	//Outputting desired information
	cout << "Name: " << newAcc.getName() << endl;
	cout << "Interest rate: " << Account::getAnnualInterestRate() << endl;
	cout << "Balance: " << newAcc.getBalance() << endl;
	cout << "Transactions: " << endl;
	int lengthtrans = newAcc.getTransac().size();
	for (int i = 0; i < lengthtrans; i++)
	{
		newAcc.getTransac()[i].printTransaction();
	}
	return 0;
}