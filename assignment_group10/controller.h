#pragma once
#include <iostream>
#include <math.h>
#include "quicksort.h"
#include <iomanip>
#define LOW 0

using namespace std;

class myArray {
private:
	double* arr;
	int count;
	int size;

	double sum;
	double median = 0.0F;
	double max = 0.0F;
	double mode = 0.0F;
	double mean;
	double variance;
	double standardDeviation;
	double mad;
	double thirdQuartile;
	double skewness;
	double kurtosis;
	double covariance;

public:
	int getSize() { return count; };
	double* getArray() { return arr; };
	myArray();
	void add(double val);
	void growSize();
	void shrinkSize();
	void start();
	void print();

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
	double getKurtosis();
	double getCovariance();

	//setter
	void findSum();
	void findMedian();
	void findMax();
	void findMean();
	void findVariance();
	void findStandardDeviation();
	void findMode();
	void findMad();
	void findThirdQuartile();
	void findSkewness();
	void findKurtosis();
	void findCovariance(myArray arr);
	double findPearson(myArray arr);
	string findLinearRegression(myArray arr);
};

myArray::myArray() {
	arr = new double[1];
	int size = 1;
	int count = 0;
}

void myArray::add(double val) {
	if (count == size)
		growSize();
	arr[count] = val;
	count++;
}

void myArray::growSize() {
	double* temp = new double[size + 100];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size += 100;
}

void myArray::shrinkSize() {
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

void myArray::start() {
	quickSort(arr, LOW, size - 1);
	findMedian();
	findMax();
	findVariance();
	findStandardDeviation();
	findMode();
	findMad();
	findThirdQuartile();
	findSkewness();
	findKurtosis();
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
}

void myArray::findMax() {
	max = arr[size - 1];
}

void myArray::findMean() {
	mean = (double)sum / size;
}

void myArray::findVariance() {
	double sqDiff = 0;
	for (int i = 0; i < size; i++) {
		sqDiff += pow((arr[i] - mean), 2);
	}
	variance = sqDiff / (size - 1);
}

void myArray::findStandardDeviation() {
	standardDeviation = sqrt(variance);
}

void myArray::findMode() {
	// only work if the array already sorted

	// initialize
	int mode_count = 0;
	double current_num = 0.0;
	int current_count = 0;

	// loop through array
	for (int i = 0; i < size; i++) {
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

void myArray::findMad() {
	double sumDiff = 0;
	for (int i = 0; i < size; i++) {
		sumDiff += abs((arr[i] - mean));
	}
	mad = sumDiff / size;
}

void myArray::findThirdQuartile() {
	if (size % 2 == 0)
		thirdQuartile = (arr[(size / 2 + size - 1) / 2] + arr[(size / 2 + size) / 2]) / 2;
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

void myArray::findKurtosis() {
	for (int i = 0; i < size; ++i) {
		kurtosis += pow((arr[i] - mean), 4.0);
	}
	kurtosis /= double(size) * pow(variance, 2.0);
	kurtosis -= 3.0;
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

double myArray::getKurtosis() {
	return kurtosis;
}

double myArray::getCovariance() {
	return covariance;
}

void myArray::findCovariance(myArray arr1) {
	for (int i = 0; i < size; i++) {
		covariance += (arr[i] - mean) * (arr1.getArray()[i] - arr1.getMean());
	}

	covariance /= size;
}
double myArray::findPearson(myArray arr2) {
	double pearson = covariance / (standardDeviation * arr2.getStandardDeviation());
	return pearson;
}

string myArray::findLinearRegression(myArray arr) {
	double a;
	double b;
	stringstream temp;
	double pearson = findPearson(arr);

	a = (pearson * arr.getStandardDeviation()) / standardDeviation;
	b = arr.getMean() - (a * mean);

	temp << setprecision(4) << fixed << a << "x" << " + " << b;
	return temp.str();
}
