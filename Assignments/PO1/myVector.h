/**
*  Course: CMPS 2143 - OOP
*  Assignment: P01
*  Purpose: Simulate the Vector class by pushing and popping values,
*  then printing size and vector.
*
*  @author Ponyduelist003
*  @version 1.1 09/03/18
*/
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class myVector {
private:
	int* theVector;
	int currentSize;
	int initialSize;
	int maxSize;
public:
	myVector(int size);
	void print();
	int size();
	double percentFull();
	void push_back(int value);
	int pop_back();
};
