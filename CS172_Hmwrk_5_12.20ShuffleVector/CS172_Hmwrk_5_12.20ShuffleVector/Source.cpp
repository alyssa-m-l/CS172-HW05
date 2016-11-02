//Name: Alyssa La Fleur
//Class CS172
//Homework #5
//Problem EX05_04: 12.20 Shuffle vector
//Purpose:  A program with a template function to shuffle vectors

#include <iostream>
#include <vector>
using namespace std;


//Template function to shuffle vector, input of vector to be shuffled, no output
//Since amount of shuffling is not specified, this function shuffles by swapping every even idex element with the next indexed even element
template <typename T>
void shuffle(vector<T> &v)
{
	//Declaring size for for loops
	int length = v.size();
	//Declaring vector to store elements for shuffling
	vector <T> temp(length);
	//Copying original vector
	for (int i = 0; i < length; i++)
	{
		temp[i] = v[i];
	}
	//Shuffling contents of copied vector
	for (int j = 0; j < length; j++)
	{
		if (j % 2 == 0)
		{
			if (temp[j] == v[j])
			{
				T store = temp.at(j);
				if (j + 2 < length - 1)
				{
					temp[j] = v[j + 2];
					temp[j + 2] = store;
				}
			}
		}
	}
	//Swapping original vector and copied vector
	v.swap(temp);
}

//Running requested test for swap function
int main()
{
	//Declaring needed vector
	vector<int> vect;
	int length = 10;
	int entry = 0;
	//Pushing back user entry 10 times for required vector
	for (int i = 0; i < length; i++)
	{
		cin >> entry;
		vect.push_back(entry);
	}
	//shuffling vector
	shuffle(vect);
	//Displaying shuffled vector for comparison to original
	cout << "The shuffled vector is: " << endl;
	for (int j = 0; j < length; j++)
	{
		cout << vect.at(j) << endl;
	}
	return 0;
}