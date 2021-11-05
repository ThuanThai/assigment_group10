#pragma once
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
#include "controller.h"
using namespace std;


bool contain(const string& word, const string& sentence) {
	return sentence.find(word)    // this returns the index of the first instance
								  // word
		!= string::npos;  // which will take this value if it's not found
}

bool is_double(string digit) {
	int dot_counter = 0;
	if (strlen(digit.c_str()) < 0 || strlen(digit.c_str()) > 15)
		return false;
	int i = 0;
	if (digit[i] == '+' || digit[i] == '-') {
		i++;
	}
	while (digit[i] != '\0') {
		if (digit[i] == '.') {
			dot_counter++;
			if (dot_counter > 1) return false;
		}
		else if (digit[i] < '1' || digit[i] > '9')
			return false;
		i++;
	}
	return true;
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
		stringstream s1(line1);
		stringstream s2(line2);
		
		while (s1 >> temp1) {
			col1.add(temp1);
		}
		while (s2 >> temp2) {
			col2.add(temp2);
		}
	}

}