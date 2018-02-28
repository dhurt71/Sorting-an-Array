//Author: Devon Hurt
//CPSC 121 Lab 7
//04/08//17

//Libraries used
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Functions used and defined outside of main
void sort(int[], int);
void fillRandom(int*, int, int, int);
void menuValues();
void menuSort();
void swap(int*, int*);
void selectSort(int*, int);

//Global, constant variables
const int range = 100;
const int min = 0;

int main()
{
	//Variables used in main
	int *array = NULL;
	int arraySize;
	int userOption;
	int userSort;
	srand(time(NULL));
	char exit;

	//Loop to run the program another time
	do 
	{
		//Prompt user for an array size
		cout << "Enter an array size." << endl;
		cin >> arraySize;

		//Dynamically allocate an array size based on user input
		array = new int[arraySize];

		//Set all values to 0 before inputting
		for (int i = 0; i < arraySize; i++)
		{
			array[i] = 0;
		}

		//Displays the first menu of inputting values or randomly generated ones
		menuValues();
		cin >> userOption;
		cout << "-----------------------------" << endl;

		//If the user selects inputting values
		if (userOption == 1)
		{
			for (int i = 0; i < arraySize; i++)
			{
				cin >> array[i];
			}
		}

		//If the user selects randomly generated values
		if (userOption == 2)
		{
			fillRandom(array, arraySize, range, min);
		}

		//Displaying the array after values have been stored
		cout << "-----------------------------" << endl;
		cout << "The array contains:" << endl;
		for (int i = 0; i < arraySize; i++)
		{
			cout << array[i] << endl;
		}

		//Displays the second menu of choosing the sort method
		menuSort();
		cin >> userSort;

		//If the user selects bubble sort
		if (userSort == 1)
		{
			sort(array, arraySize);
		}

		//If the user chooses selection sort
		if (userSort == 2)
		{
			selectSort(array, arraySize);
		}

		//Displays the array after values have been sorted
		cout << "-----------------------------" << endl;
		cout << "After sorting, the array contains:" << endl;
		for (int i = 0; i < arraySize; i++)
		{
			cout << array[i] << endl;
		}

		//Prompting the user to use the program again
		cout << "Would you like to run the program again? (Yes = y, No = n)" << endl;
		cin >> exit;

		//Deleting the array at the end to free up space in memory
		delete[] array;
		array = NULL;

	} while (exit == 'y');

	system("pause");

	return 0;
}

//First menu to select value generation method
void menuValues()
{
	cout << "Choose an option." << endl;
	cout << "1. Input values." << endl;
	cout << "2. Randomly generated values." << endl;
	cout << "-----------------------------" << endl;
}

//Second menu to select sorting method
void menuSort()
{
	cout << "Choose an option." << endl;
	cout << "1. Bubble Sort." << endl;
	cout << "2. Selection Sort." << endl;
	cout << "-----------------------------" << endl;
}

//Function used to sort the values in the array from least to greatest
void sort(int array[], int arraySize)
{
	//Variables used in the sort function
	bool change;
	int temp;

	//Loop to keep sorting until change doesn't return true
	do
	{
		//Variables used in the loop under the sort function
		change = false;

		//Loop to sort one value at a time by comparing the current index with the next and swapping those two. 
		//This keeps happening until the end of the loop.
		for (int i = 0; i < (arraySize - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				change = true;
			}
		}
	} while (change);
}

//Function used to swap variables in the bubble sort method
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Function that assigns random values to each element in the array
void fillRandom(int *array, int arraySize, int range, int min)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = min + rand() % range;
	}
}

//Function that uses the lowest value and swaps it to the beginning
void selectSort(int *array, int arraySize)
{
	//Variables used in the selectSort function
	int scan;
	int minIndex;
	int minValue;

	//Loop to scan through the array 
	for (int i = 0; i < (arraySize - 1); i++)
	{
		minIndex = i;
		minValue = array[i];

		//Loop to replace the lowest value and place it at the beginning
		for (int j = i + 1; j < arraySize; j++)
		{
			if (array[j] < minValue)
			{
				minValue = array[j];
				minIndex = j;
			}
		}
		array[minIndex] = array[i];
		array[i] = minValue;
	}
}