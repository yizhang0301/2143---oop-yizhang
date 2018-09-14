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
