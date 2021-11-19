#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "controller.h"
using namespace std;

// function check for valid input
bool is_valid_data(string str) {
	bool result = false;
	//variable count the dot 
	int dot_count = 0;

	for (int i = 0; i < str.length(); i++) {
		//check if all chars are not number and dot
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
			return result;
		}
		
		//check for dot
		if (str[i] == '.') {
			dot_count++;
			//check if dot appears > 1 time
			if (dot_count > 1) {
				return result;
			}
		}
	}
	result = true;
	return result;
}

void read_csvFile(char* fileName, myArray& col1, myArray& col2) {
	ifstream fin;
	fin.open(fileName, ios::in);
	if (!fin) {
		cout << "Cannot open File!\n";
	}
	int i = 0;
	double temp1, temp2;
	while (fin.good()) {
		string line1;
		string line2;
		getline(fin, line1, ',');
		getline(fin, line2, '\n');
		//check valid input
		//if not, continue to next line
		if (!is_valid_data(line1) || !is_valid_data(line2)) {
			continue;
		}
		stringstream s1(line1);
		stringstream s2(line2);

		while (s1 >> temp1 && s2 >> temp2) {
				col1.add(temp1);
				col2.add(temp2);
		}
	}
}