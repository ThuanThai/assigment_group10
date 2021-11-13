#include "iofile.h"
#include "controller.h"

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Wrong compiling method!!!\n" << "Please compile as follow: assignment1_group10.exe <filename>.csv" << endl;
	}
	
	myArray col1, col2;
	// read csvFile then store the value into the vector
	read_csvFile(argv[1], col1, col2);
	col1.shrinksize(), col2.shrinksize();
	double mean1 = col1.getMean();
	double mean2 = col2.getMean();
	int size = col1.getSize();

	double covariance = col2.findcovariance(col1);
	double Pearson = covariance / (col1.getStandardDeviation() * col2.getStandardDeviation());

	//Descriptive Statistics
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
		
	//Inferential Statistics
	cout << "covariance: " << covariance << endl;
	cout << "pearson: " << getPearson(covariance, col1, col2) << endl;
	return 0;
}