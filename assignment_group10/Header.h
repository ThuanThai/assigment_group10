#pragma once
#include <iostream>
using namespace std;

class myArray {
private:
	int* arr;
	int count;
	int size;

public:
	myArray();
	void add(int val);
	void growsize();
	void print();
	int getSize() { return size; };
};

myArray::myArray() {
	arr = new int[1];
	int size = 1;
	int count = 0;
}

void myArray::add(int val) {
	if (count == size)
		growsize();
	arr[count] = val;
	count++;
}

void myArray::growsize() {
	int* temp = new int[size * 2];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	arr = temp;
	size *= 2;
}

void myArray::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}