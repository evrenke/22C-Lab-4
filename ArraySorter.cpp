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

template <class ObjectType>
void sortingArray(Array<ObjectType> *array);

int takeIntegerInput(int min, int max);
int takeIntegerInput();// max range

double takeDoubleInput();

int main()
{
	bool isUsingProgram = true;;
	int inputNumber = 0;
	do
	{
		std::cout << "Hello! What kind of array would you like to make?" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "1) Integer array" << std::endl;
		std::cout << "2) Double array" << std::endl;
		std::cout << "3) Character array" << std::endl;
		std::cout << "4) String array" << std::endl;
		std::cout << "5) Exit" << std::endl;
		inputNumber = takeIntegerInput(0, 5);
		switch (inputNumber)
		{
		case 1://Integer array made
		{
			std::cout << "How long you want your integer array to be? (Maximum of 32)" << std::endl;
			std::cout << "(Enter zero to return)" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			inputNumber = takeIntegerInput(0, 32);
			Array<int> intArray = Array<int>(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					std::cout << "Enter the integer at the " << ind + 1 << "st place in your array: " << std::endl;
					break;
				case 1:
					std::cout << "Enter the integer at the " << ind + 1 << "nd place in your array: " << std::endl;
					break;
				case 2:
					std::cout << "Enter the integer at the " << ind + 1 << "rd place in your array: " << std::endl;
					break;
				default:
					std::cout << "Enter the integer at the " << ind + 1 << "th place in your array: " << std::endl;
					break;
				}
				int number = takeIntegerInput();
				intArray[ind] = number;
			}
			sortingArray(&intArray);
		}
		break;
		case 2://Double array made
		{
			std::cout << "How long you want your double array to be? (Maximum of 32)" << std::endl;
			std::cout << "(Enter zero to return)" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			inputNumber = takeIntegerInput(0, 32);
			Array<double> doubleArray = Array<double>(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					std::cout << "Enter the double at the " << ind + 1 << "st place in your array: " << std::endl;
					break;
				case 1:
					std::cout << "Enter the double at the " << ind + 1 << "nd place in your array: " << std::endl;
					break;
				case 2:
					std::cout << "Enter the double at the " << ind + 1 << "rd place in your array: " << std::endl;
					break;
				default:
					std::cout << "Enter the double at the " << ind + 1 << "th place in your array: " << std::endl;
					break;
				}
				double number = takeDoubleInput();
				doubleArray[ind] = number;
			}
			sortingArray(&doubleArray);
		}
		break;
		case 3://character array made
		{
			std::cout << "How long you want your character array to be? (Maximum of 32)" << std::endl;
			std::cout << "(Enter zero to return)" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			inputNumber = takeIntegerInput(0, 32);
			Array<char> charArray(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					std::cout << "Enter the character at the " << ind + 1 << "st place in your array: " << std::endl;
					break;
				case 1:
					std::cout << "Enter the character at the " << ind + 1 << "nd place in your array: " << std::endl;
					break;
				case 2:
					std::cout << "Enter the character at the " << ind + 1 << "rd place in your array: " << std::endl;
					break;
				default:
					std::cout << "Enter the character at the " << ind + 1 << "th place in your array: " << std::endl;
					break;
				}
				std::string charInput;
				std::getline(std::cin, charInput);
				char character = charInput.at(0);
				charArray[ind] = character;
				system("CLS");
			}
			sortingArray(&charArray);
		}
		break;
		case 4://string array made
		{
			std::cout << "How long you want your string array to be? (Maximum of 32)" << std::endl;
			std::cout << "(Enter zero to return)" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			inputNumber = takeIntegerInput(0, 32);
			Array<std::string> stringArray(inputNumber);
			for (int ind = 0; ind < inputNumber; ind++)
			{
				switch (ind)
				{
				case 0:
					std::cout << "Enter the string at the " << ind + 1 << "st place in your array: " << std::endl;
					break;
				case 1:
					std::cout << "Enter the string at the " << ind + 1 << "nd place in your array: " << std::endl;
					break;
				case 2:
					std::cout << "Enter the string at the " << ind + 1 << "rd place in your array: " << std::endl;
					break;
				default:
					std::cout << "Enter the string at the " << ind + 1 << "th place in your array: " << std::endl;
					break;
				}
				std::string stringInput;
				std::getline(std::cin, stringInput);
				stringArray[ind] = stringInput;
				system("CLS");
			}
			sortingArray(&stringArray);
		}
		break;
		case 5://exiting program
		{
			isUsingProgram = false;
			break;
		}
		default: {
			std::cout << "Error: Please input a valid number." << std::endl;
			break;
		}
		}
	} while (isUsingProgram);
	return 0;
}

int takeIntegerInput(int min, int max)
{
	int chosen = 0;
	bool properNumber = false;
	std::cout << std::endl;
	do
	{
		std::cout << "Enter a valid integer: ";
		std::string input = "";
		std::getline(std::cin, input);
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

int takeIntegerInput()
{
	return takeIntegerInput(-2147483647, 2147483647); // max range
}

double takeDoubleInput()
{
	double chosen = 0;
	bool properNumber = false;
	std::cout << std::endl;
	do
	{
		std::cout << "Enter a valid double: ";
		std::string input = "";
		std::getline(std::cin, input);
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

template <class ObjectType>
void sortingArray(Array<ObjectType> *array)
{
	std::cout << "Now your array will be sorted with " << std::endl;
	std::cout << "Insertion sort, quick sort, and merge sort" << std::endl;

	array->insertionSort();
	std::cout << "Insertion Sort Completed.\n";
	array->shuffle();
	array->quicksort();
	std::cout << "Quicksort completed\n";
	array->shuffle();
	array->mergeSort();
	std::cout << "Merge Sort Completed\n";
}