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
	
	
	cout << setprecision(5) << "sum: "  << col1.getSum() << endl;
	cout << setprecision(5) << "max: " << col1.getMax() << endl;
	cout << setprecision(5) << "mean: " << col1.getMean() << endl;
	cout << setprecision(5) << "mean: " << col2.getMean() << endl;
	cout << setprecision(5) << "median: " << col2.getMedian() << endl;
	cout << setprecision(5) << "mode: " << col1.getMode() << endl;
	cout << setprecision(5) << "variance: " << col1.getVariance() << endl;
	cout << setprecision(5) << "deviation: " << col1.getStandardDeviation() << endl;
	cout << setprecision(5) << "Third Quartile: " << col1.getThirdQuartile() << endl;
	cout << setprecision(5) << "skewness: " << col1.getSkewness() << endl;
	cout << setprecision(5) << "kurtosis: " << col1.getKurtosis() << endl;
	cout << setprecision(5) << "covariance: " << col1.getCovariance() << endl;
	cout << setprecision(2) << "Pearson: " << col1.findPearson(col2) << endl;
	cout << "Linear Regression: " << col1.findLinearRegression(col2) << endl;
	return 0;
}