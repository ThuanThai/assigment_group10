#pragma once
#include "quicksort.h"
#include <unordered_map>
#include <math.h>
#define LOW 0

int findMedian(float arr[], int length) {
	if (length % 2 != 0) {
		return arr[length / 2];
	}
	else {
		return (arr[(length - 1) / 2] + arr[length / 2]) / 2;
	}
}

float findMax(float arr[], int length) {
	float max = arr[0];
	for (int i = 0; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double findMean(float arr[], int length) {
	float sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return (double) sum / length;
}

double find_variance(float arr[], int length) {
	double sqDiff = 0;
	int mean = findMean(arr, length);
	for (int i = 0; i < length; i++) {
		sqDiff += pow((arr[i] - mean), 2);
	}

	return sqDiff / (length - 1);
}

double standardDeviation(float arr[], int length) {
	return sqrt(find_variance(arr, length));
}

int findMode(float arr[], int length) {
	int max = findMax(arr, length);
	int size = max + 1;
	int* count = new int[size];
	for (int i = 0; i < size; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < length; i++) {
		//count[arr[i]]++;
	}

	int mode = 0, val = count[0];
	for (int i = 0; i < size; i++) {
		if (count[i] > val) {
			val = count[i];
			mode = i;
		}
	}
	return mode;
}

float find_mode_new(float arr[], int length) {
	// only work if the array already sorted
	
	// initialize 
	float mode = 0;
	int mode_count = 0;
	float current = 0;
	int current_count = 0;

	// loop through array
	for (int i = 0; i < length; i++) {

		//reset if meeting a new number
		if (arr[i] != current) {
			current = arr[i];
			current_count = 1;
		} else current_count++; //increase count if meeting the same number 

		//update mode and mode_count if the current number appears more frequently
		if (current_count > mode_count) {
			mode_count = current_count;
			mode = arr[i];
		}
		cout << arr[i] << " " << current_count << endl;
	}
	return mode;
}

void Menu(float col1[], float col2[], int length) {
	bool flag = true;
	int choice;

	while (flag) {
		system("cls");
		cout << "1. Find Median element for x and y\n";
		cout << "2. Find Mode\n";
		cout << "3. Find Variance and Standard Deviation\n";
		cout << "\tEnter the number\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{

			int medX = findMedian(col1, length);
			int medY = findMedian(col2, length);

			cout << "Median_X: " << medX << endl;
			cout << "Median_Y: " << medY << endl;
			system("pause");
		}
		break;

		case 2:
		{
			int x = findMode(col1, length);
			int y = findMode(col2, length);

			cout << "Mode_X: " << x << endl;
			cout << "Mode_Y: " << y << endl;
			system("pause");
		}
		break;

		case 3:
		{
			double x = find_variance(col1, length);
			double y = find_variance(col2, length);
			double x1 = standardDeviation(col1, length);
			double y1 = standardDeviation(col1, length);

			cout << x << " " << y << "\n" << x1 << " " << y1 << endl;
			system("pause");
			break;
		}

		case 0:
			delete[] col1;
			delete[] col2;
			flag = false;
			break;

		default:
			cout << "Wrong choice\n";
			system("pause");
			continue;
		}

	}
}