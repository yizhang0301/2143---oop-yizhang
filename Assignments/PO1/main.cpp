/**
     *  Course: CMPS 2143 - OOP
     *
     *  Purpose: ArrayVectorClass
     * 
     *  @author @author Terry Griffin ; YI ZHANG
     *  @ 9/14/18 
     */
#include <iostream>
#include <vector>
#include <array>
#include "myVector.h"

using namespace std;

int main() {
	myVector v(10);
	int x = v.pop_back();
	v.push_back(13);
	v.push_back(31);
	v.push_back(73);
	v.print();
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << v.size() << "\n";
	for (int i = 0; i < 998; i++) {
		x = v.pop_back();
	}
	cout << v.size() << "\n";
	v.print();
	return 0;

