//Name: Alyssa La Fleur
//Class CS172
//Homework #5
//Problem: 12.8 Implement Vector Class / EX05_03
//Purpose:  A program with a class which fufills the same actions as the functions depicted in figure 12.2

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
	//Private variables for template 'vector' class
	//Pointer to array for type T elements
	T * list;
	//Size of array
	int size;
	//Number of elements in array
	int filled;
	//Private function to double the size of the array, and fill it with old values, input of new size, no output
	void IncreaseSizeVector(int newSize)
	{
		//Create temporary array
		T* newList = new T[newSize];
		//Fill array with old variables
		for (int i = 0; i < filled; i++)
		{
			newList[i] = list[i];
		}
		//Delete old list
		delete[] list;
		//Set temp array to list pointer
		list = newList;
		//Set new size to double the size
		size = newSize;
	}

public:
	//No arg constructor, with a array of size 1 because size 0 is not allowed, no input, no output
	Vector()
	{
		list = new T[1];
		size = 0;
		filled = 0;
	}
	//Constructor wtih a specified size for the array, input of size, no output
	Vector(int size)
	{
		list = new T[size];
		this->size = size;
		filled = 0;
	}
	//Function to add elements to the array, input of element to be added, no outputs
	void Push_back(T element)
	{
		//Checking if array needs to be expanded
		int sizenew = filled + 1;
		if (sizenew > size|| size == 0)
		{
			//Making sure that size != 0 for doubling the size
			if (size == 0)
			{
				size = 1;
			}
			//Doubling the size of the array
			int doublesize = size * 2;
			IncreaseSizeVector(doublesize);
			//Adding new element, increasing track of filled positions of array
			list[filled] = element;
			filled++;
		}
		//If array size does not need to be increased, adds the element to the array, increases the number of filled positions
		else
		{
			list[filled] = element;
			filled++;
		}
	}
	//Function to decrease the size of the array by last element, no input, no output
	void Pop_back()
	{
		//Decreasing positions filled
		filled--;
		//Creates smaller array, removing last position entirely
		IncreaseSizeVector(filled);
	}
	//Function to return number of filled positions, no input, output of filled positions
	int Size() const
	{
		return filled;
	}
	//Function to return the element value at a given index
	T at(int index)
	{
		//Checks if the index falls in the range of the array, if so, returns the element
		if (index < filled || index == filled)
		{
			return list[index];
		}
		//If it does not fall in the array, displays a error message, and returns the first element of the array by default
		else
		{
			cout << "Invalid index entry, returned first eleemnt" << endl;
			return list[0];
		}
	}
	//Function to determine if the array is empty, no inputs, output of bool value for emptiness
	bool empty()
	{
		//Declaring needed bool value
		bool empty = false;
		//Checking if no positions are filled, if none are, changes bool value to true
		if (filled == 0)
		{
			empty = true;
		}
		//Returns bool value
		return empty;
	}
	//Function to clear, no inputs, no outputs
	void clear()
	{
		//Resetting size and filled positiosn to 0
		size = 0;
		filled = 0;
		//Setting the list pointer to a list with one object, filled with random data, as arrays with length 0 are not allowed
		T * emptylist = new T[1];
		delete[] list;
		list = emptylist;
	}
	//Function to return list size for use in swap, no inputs, output of size
	int GetSizeList()
	{
		return size;
	}
	//Function to swap all values of two vectors
	void swap(Vector v2)
	{
		//Copying all values from list two
		T * clone = new T[v2.GetSizeList()];
		int clonesize = v2.GetSizeList();
		int clonefilled = v2.Size();
		//Filling array with all list two values
		for (int i = 0; i < clonesize; i++)
		{
			clone[i] = v2.at(i);
		}
		//Emptying list two
		v2.clear();
		//Pushing all element of list one to list two, which also sets list two size and filled positions to list one's
		for (int j = 0; j < size; j++)
		{
			v2.Push_back(list[j]);
		}
		//Deleting orignial list
		delete[] list;
		//Setting original list to the copied list
		list = clone;
		//Setting all other variables to copied variables
		size = clonesize;
		filled = clonefilled;
	}
};


//Test of all functions in class with two int vectors
int main()
{
	Vector <int> vecti(10);
	vecti.Push_back(10);
	vecti.Pop_back();
	int size = vecti.Size();
	cout << size << endl;
	if (!vecti.empty())
	{
		cout << "Passed empty test" << endl;
	}
	vecti.clear();
	vecti.Push_back(1);
	vecti.Push_back(2);
	int test = vecti.at(0);
	cout << test << endl;
	vecti.Push_back(3);
	vecti.Push_back(4);
	int testsize = vecti.Size();
	int endel = vecti.at(testsize - 1);
	cout << endel << endl;
	for (int j = 0; j < vecti.Size(); j++)
	{
		cout << vecti.at(j) << endl;
	}
	Vector <int> vecti2;
	for (int i = 1; i < 5; i++)
	{
		vecti2.Push_back(10);
	}
	vecti.swap(vecti2);
	for (int j = 0; j < vecti.Size(); j++)
	{
		cout << vecti.at(j) << endl;
	}
	for (int k = 0; k < vecti2.Size(); k++)
	{
		cout << vecti2.at(k) << endl;
	}
	return 0;
}