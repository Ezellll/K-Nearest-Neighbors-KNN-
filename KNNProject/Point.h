#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <vector>
using namespace std;
class Point
{
public:
	Point(int,int,int);
	~Point();
	void setCatID(int);
	void setFeature(int, int);
	void setIndex(int);
	void setDistance(double);

	double getDistance() const;
	int getCatID() const;
	double getFeature(int) const;
	int getIndex() const;
private:
	vector<double>feature;
	int index;
	int cat_ID;
	double distance;
};

#endif