//Name: Alyssa La Fleur
//Class CS172
//Homework #5
//Problem EX05_01
//Purpose:  A rewrite of the linear search function from chp 7 to use templates

#include <iostream>
using namespace std;

//Template function to perform linear search
template <typename T>
int linearSearch(const T list[], T key, int size)
{
	//Loop to cycle through array elements
	for (int i = 0; i < size; i++)
	{
		//If the index value is the same as the search value, returns index location
		if (key == list[i])
		{
			return i;
		}
		//Otherwise, returns -1 if the value is not present in the array
		return -1;
	}
}

//Requested tests of function from problem
int main()
{
	//Declaring arrays to be tested
	int listtest[4] = { 1,2,3,4 };
	double listtestd[4] = { 1.1,2.1,3.1,4.1 };
	string listtests[4] = { "a", "b", "c", "d" };
	//Test for int 
	cout << linearSearch <int>(listtest, 1, 4) << endl;
	//Test for doubles
	cout << linearSearch <double>(listtestd, 1.1, 4) << endl;
	//Test for strings
	cout << linearSearch <string>(listtests, "a", 4) << endl;
	return 0;
}