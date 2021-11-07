#pragma once
#include <iostream>
using namespace std;

class myArray {
private:
	double* arr;
	int count;
	int size;

public:
	int getSize() { return count; };
	double* getArray() { return arr; };
	myArray();
	void add(double val);
	void growsize();
	void shrinksize();
	void print();

};

myArray::myArray() {
	arr = new double[1];
	int size = 1;
	int count = 0;
}

void myArray::add(double val) {
	if (count == size)
		growsize();
	arr[count] = val;
	count++;
}

void myArray::growsize() {
	double* temp = new double[size + 100];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size += 100;
}

void myArray::shrinksize() {
	double* temp = NULL;
	if (count > 0) {
		temp = new double[count];
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