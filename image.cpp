#include "image.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Image(const string& path) {
	image = imread(path);
	dimensions = image.size();
}

void display() {
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", image);
	waitKey(0);
}

void save(const string& path) {
	imwrite(path, image);
}

Size Image::getDimensions() const
{
	return dimensions;
}
