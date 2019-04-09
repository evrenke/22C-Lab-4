/*
Authors: Evren Keskin, Jason Hagene
Date: 11/09/2018
Description: This program will allow the user to create an array of data and display its sorting
The user is prompted to choose between int,double,char, and string arrays to create
Then they enter data into the array manually
Finally the array is seperately sorted three times using
Insertion Sort, Quick Sort and Merge Sort, all recursive
Every step in each sort is displayed to the user
*/


#include "Array.h"
#include <string>
#include <iostream>
#include <fstream>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

template <class ObjectType>
void insertionSort(Array<ObjectType> *array, int lastElem, std::ofstream *outfile);

template <class ObjectType>
void quickSort(Array<ObjectType> *copy, int start, int end, std::ofstream *outfile);

template <class ObjectType>
void mergeSort(Array<ObjectType> *copy, int start, int end, std::ofstream *outfile);

template <class ObjectType>
void sortingArray(std::ofstream *outfile, Array<ObjectType> *array);

int takeIntegerInput(std::ofstream *outfile, int min, int max);
int takeIntegerInput(std::ofstream *outfile);// max range
double takeDoubleInput(std::ofstream *outfile);
char takeCharInput(std::ofstream *outfile);
std::string takeStringInput(std::ofstream *outfile);

template <class ObjectType>
void writeOutput(std::ofstream *outfile, ObjectType output);

int main()
{
	std::ofstream outputFile;
	outputFile.open("output.txt");
	
	bool isUsingProgram = true;
	int inputNumber = 0;
	do
	{
		writeOutput(&outputFile, "Hello! What kind of array would you like to make?\n");
		writeOutput(&outputFile, "-------------------------------------------------\n");
		writeOutput(&outputFile, "1) Integer array\n");
		writeOutput(&outputFile, "2) Double array\n");
		writeOutput(&outputFile, "3) Character array\n");
		writeOutput(&outputFile, "4) String array\n");
		writeOutput(&outputFile, "5) Exit\n");
		inputNumber = takeIntegerInput(&outputFile, 0, 5);
		switch (inputNumber)
		{
		case 1://Integer array made
		{
			writeOutput(&outputFile, "How long you want your integer array to be? (Maximum of 32)\n");
			writeOutput(&outputFile, "(Enter zero to return)\n");
			writeOutput(&outputFile, "-------------------------------------------\n");
			inputNumber = takeIntegerInput(&outputFile, 0, 32);
			Array<int> intArray = Array<int>(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					writeOutput(&outputFile, "Enter the integer at the " + std::to_string(ind + 1) + "st place in your array: \n");
					break;
				case 1:
					writeOutput(&outputFile, "Enter the integer at the " + std::to_string(ind + 1) + "nd place in your array: \n");
					break;
				case 2:
					writeOutput(&outputFile, "Enter the integer at the " + std::to_string(ind + 1) + "rd place in your array: \n");
					break;
				default:
					writeOutput(&outputFile, "Enter the integer at the " + std::to_string(ind + 1) + "th place in your array: \n");
					break;
				}
				int number = takeIntegerInput(&outputFile);
				intArray[ind] = number;
			}
			sortingArray(&outputFile, &intArray);
			intArray.~Array();
		}
		break;
		case 2://Double array made
		{
			writeOutput(&outputFile, "How long you want your double array to be? (Maximum of 32)\n");
			writeOutput(&outputFile, "(Enter zero to return)\n");
			writeOutput(&outputFile, "-------------------------------------------\n");
			inputNumber = takeIntegerInput(&outputFile, 0, 32);
			Array<double> doubleArray = Array<double>(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					writeOutput(&outputFile, "Enter the double at the " + std::to_string(ind + 1) + "st place in your array: \n");
					break;
				case 1:
					writeOutput(&outputFile, "Enter the double at the " + std::to_string(ind + 1) + "nd place in your array: \n");
					break;
				case 2:
					writeOutput(&outputFile, "Enter the double at the " + std::to_string(ind + 1) + "rd place in your array: \n");
					break;
				default:
					writeOutput(&outputFile, "Enter the double at the " + std::to_string(ind + 1) + "th place in your array: \n");
					break;
				}
				double number = takeDoubleInput(&outputFile);
				doubleArray[ind] = number;
			}
			sortingArray(&outputFile, &doubleArray);
			doubleArray.~Array();
		}
		break;
		case 3://character array made
		{
			writeOutput(&outputFile, "How long you want your character array to be? (Maximum of 32)\n");
			writeOutput(&outputFile, "(Enter zero to return)\n");
			writeOutput(&outputFile, "-------------------------------------------\n");
			inputNumber = takeIntegerInput(&outputFile, 0, 32);
			Array<char> charArray(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					writeOutput(&outputFile, "Enter the character at the " + std::to_string(ind + 1) + "st place in your array: \n");
					break;
				case 1:
					writeOutput(&outputFile, "Enter the character at the " + std::to_string(ind + 1) + "nd place in your array: \n");
					break;
				case 2:
					writeOutput(&outputFile, "Enter the character at the " + std::to_string(ind + 1) + "rd place in your array: \n");
					break;
				default:
					writeOutput(&outputFile, "Enter the character at the " + std::to_string(ind + 1) + "th place in your array: \n");
					break;
				}
				char charInput = takeCharInput(&outputFile);
				charArray[ind] = charInput;
			}
			sortingArray(&outputFile, &charArray);
			charArray.~Array();
		}
		break;
		case 4://string array made
		{
			writeOutput(&outputFile, "How long you want your string array to be? (Maximum of 32)\n");
			writeOutput(&outputFile, "(Enter zero to return)\n");
			writeOutput(&outputFile, "-------------------------------------------\n");
			inputNumber = takeIntegerInput(&outputFile, 0, 32);
			Array<std::string> stringArray(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					writeOutput(&outputFile, "Enter the string at the " + std::to_string(ind + 1) + "st place in your array: \n");
					break;
				case 1:
					writeOutput(&outputFile, "Enter the string at the " + std::to_string(ind + 1) + "nd place in your array: \n");
					break;
				case 2:
					writeOutput(&outputFile, "Enter the string at the " + std::to_string(ind + 1) + "rd place in your array: \n");
					break;
				default:
					writeOutput(&outputFile, "Enter the string at the " + std::to_string(ind + 1) + "th place in your array: \n");
					break;
				}
				std::string stringInput = takeStringInput(&outputFile);
				stringArray[ind] = stringInput;
			}
			sortingArray(&outputFile, &stringArray);
			stringArray.~Array();
		}
		break;
		case 5://exiting program
			isUsingProgram = false;
			break;
		}
	} while (isUsingProgram);

	outputFile.close();

	_CrtDumpMemoryLeaks();
	return 0;
}

template <class ObjectType>
void writeOutput(std::ofstream *outfile, ObjectType output)
{
	std::cout << output;
	*outfile << output ;
}


int takeIntegerInput(std::ofstream *outfile, int min, int max)
{
	int chosen = 0;
	bool properNumber = false;
	writeOutput(outfile, "\n");
	do
	{
		writeOutput(outfile, "Enter a valid integer: ");
		std::string input = "";
		std::getline(std::cin, input);
		*outfile << input << "\n";
		try {
			chosen = std::stoi(input);
			properNumber = true;
		}
		catch (...)
		{
			properNumber = false;
		}
	} while (!properNumber && (chosen <= min || chosen > max));
	system("CLS");
	return chosen;
}

int takeIntegerInput(std::ofstream *outfile)
{
	return takeIntegerInput(outfile, -2147483647, 2147483647); // max range
}

double takeDoubleInput(std::ofstream *outfile)
{
	double chosen = 0;
	bool properNumber = false;
	writeOutput(outfile, "\n");
	do
	{
		writeOutput(outfile, "Enter a valid double: ");
		std::string input = "";
		std::getline(std::cin, input);
		*outfile << input << "\n";
		try {
			chosen = std::stod(input);
			properNumber = true;
		}
		catch (...)
		{
			properNumber = false;
		}
	} while (!properNumber);
	system("CLS");
	return chosen;
}

char takeCharInput(std::ofstream *outfile)
{
	char chosen = '0';
	bool properChar = false;
	writeOutput(outfile, "\n");
	do
	{
		writeOutput(outfile, "Enter a valid char: ");
		std::string input = "";
		std::getline(std::cin, input);
		*outfile << input << "\n";
		if (input.length() == 1)
		{
			chosen = input.at(0);
			properChar = true;
		}
	} while (!properChar);
	system("CLS");
	return chosen;
}
std::string takeStringInput(std::ofstream *outfile)
{
	std::string chosen = "";
	bool properString = false;
	writeOutput(outfile, "\n");
	do
	{
		writeOutput(outfile, "Enter a valid string: ");
		std::string input = "";
		std::getline(std::cin, input);
		*outfile << input << "\n";
		if (input.length() != 0)
		{
			chosen = input;
			properString = true;
		}
	} while (!properString);
	system("CLS");
	return chosen;
}

template <class ObjectType>
void sortingArray(std::ofstream *outfile, Array<ObjectType> *array)
{
	writeOutput(outfile, "Now your array will be sorted with \n");
	writeOutput(outfile, "Insertion sort, quick sort, and merge sort\n");
	writeOutput(outfile, "Your original array: \n");
	
	for (int i = 0; i < (*array).getLength(); i++)
	{
		writeOutput(outfile, (*array)[i] );
		writeOutput(outfile, " ");
	}
	writeOutput(outfile, "\n\n");

	
	writeOutput(outfile, "Insertion sort of your array:\n");
	Array<ObjectType> copyOne = Array<ObjectType>(array->getLength());
	copyArray(&copyOne, array);
	insertionSort(&copyOne, copyOne.getLength() , outfile);
	writeOutput(outfile, "\n");

	writeOutput(outfile, "Quick sort of your array:\n"); 
	Array<ObjectType> copyTwo = Array<ObjectType>(array->getLength());
	copyArray(&copyTwo, array);
	quickSort(&copyTwo, 0, copyTwo.getLength() - 1, outfile);
	writeOutput(outfile, "\n");

	writeOutput(outfile, "Merge sort of your array:\n");
	Array<ObjectType> copyThree = Array<ObjectType>(array->getLength());
	copyArray(&copyThree, array);
	mergeSort(&copyThree, 0, copyTwo.getLength() - 1, outfile);
	writeOutput(outfile, "\n");

	writeOutput(outfile, "Press any key to continue...");
	std::cin.get();
	system("CLS");
}

template <class ObjectType>
void copyArray(Array<ObjectType> *copy, Array<ObjectType> *array)
{
	for (int ind = 0; ind < array->getLength(); ind++)
	{
		(*copy)[ind] = (*array)[ind];
	}
}

template <class ObjectType>
void insertionSort(Array<ObjectType> *array, int length, std::ofstream *outfile)
{
	int position, swapTarget;
	ObjectType key;
	for (position = 1; position < length; position++)
	{
		
		key = (*array)[position];
		swapTarget = position - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (swapTarget >= 0 && (*array)[swapTarget] <= key)
		{
			(*array)[swapTarget + 1] = (*array)[swapTarget];
			swapTarget--;
		}
		(*array)[swapTarget + 1] = key;

		writeOutput(outfile, "Most recent element considered: Element at position: " + std::to_string(position + 1) + "\n");
		for (int i = 0; i < (*array).getLength(); i++)
		{
			writeOutput(outfile, (*array)[i]);
			writeOutput(outfile, " ");
		}
		writeOutput(outfile, "\n");
	}
}

template <class ObjectType>
void quickSort(Array<ObjectType> *copy, int start, int end, std::ofstream *outfile)
{
	if (end <= start) return;
	int pivotInd = start - 1;
	ObjectType pivot = (*copy)[end];
	for (int j = start; j <= end; j++) {
		if ((*copy)[j] > pivot) {
			pivotInd++;
			ObjectType temp = (*copy)[pivotInd];
			(*copy)[pivotInd] = (*copy)[j];
			(*copy)[j] = temp;
		}
	}
	pivotInd++;
	ObjectType temp = (*copy)[pivotInd];
	(*copy)[pivotInd] = (*copy)[end];
	(*copy)[end] = temp;

	
	writeOutput(outfile, "Item number " + std::to_string(pivotInd + 1) + " (");
	writeOutput(outfile, (*copy)[pivotInd]);
	writeOutput(outfile, ") is now in the correct position.\n");
	for (int i = 0; i < (*copy).getLength(); i++) {
		writeOutput(outfile, (*copy)[i] );
		writeOutput(outfile, " ");
	}
	writeOutput(outfile, "\n");

	quickSort(copy, start, pivotInd - 1, outfile);
	quickSort(copy, pivotInd + 1, end, outfile);
}

template <class ObjectType>
void mergeSort(Array<ObjectType> *copy, int start, int end, std::ofstream *outfile)
{
	if (start >= end) {
		return;
	}
	int midpoint = start + (end - start) / 2;
	mergeSort(copy, start, midpoint, outfile);
	mergeSort(copy, midpoint + 1, end, outfile);

	merge(copy, start, midpoint, end, outfile);
}

template <class ObjectType>
void merge(Array<ObjectType> *copy, int start, int midpoint, int right, std::ofstream *outfile)
{
	int i, j, k;
	int n1 = midpoint - start + 1;
	int n2 = right - midpoint;

	Array<ObjectType> Left = Array<ObjectType>(n1);
	Array<ObjectType> Right = Array<ObjectType>(n2);

	/* Copy data to temp arrays Left[] and Right[] */
	for (i = 0; i < n1; i++)
		Left[i] = (*copy)[start + i];
	for (j = 0; j < n2; j++)
		Right[j] = (*copy)[midpoint + 1 + j];

	/* Merge the temp arrays back into copy[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = start; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (Left[i] > Right[j])
		{
			(*copy)[k] = Left[i];
			i++;
		}
		else
		{
			(*copy)[k] = Right[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of Left[]*/
	while (i < n1)
	{
		(*copy)[k] = Left[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of Right[] */
	while (j < n2)
	{
		(*copy)[k] = Right[j];
		j++;
		k++;
	}

	writeOutput(outfile, "Results of most recent merge: ");
	for (int i = 0; i < copy->getLength(); i++)
	{
		writeOutput(outfile, (*copy)[i]);
		writeOutput(outfile, " ");

	}
	writeOutput(outfile, "\n");
}
