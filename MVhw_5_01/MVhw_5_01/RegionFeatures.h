#ifndef REGION_FEATURES_H

#include <opencv2/opencv.hpp>
#include <stddef.h>
using namespace std;
using namespace cv;

#define RUN_HEAD y
#define RUN_END z
enum class THRESHOLD_TYPE{
	THRESHOLD_BINARY = 0,
	THRESHOLD_INVERSE,
};
void mythreshold(const Mat& src, Mat& dst, uchar threshold, THRESHOLD_TYPE type);


void get_component(const Mat& src, vector<vector<Point3i>>& componentset, int area_threshold);
void display_component(string imname, const Mat& src, Mat& dst, vector<vector<Point3i>>& component,bool black);

int component_area(vector<Point3i>& component);
Point2i component_center(vector<Point3i>& component, int* _area);
vector<int> component_dmax(vector<Point3i>& component);
float component_circularity(vector<Point3i>& component, int dmax, int area);
#endif // !REGION_FEATURES_H

