#pragma once
#include "iofile.h"

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

void quickSort(double arr[], int low, int high) {
	if (low < high) {
		int n = partition(arr, low, high);
		quickSort(arr, n + 1, high);
		quickSort(arr, low, n - 1);
	}
}