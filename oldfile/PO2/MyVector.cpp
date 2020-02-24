#pragma once
#include <iostream>

using namespace std;

template <typename T>
class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size = 10);
	void pushBack(T item);
	void pushBack(int *, int size);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	// Implementation of << operator.  This function must return a 
	// cout statement it would print the entire vector without a newline.
	friend ostream& operator<<(ostream& stream, const myVector<T>& v)
	{
		for (int i = 0; i < v.index; i++)
		{
			stream << v.vPtr[i] << " ";
		}
		return stream;
	}

	friend myVector& operator+(const myVector& left, const myVector& right)
	{
		myVector result;
		result = left;
		for (int i = 0; i < result.index; i++)
		{
			result.vPtr[i] += right.vPtr[i];
		}
		return result;
	}

	myVector& operator=(const myVector& other)
	{
		maxSize = other.maxSize;
		minSize = other.minSize;
		index = other.index;
		vPtr = new T[maxSize];
		for (int i = 0; i < index; i++)
		{
			vPtr[i] = other.vPtr[i];
		}
		return *this;
	}

};

/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
template <typename T>
myVector<T>::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new T[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void
* @return void
*/
template <typename T>
void myVector<T>::print() {
	for (int i = 0; i < index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
template <typename T>
void myVector<T>::pushBack(T item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

/**
* Function popBack
*   Returns value from vector
* @param none
* @return {int} : last item on vector
*/
template <typename T>
int myVector<T>::popBack() {

	index--;

	if (index < 0) {
		//dammit
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
template <typename T>
int* myVector<T>::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}

template <typename T>
int* myVector<T>::resize(int size) {

	return _resize(size);

}

template <typename T>
int* myVector<T>::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	int* vBigger = new int[newSize];

	//copy everything over
	for (int i = 0; i < index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
template <typename T>
double myVector<T>::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
template <typename T>
int myVector<T>::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
template <typename T>
void myVector<T>::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
template <typename T>
int myVector<T>::vSize() {
	return maxSize;
}
