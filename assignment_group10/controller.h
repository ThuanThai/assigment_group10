#pragma once
#include <iostream>
#include <math.h>
#define LOW 0

using namespace std;

class myArray {
private:
	double* arr;
	int count;
	int size;

	double sum;
	double median;
	double max;
	double mode;
	double mean;
	double variance;
	double standardDeviation;
	double mad;
	double thirdQuartile;
	double skewness;

public:
	int getSize() { return count; };
	double* getArray() { return arr; };
	myArray();
	void add(double val);
	void growsize();
	void shrinksize();
	void print();

	void quickSort(double arr[], int low, int high);

	//getter
	double getSum();
	double getMedian();
	double getMode();
	double getMax();
	double getMean();
	double getVariance();
	double getStandardDeviation();
	double getMad();
	double getThirdQuartile();
	double getSkewness();
	
	//setter
	void findSum();
	void findMedian();
	void findMax(double arr[], int length);
	void findMean(double arr[], int length);
	void find_variance(double arr[], int length);
	void find_standardDeviation(double arr[], int length);
	void findMode(double arr[], int length);
	void findMad(double arr[], int length);
	void findThirdQuartile();
	void findSkewness();
	
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

	int length = size - 1;
	quickSort(arr, LOW, length);
	findSum();
	findMedian();
	findMax(arr, length);
	findMean(arr, length);
	find_variance(arr, length);
	find_standardDeviation(arr, length);
	findMode(arr, length);
	findMad(arr, length);
	findThirdQuartile();
	findSkewness();
}

void myArray::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}


// calculation functions
void myArray::findSum() {
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
}

void myArray::findMedian() {
	median = (arr[(LOW + size - 1) / 2] + arr[(LOW + size) / 2]) / 2;
	/*
	if (length % 2 != 0) {
		median = arr[length / 2];
	}
	else {
		median = (arr[(length - 1) / 2] + arr[length / 2]) / 2;
	}
	*/
}

void myArray::findMax(double arr[], int length) {
	max = arr[length];
}

void myArray::findMean(double arr[], int length) {
	mean = (double)sum / length;
}

void myArray::find_variance(double arr[], int length) {
	double sqDiff = 0;
	for (int i = 0; i < length; i++) {
		sqDiff += pow((arr[i] - mean), 2);
	}
	variance = sqDiff / (length - 1);
}

void myArray::find_standardDeviation(double arr[], int length) {
	standardDeviation = sqrt(variance);
}

void myArray::findMode(double arr[], int length) {
	// only work if the array already sorted

	// initialize 
	int mode_count = 0.0;
	double current_num = 0.0;
	int current_count = 0.0;

	// loop through array
	for (int i = 0; i < length; i++) {

		//reset if meeting a new number
		if (arr[i] != current_num) {

			//update mode and mode_count if the current number appears more frequently
			if ((i != 0) && (current_count > mode_count)) {
				mode_count = current_count;
				mode = arr[i - 1];
			}

			//reset
			current_num = arr[i];
			current_count = 1;

		}
		else current_count++; //increase count if meeting the same number 
	}
}

void myArray::findMad(double arr[], int length) {
	double sumDiff = 0;
	for (int i = 0; i < length; i++) {
		sumDiff += abs((arr[i] - mean));
	}
	mad = sumDiff / length;
}

void myArray::findThirdQuartile() {
	if (size % 2 == 0) 
		thirdQuartile = (arr[(size/2 + size - 1) / 2] + arr[(size / 2 + size) / 2]) / 2;
	else 
		thirdQuartile = (arr[(size / 2 + size) / 2] + arr[(size / 2 + size + 1) / 2]) / 2;
}

void myArray::findSkewness() {
	double sumDiff = 0.0F;
	double coe = (double)size / (((double)size - 1) * ((double)size - 2));
	for (int i = 0; i < size; i++) {
		sumDiff += pow(arr[i] - mean, 3);
	}
	skewness = sumDiff * coe / pow(standardDeviation, 3);
	
}

//getter
double myArray::getSum() {
	return sum;
}

double myArray::getMedian() {
	return median;
}

double myArray::getMax() {
	return max;
}

double myArray::getMode() {
	return mode;
}

double myArray::getMean() {
	return mean;
}

double myArray::getVariance() {
	return variance;
}

double myArray::getStandardDeviation() {
	return standardDeviation;
}

double myArray::getMad() {
	return mad;
}

double myArray::getSkewness() {
	return skewness;
}

double myArray::getThirdQuartile() {
	return thirdQuartile;
}

//quick sort
void swap(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}

int partition(double arr[], int low, int high) {
	int pivot = arr[high];
	int right = high - 1;
	int left = low;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void myArray::quickSort(double arr[], int low, int high) {
	if (low < high) {
		int n = partition(arr, low, high);
		quickSort(arr, n + 1, high);
		quickSort(arr, low, n - 1);
	}
}