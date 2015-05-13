/*This is the class for optimal coverage of a given map,
using a known number of agents*/

#ifndef COVERAGE
#define COVERAGE

#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "utils.h"

using namespace cv;

class Coverage
{
public:
	Coverage();
	Coverage(Mat& img, int n):map(img), n_agents(n){};
	~Coverage();

	void GetBestPositions(vector<Point>& positions);

private:
	Mat map;
	int n_agents;
	Point GetNearestFreeCentroid(Point centre);
	bool IsBlocked(Point p);
	void GetCentroids(Mat& img,vector<Point>& sites, vector<Point>& centroids);
	void GetStartingPoints(vector<Point>& sites);
	void DisplayPoints(vector<Point>& locations);

};

inline bool Coverage::IsBlocked(Point p)
{
	return (map.at<uchar>(p.y,p.x)==0);
}

#endif