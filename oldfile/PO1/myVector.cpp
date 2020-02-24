#include <iostream>
#include "myVector.h"

using namespace std;

myVector::myVector(int size) {
	currentSize = 0;
	initialSize = size;
	maxSize = initialSize;
	theVector = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		theVector[i] = 0;
	}
}

void myVector::print() {
	for (int i = 0; i < currentSize; i++) {
		cout << theVector[i] << " ";
	}
	cout << "\n";
}

int myVector::size() {
	return currentSize;
}

double myVector::percentFull() {
	return (double)currentSize / maxSize;
}

void myVector::push_back(int value) {
	theVector[currentSize] = value;
	currentSize++;

	if (percentFull() >= 1) {
		int newSize = maxSize * 1.5;
		int* temp;
		temp = new int[newSize];
		for (int i = 0; i < maxSize; i++) {
			temp[i] = theVector[i];
		}
		for (int i = maxSize; i < newSize; i++) {
			temp[i] = 0;
		}
		maxSize = newSize;
		int* temp2 = theVector;
		theVector = temp;
		delete[] temp2;
	}
}

int myVector::pop_back() {
	if (currentSize == 0) {
		cout << "false\n";
		return 0;
	}

	currentSize--;
	int value = theVector[currentSize];

	if (percentFull() <= 0.4) {
		int newSize = maxSize * 0.5;
		if (newSize < initialSize) {
			newSize = initialSize;
		}
		int* temp;
		temp = new int[newSize];
		for (int i = 0; i < newSize; i++) {
			temp[i] = theVector[i];
		}
		maxSize = newSize;
		int* temp2 = theVector;
		theVector = temp;
		delete[] temp2;
	}
	return value;
}
