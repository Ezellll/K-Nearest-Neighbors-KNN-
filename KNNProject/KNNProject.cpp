#include <iostream>
#include "KNN.h"
using namespace std;

ostream& operator <<(ostream& output, const KNN& knn)
{
	output << "Training Data";
	output << "Index\t\t" << " Features:\t\t" << "Catagory" << endl;
	for (int i = 0; i < knn.getSamplesPoint().size(); i++)
	{
		output << knn.getSamplesPoint()[i].getIndex() << "\t\t\t\t" << " X = "<<setw(2) << knn.getSamplesPoint()[i].getFeature(0)
			<< " Y = " <<setw(2) << knn.getSamplesPoint()[i].getFeature(1) << "\t\t   " << knn.getSamplesPoint()[i].getCatID() << endl;
	}
	output << endl << "Testing Data";
	output << "Index\t\t" << " Features:\t\t" << endl;
	for (int i = 0; i < knn.getTestingPoint().size(); i++)
	{
		output << knn.getTestingPoint()[i].getIndex() << "\t\t\t\t" << " X = " <<setw(2) << knn.getTestingPoint()[i].getFeature(0)
			<< " Y = " <<setw(2) << knn.getTestingPoint()[i].getFeature(1) << endl;
	}
	cout << "\n\n\n";
	return output;
}
int main()
{
    int k;
    cout << "Enter the K : ";
	cin >> k;
	
    KNN knn(k);
	cout << knn;
    knn.KNNRun();
	knn.printData();
	knn.showGraph();
}
