#pragma once
#include <iostream>
#include <random>
#define output std::cout

template <class ObjectType>
class Array
{
private:
	int length;
	ObjectType *objectArray;
	ObjectType* workArray;

	void copyArr(ObjectType* toCopy, int start, int end, ObjectType* destination) {
		for (int i = start; i <= end; i++) {
			destination[i - start] = toCopy[i];
		}
	}

	void mergeSort(ObjectType* workarr, int start, int end, ObjectType* ot) {
		if (end - start == 1) {
			return;
		}
		int midpoint = (start + end) / 2;
		mergeSort(ot, start, midpoint, workarr);
		mergeSort(ot, midpoint, end, workarr);
		merge(workarr, start, midpoint, end, ot);
	}

	void merge(ObjectType* arr1, int start, int mid, int end, ObjectType* arr2) {
		int i = start, j = mid, k = start;
		while (i < mid && j < end) {
			if (arr1[i] > arr1[j]) {
				arr2[k] = arr1[i];
				i++;
				k++;
			}
			else {
				arr2[k] = arr1[j];
				j++;
				k++;
			}
		}
		while (i < mid) {
			arr2[k] = arr1[i];
			i++;
			k++;
		}
		while (j < end) {
			arr2[k] = arr1[j];
			j++;
			k++;
		}

		mergeSortPrint(arr2, end);
	}

	void mergeSortPrint(ObjectType* arr, int size) {
		output << "Results of most recent merge: ";
		for (int i = 0; i < size; i++) {
			output << arr[i] << " ";
		}
		output << std::endl;
	}

	int divide(int start, int end) {
		ObjectType pivot = objectArray[end];
		int i = start - 1;
		for (int j = start; j < end; j++){
			if (objectArray[j] > pivot) {
				i++;
				ObjectType temp = objectArray[i];
				objectArray[i] = objectArray[j];
				objectArray[j] = temp;
			}
		}
		i++;
		ObjectType temp = objectArray[i];
		objectArray[i] = objectArray[end];
		objectArray[end] = temp;
		return i;
	}

	void quicksort(int start, int end) {
		if (end <= start) return;
		int pivot = divide(start, end);
		quickSortPrint(pivot);
		quicksort(start, pivot - 1);
		quicksort(pivot + 1, end);
	}

	void quickSortPrint(int p) {
		output << "Item number " << p + 1 << " (" << objectArray[p] << ") " << "is now in the correct position." << std::endl;
		for (int i = 0; i < length; i++) {
			output << objectArray[i] << " ";
		}
		output << std::endl;
	}

	void insertionSortPrint(int pos) {
		output << "Most recent element considered: Element " << pos + 1 << " (" << objectArray[pos] << "). It and all elements to its left are in order." << std::endl;
		for (int i = 0; i < length; i++) {
			output << objectArray[i] << " ";
		}
		output << std::endl;
	}

	void insertionSort(int lastElem) {
		if (lastElem == 0) return;
		insertionSort(lastElem - 1);
		ObjectType tempOT = objectArray[lastElem];
		int position = lastElem - 1;
		while (position >= 0 && objectArray[position] < tempOT) {
			objectArray[position + 1] = objectArray[position];
			position--;
		}
		objectArray[position + 1] = tempOT;
		insertionSortPrint(position + 1);
	}

public:

	Array(int setLength)
	{
		length = setLength;
		objectArray = new ObjectType[setLength];
		workArray = new ObjectType[setLength];
	}
	~Array()
	{
		delete[]objectArray;
		delete[]workArray;
	}

	ObjectType &get(int get)
	{
		return *(objectArray + get);
	}
	void set(int set, ObjectType data)
	{
		*(objectArray + set) = data;
	}
	int getLength()
	{
		return length;
	}

	ObjectType &operator[] (int x)
	{
		return get(x);
	}

	void mergeSort() {
		copyArr(objectArray, 0, length - 1, workArray);
		mergeSort(workArray, 0, length, objectArray);
	}

	void quicksort() {
		quicksort(0, length - 1);
	}

	void insertionSort() {
		insertionSort(length - 1);
	}

	void shuffle() {
		int rand1, rand2;
		output << "Shuffling..." << std::endl;
		for (int i = 0; i < 100; i++) {
			//Yes I could seed the randomness but the point is to shuffle not make it truly random
			rand1 = rand() % length;
			rand2 = rand() % length;
			ObjectType temp = objectArray[rand1];
			objectArray[rand1] = objectArray[rand2];
			objectArray[rand2] = temp;
		}
		output << "Result of shuffle: ";
		for (int i = 0; i < length; i++) {
			output << objectArray[i] << " ";
		}
		output << std::endl;

	}
};
