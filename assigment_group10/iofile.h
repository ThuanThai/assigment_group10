#pragma once
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;


void read_csvFile(int col1[], int col2[], int& length) {
	ifstream fin;
	fin.open("data1.csv", ios::in);
	if (!fin) {
		cout << "Cannot open File!\n";
	}
	int i = 0;
	string temp1, temp2;
	while (fin.good()) {
		string line1;
		string line2;
		getline(fin, line1, ',');
		getline(fin, line2, '\n');
		stringstream s1(line1);
		stringstream s2(line2);

		while (getline(s1, temp1, ',') && getline(s2, temp2, '\n')) {
			if (!isalpha(temp1[0]) || !isalpha(temp2[0])) {
				int num1 = stoi(temp1);
				int num2 = stoi(temp2);
				col1[i] = num1;
				col2[i] = num2;
				i++;
			}
		}
	}
	length = i;
}