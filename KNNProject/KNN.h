#ifndef KNN_H
#define KNN_H
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cmath>
#include <iomanip>
#include "Point.h"
#include "Graph.h"
using namespace std;

class KNN
{
	friend ostream &operator <<(ostream&, const KNN&);
public:
	KNN(int k=3);
	~KNN();
	void createSamplesPoint();
	void createTestingPoint();
	void setK(int);
	int getK() const;
	vector<Point> getSamplesPoint() const;
	vector<Point> getTestingPoint() const;
	void showGraph();
	void printData();
	void KNNRun();
	void classifyAPoint(vector<Point> a, vector<Point> b);
private:
	vector<Point> testingPoint;
	vector<Point> samples;
	int K;
};

#endif