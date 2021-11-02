#include "handle.h"

int main() {
	int length;
	int* col1 = new int[50000];
	int* col2 = new int[50000];
	// read csvFile then store the value into the vector
	read_csvFile(col1, col2, length);

	int high1 = length - 1;
	int high2 = length - 1;
	//using quick sort to order the array
	quickSort(col1, LOW, high1);
	quickSort(col2, LOW, high2);
	//Call Menu Function
	Menu(col1, col2, length);
	return 0;
}