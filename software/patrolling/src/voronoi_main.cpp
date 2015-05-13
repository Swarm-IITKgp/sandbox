#include <iostream>
#include <cassert>
#include <cstdlib>
#include "voronoi_diagram_generator.h"
#include "coverage.h"
#include "patrolling.h"


using namespace cv;
using namespace std;


int main(int argc,char *argv[]) 
{	
	//Command line args are <map file> <num_agents> <radius>

	char* fname = argv[1];
	int n_agents = atoi(argv[2]);
	int radius = atoi(argv[3]); //In terms of pixels on map - scale as needed

	//Obtain image for map
	Mat img = imread(fname,0);
	Mat img_pat = imread(fname,1); //Coloured image used for patrolling object to display if needed

	//Initialize object
	Coverage cov_obj(img,n_agents);
	vector<Point> centroids;
	cov_obj.GetBestPositions(centroids); //Obtain initial centroids

	//Initialize with necessary values and run patrolling
	Patrolling pat_obj(img_pat,n_agents,radius,centroids);
	pat_obj.GetBestPatrol();
	
	
	return 0;
	
}



