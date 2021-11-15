#include "iofile.h"
#include "controller.h"

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
	col1.findPearson(col2);
	col1.findLinearRegression(col2);

	cout << "sum: " << col1.getSum() << endl;
	cout << "max: " << col1.getMax() << endl;
	cout << "mean: " << col1.getMean() << endl;
	cout << "mean: " << col2.getMean() << endl;
	cout << "median: " << col2.getMedian() << endl;
	cout << "mode: " << col1.getMode() << endl;
	cout << "variance: " << col1.getVariance() << endl;
	cout << "deviation: " << col1.getStandardDeviation() << endl;
	cout << "Third Quartile: " << col1.getThirdQuartile() << endl;
	cout << "skewness: " << col1.getSkewness() << endl;
	cout << "kurtosis: " << col1.getKurtosis() << endl;
	cout << "covariance: " << col1.getCovariance() << endl;
	cout << "Pearson: " << col1.getPearson() << endl;
	cout << "Linear Regression: " << col1.getLinearRegression() << endl;
	return 0;
}