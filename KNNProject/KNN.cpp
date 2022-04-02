#include "KNN.h"
typedef set<pair<double, double> > Mid;

// constructor set k values , create samples and testing point.
KNN::KNN(int k)
{
	setK(k);
	createSamplesPoint();
	createTestingPoint();
}

KNN::~KNN()
{
}
// Used to sort an vector of points' distance  
bool comparison(Point a, Point b)
{
	return (a.getDistance() < b.getDistance());
}
// Used in the count_if function that count the category IDs in the specified range to store
bool catIs_1(Point c) 
{ 
	return (c.getCatID() == 0);
}
bool catIs_2(Point c)
{
	return (c.getCatID() == 1);
}
bool catIs_3(Point c)
{
	return (c.getCatID() == 2);
}
// Function to set the K 
void KNN::setK(int k)
{
	string message = "ERROR ! K can not be negative";
	try
	{
		K = k;
		if (K<0)
		{
			throw message;
		}

	}
	catch (string x)
	{

		cout << x << endl;
		cout << " K = 3 " << endl;
		K = 3;
	}

}
//I created the examples in two different ways.
//In both methods, randomly, but the part in the comment line prevents conflicts by using set.
void KNN::createSamplesPoint()
{
	//create samples point 
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		Point point(i, (rand() % 11 - 5), (rand() % 11 - 5));
		if (i < 10) {
			point.setCatID(0);
		}
		else if (10 <= i && i < 20) {
			point.setCatID(1);
		}
		else {
			point.setCatID(2);
		}
		samples.push_back(point);
	}
	/*
	Mid set;
	int i = 0;
	while (set.size() < 30) {
		pair<double, double> temp((rand() % 11 - 5), (rand() % 11 - 5));
		set.insert(Mid::value_type(temp));
	}
	for (Mid::const_iterator it = set.begin(); it != set.end(); ++it)
	{
		Point point(i,it->first, it->second);
		if (i < 10) {
			point.setCatID(0);
			samples.push_back(point);
		}
		else if (10 <= i && i < 20) {
			point.setCatID(1);
			samples.push_back(point);
		}
		else if(20<=i && i<30) {
			point.setCatID(2);
			samples.push_back(point);
		}
		i++;
	}
	*/
}
// Create Testing Point
void KNN::createTestingPoint()
{
	for (int i = 30; i < 40; i++)
	{
		Point point(i, (rand() % 11 - 5), (rand() % 11 - 5));
		testingPoint.push_back(point);
	}
}
// Function to retrieve K
int KNN::getK() const
{
	return K;
}
// function to retrieve samples vector
vector<Point> KNN::getSamplesPoint() const
{
	return samples;
}
// function to retrieve testingPoint vector
vector<Point> KNN::getTestingPoint() const
{
	return testingPoint;
}
// Print Samples Point and testing point
void KNN::printData()
{
	cout << "After the k-NN algorithm" << endl;
	cout << "Training Data";
	cout << "Index\t\t" << " Features:\t\t" << "Catagory" << endl;
	for (int i = 0; i < getSamplesPoint().size(); i++)
	{
		cout << getSamplesPoint()[i].getIndex() << "\t\t\t\t" << " X = " << setw(2) << getSamplesPoint()[i].getFeature(0)
			<< " Y = " <<setw(2) << getSamplesPoint()[i].getFeature(1) << "\t\t   " << getSamplesPoint()[i].getCatID() << endl;
	}
	cout << "\n";
	for (int i = 0; i < getTestingPoint().size(); i++)
	{
		cout << getTestingPoint()[i].getIndex() << "\t\t\t\t" << " X = " <<setw(2) << getTestingPoint()[i].getFeature(0)
			<< " Y = " <<setw(2) << getTestingPoint()[i].getFeature(1) << "\t\t   " << getTestingPoint()[i].getCatID() << endl;
	}
}
//  Run the KNN algorithm
void KNN::KNNRun()
{
	classifyAPoint(getSamplesPoint(), getTestingPoint());
}
// show the Graph
void KNN::showGraph()
{
	Graph g1;
	g1.printGraph(getSamplesPoint(), getTestingPoint());
}
// This function finds classification of points using  k nearest neighbour algorithm.
// It assumes only two features and three category
void KNN::classifyAPoint(vector<Point> a, vector<Point> b)
{
	double d=0;
	vector<int> freq;
	for(int i= 0;  i< b.size(); i++)
	{
		freq.clear();
		for (int j = 0; j < a.size(); j++)
		{
			d = pow(((a[j].getFeature(0)) - (b[i].getFeature(0))), 2) +
				pow(((a[j].getFeature(1)) - (b[i].getFeature(1))), 2);
			d = sqrt(d);
			a[j].setDistance(d);
		}
		sort(a.begin(), a.end(), comparison);

		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_1));
		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_2));
		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_3));
		if (!(freq[0] == freq[1] && freq[0] == freq[2])) {
			testingPoint[i].setCatID(max_element(freq.begin(), freq.end()) - freq.begin());
		}
		else {
			testingPoint[0].setCatID(a[0].getCatID());
		}
	}
}
