#include "iofile.h"
#include "controller.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Wrong compiling method!!!\n" << "Please compile as follow: assignment1_group10.exe <filename>.csv" << endl;
	}

	myArray col1, col2;
	read_csvFile(argv[1], col1, col2);
	col1.shrinksize(); col2.shrinksize();

	col1.findSum(); col2.findSum();
	col1.findMean(); col2.findMean();
	col1.findcovariance(col2);

	col1.start(); col2.start();

	cout << "\n\t\tDescriptive Statistics" << endl;
	cout << setprecision(4) << fixed << "median_x =  " << col1.getMedian() << "\t - median_y =  " << col2.getMedian() << endl;
	cout << setprecision(4) << fixed << "mode_x =  " << col1.getMode() << "\t - mode_y =  " << col2.getMode() << endl;
	cout << setprecision(4) << fixed << "var_x =  " << col1.getVariance() << "\t - var_y =  " << col2.getVariance() << endl;
	cout << setprecision(4) << fixed << "stdev_x =  " << col1.getStandardDeviation() << "\t - stdev_y =  " << col2.getStandardDeviation() << endl;
	cout << setprecision(4) << fixed << "mad_x =  " << col1.getMad() << "\t - mad_y =  " << col2.getMad() << endl;
	cout << setprecision(4) << fixed << "Q3_x =  " << col1.getThirdQuartile() << "\t\t - Q3_y =  " << col2.getThirdQuartile() << endl;
	cout << setprecision(4) << fixed << "Skew_x =  " << col1.getSkewness() << "\t - Skew_y =  " << col2.getSkewness() << endl;
	cout << setprecision(4) << fixed << "Kurt_x =  " << col1.getKurtosis() << "\t - Kurt_y =  " << col2.getKurtosis() << endl;

	cout << "\n\t\tInferential Statistics" << endl;
	cout << setprecision(4) << fixed << "cov(x_y) =  " << col1.getCovariance() << endl;
	cout << setprecision(4) << fixed << "r(x_y) =  " << col1.findPearson(col2) << endl;
	cout << "Linear Regression: " << col1.findLinearRegression(col2) << endl;
	end(col1, col2);
	cout << "\n\t\tASSIGNMENT 1 GROUP 10" << endl;
	cout << "\ts3877819, s3877819@rmit.edu.vn, Phong, Le" << endl;
	cout << "\ts3877798, s3877798@rmit.edu.vn, Anh, Nguyen" << endl;
	cout << "\ts3877024, s3877024@rmit.edu.vn, Thuan, Thai" << endl;
	cout << "\ts3761910, s3761910@rmit.edu.vn, Dat, Phan" << endl;

	delete[] col1.getArray();
	delete[] col2.getArray();
	return 0;
}