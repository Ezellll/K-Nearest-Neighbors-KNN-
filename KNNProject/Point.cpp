#include "Point.h"
// constructor set the index and feature vector
Point::Point(int index, int x, int y)
{
	setIndex(index);
	setFeature(x, y);
}

Point::~Point()
{
}
// function to set the category ID 
void Point::setCatID(int category)
{
	cat_ID = category;
}
// function to set the feature(x,y) vector
void Point::setFeature(int x, int y)
{
	feature.push_back(x);
	feature.push_back(y);
}
// function to set the index
void Point::setIndex(int a)
{
	index = a;
}
// function to set the distance
void Point::setDistance(double a)
{
	distance = a;
}
// function to retrieve the category ID 
int Point::getCatID() const
{
	return cat_ID;
}
// function to retrieve the category ID 
double Point::getFeature(int i) const
{
	return feature[i];
}
// function to retrieve the Index
int Point::getIndex() const
{
	return index;
}
// function to retrieve the distance
double Point::getDistance() const
{
	return distance;
}













