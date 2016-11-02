//Name: Alyssa La Fleur
//Class CS172
//Homework #5
//Problem EX05_02
//Purpose: A program with a function to check if the elements in an array are sorted

#include <iostream>
using namespace std;

template <typename T>
bool isSorted(const T list[], int size)
{
	bool issorted = false;
	int limit = size;
	//storage variable for loops
	T storage = list[0];
	//Create new list and copy all search list elements into it
	T * listnew = new T[size];
	for (int i = 0; i < size; i++)
	{
		listnew[i] = list[i];
	}
	//Loop through all contents of new list, sort them
	for (int i = 0; i < limit; i++)
	{
		//Compare all elements to one before
		for (int j = i + 1; j < limit; j++)
		{
			//If it is larger, replace letter before with letter
			if (listnew[j - 1] > listnew[j])
			{
				storage = listnew[j];
				listnew[j] = listnew[j - 1];
				listnew[j - 1] = storage;
			}
		}
	}
	//Check if list original is the same as the sorted list
	for (int k = 0; k < size; k++)
	{
		//Checks if elements are the same
		if (list[k] == listnew[k])
		{
			issorted = true;
		}
		//If elements are not the same, deletes the new list, and returns false
		else
		{
			delete[] listnew;
			return false;
		}
	}
	//If all elements are the same, deletes the new list and returns true
	delete[] listnew;
	return issorted;
}

int main()
{
	//Int test for template function
	int listtesti[4] = { 1,2,3,4 };
	int listtesti2[4] = { 1,3,2,4 };
	if (isSorted <int>(listtesti, 4))
	{
		cout << "Is sorted- works" << endl;
	}
	if (!isSorted <int>(listtesti2, 4))
	{
		cout << "Is not sorted- works" << endl;
	}
	//Double test for template function
	double listtestd[4] = { 1,2,3,4 };
	double listtestd2[4] = { 1,3,2,4 };
	if (isSorted <double>(listtestd, 4))
	{
		cout << "Is sorted- works" << endl;
	}
	if (!isSorted <double>(listtestd2, 4))
	{
		cout << "Is not sorted- works" << endl;
	}
	//String tests for template function
	string listtests[4] = { "1","2","3","4" };
	string listtests2[4] = { "1","3","2","4" };
	if (isSorted <string>(listtests, 4))
	{
		cout << "Is sorted- works" << endl;
	}
	if (!isSorted <string>(listtests2, 4))
	{
		cout << "Is not sorted- works" << endl;
	}
	return 0;
}