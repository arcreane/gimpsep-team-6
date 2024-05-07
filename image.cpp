#include "image.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Image::Image(const string& path) {
	image = imread(path);
	dimensions = image.size();
}

Image::Image(const Mat& img) {
	image = img.clone();
	dimensions = image.size();
}

void Image::display() {
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", image);
	waitKey(0);
}

void Image::save(const string& path) {
	imwrite(path, image);
}

Size Image::getDimensions() const
{
	return dimensions;
}

Mat Image::getImage() const
{
	return image;
}

