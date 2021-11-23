#pragma once
#include <iostream>
#include <math.h>
#include <sstream> 
#include "quicksort.h"
#include <iomanip>
#define LOW 0 // first index of array
#define UPSIZE 100 // used to grow size of array

using namespace std;

// create an object of an array
class myArray {
private:
	double* arr = 0; //pointer
	int count;
	int size;

	// variables storing statistics
	double sum = 0;
	double median = 0;
	double max = 0;
	double mode = 0;
	double mean = 0;
	double variance = 0;
	double standardDeviation = 0;
	double mad = 0;
	double thirdQuartile = 0;
	double skewness = 0;
	double kurtosis = 0;
	double covariance = 0;

public:
	myArray();
	int getSize() { return count; }; // function return number of elements
	double* getArray() { return arr; }; // function return an array
	void add(double val); // function adding one element to the array
	void growSize(); // function enlarging size of array
	void shrinkSize(); // funtion shrinking size of array
	void start(); // function doing the main task
	void print(); // funtion printing the data

	//getter
	double getSum();
	double getMedian();
	double getMode();
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
	void findMean();
	void findVariance();
	void findStandardDeviation();
	void findMode();
	void findMad();
	void findThirdQuartile();
	void findSkewness();
	void findKurtosis();
	friend void end(myArray col1, myArray col2);
	void findcovariance(myArray arr);
	double findPearson(myArray arr);
	string findLinearRegression(myArray arr);
};

// constructor
myArray::myArray() {
	// pointer to a dynamic array of type double
	// initial size = 1
	arr = new double[1];
	int size = 1;
	int count = 0;
}

// function adding one element to array
void myArray::add(double val) {
	if (count == size)
		growSize(); // enlarges size if number of element in the array reaches the size
	arr[count] = val;
	count++;
}

// function enlarging size of the array
void myArray::growSize() {
	// create a new pointer point to a new array with bigger size
	double* temp = new double[size + UPSIZE];
	// copy the elements from the old array to the new one
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr; // release old array memory
	arr = temp; // change the pointer
	size += 100;
}

// function shrinking size of the array
void myArray::shrinkSize() {
	double* temp = NULL;
	if (count > 0) {
		temp = new double[count]; // new array with size = number of elements
		for (int i = 0; i < count; i++) {
			temp[i] = arr[i]; // copy the elements from the old array to the new one
		}
	}
	delete[] arr; // release old array memory
	arr = temp; // change the pointer
	size = count;
}

// function doing the task
void myArray::start() {
	// sort the array
	quickSort(arr, LOW, size - 1);
	// find the descriptive statistic
	findMedian();
	findVariance();
	findStandardDeviation();
	findMode();
	findMad();
	findThirdQuartile();
	findSkewness();
	findKurtosis();
}

// function printing the array
void myArray::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

// CALCULATION FUNCTIONS (SETTER)
// find sum	
void myArray::findSum() {
	for (int i = 0; i < size; i++) {
		this->sum += arr[i];
	}
}


// find median
void myArray::findMedian() {
	this->median = (arr[(LOW + size - 1) / 2] + arr[(LOW + size) / 2]) / 2;
}

//find mean
void myArray::findMean() {
	mean = (double)sum / size; // mean = sum/size
}

// find variance
void myArray::findVariance() {
	double sqDiff = 0; //squared difference from the mean
	for (int i = 0; i < size; i++) {
		sqDiff += pow((arr[i] - mean), 2); // squared difference += (arr[i]-mean)^2
	}
	this->variance = sqDiff / (size - 1);
}

// find standard deviation
void myArray::findStandardDeviation() {
	standardDeviation = sqrt(variance); // variance^2 = standard deviation
}

// find mode
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
				this->mode = arr[i - 1];
			}

			//reset
			current_num = arr[i];
			current_count = 1;
		}
		else current_count++; //increase count if meeting the same number
	}
}

// find MAD
void myArray::findMad() {
	double sumDiff = 0; // sum difference from the mean
	for (int i = 0; i < size; i++) {
		sumDiff += abs((arr[i] - mean)); //calculate sum difference
	}
	this->mad = sumDiff / size;
}

// find third quartile (Q3)
void myArray::findThirdQuartile() {
	if (size % 2 == 0)	// if size is even
		thirdQuartile = (arr[(size / 2 + size - 1) / 2] + arr[(size / 2 + size) / 2]) / 2;
	else				// if size is odd
		thirdQuartile = (arr[(size / 2 + size) / 2] + arr[(size / 2 + size + 1) / 2]) / 2;
}

// find skewness
void myArray::findSkewness() {
	double sumDiff = 0.0F; // sum difference from the mean
	double coe = (double)size / (((double)size - 1) * ((double)size - 2)); //coefficient = size/((size-1)*(size-2))
	for (int i = 0; i < size; i++) {
		sumDiff += pow(arr[i] - mean, 3); //calculate sum difference
	}
	this->skewness = sumDiff * coe / pow(standardDeviation, 3);
}

// find kurtosis
void myArray::findKurtosis() {
	for (int i = 0; i < size; ++i) {
		kurtosis += pow((arr[i] - mean), 4.0); //calculate kurtosis
	}
	this->kurtosis /= double(size) * pow(variance, 2.0);
	this->kurtosis -= 3.0;
}

// GETTER
// get sum
double myArray::getSum() {
	return sum;
}

// get median
double myArray::getMedian() {
	return median;
}

// get mode
double myArray::getMode() {
	return mode;
}

// get median
double myArray::getMean() {
	return mean;
}

//get variance
double myArray::getVariance() {
	return variance;
}

//get standard deviation
double myArray::getStandardDeviation() {
	return standardDeviation;
}

//get MAD
double myArray::getMad() {
	return mad;
}

//get skewness
double myArray::getSkewness() {
	return skewness;
}

//get third quartile (Q3)
double myArray::getThirdQuartile() {
	return thirdQuartile;
}

// get kurtosis
double myArray::getKurtosis() {
	return kurtosis;
}

// get covariance
double myArray::getCovariance() {
	return covariance;
}

// FUNCTION CALCULATING INFERENTIAL STATISTICS
// find covariance of two data sets
void myArray::findCovariance(myArray arr1) {
	for (int i = 0; i < size; i++) {
		// sum of (x - x.Mean) * (y - y.Mean)
		covariance += (arr[i] - mean) * (arr1.getArray()[i] - arr1.getMean());
	}
	covariance /= size;
void end(myArray col1, myArray col2) {
	delete[] col1.getArray();
	delete[] col2.getArray();
}

// find Pearson coefficient of two data sets
double myArray::findPearson(myArray arr2) {
	// pearson = covariance / (x.standardDeviation * y.standardDeviation)
	double pearson = covariance / (standardDeviation * arr2.getStandardDeviation());
	return pearson;
}

// find linear regression of two data sets
string myArray::findLinearRegression(myArray arr) {
	double a;
	double b;
	stringstream temp;
	double pearson = findPearson(arr);
	// a = (pearson * y.standardDeviation) / x.standardDeviation
	a = (pearson * arr.getStandardDeviation()) / standardDeviation;
	// b = y.Mean - a * x.Mean
	b = arr.getMean() - (a * mean);
	// Linear regression: y = ax + b
	temp << setprecision(4) << fixed << a << "x" << " + " << b; // set number to 4 decimal points
	return temp.str();
}
