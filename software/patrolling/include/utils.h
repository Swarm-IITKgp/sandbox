//General utility functions

#ifndef UTILS
#define UTILS

#include "opencv2/core/core.hpp"

using namespace cv;

inline bool IsValidPoint(int x, int y, int r, int c)
{
	//Checks if inside the grid - for corner cases
	if(x<0||y<0||x>=c||y>=r)
		return false;
	return true;
}

inline double EuclideanDist(Point p1, Point p2)
{
	//OpenCV norm is too clunky but you can use it
	double sqdist = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
	return sqrt(sqdist);
}

#endif