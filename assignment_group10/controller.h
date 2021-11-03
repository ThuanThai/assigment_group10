#pragma once
#include <iostream>
using namespace std;

class myArray {
private:
	int* arr;
	int count;
	int size;

public:
	int getSize() { return size; };
	int* getArray() { return arr; };
	myArray();
	void add(int val);
	void growsize();
	void shrinksize();
	void print();
	
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
	int* temp = new int[size + 100];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size += 100;
}

void myArray::shrinksize() {
	int* temp = NULL;
	if (count > 0) {
		temp = new int[count];
		for (int i = 0; i < count; i++) {
			temp[i] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	size = count;
}

void myArray::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}