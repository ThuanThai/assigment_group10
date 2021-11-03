#include "handle.h"


int main(int argc, char* argv[]) {

	if (argc != 2 || !contain(".csv", argv[1])) {
		cout << "Wrong compiling method!!!\n" << "Please compile as follow: assignment1_group10.exe <filename>.csv" << endl;
	}
	
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