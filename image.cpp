#pragma once
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
	const std::string windowName = "Image";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, image);

	int key = waitKey(1);
	if (key == 13 || getWindowProperty(windowName, WND_PROP_VISIBLE) < 1) {
		if (getWindowProperty(windowName, WND_PROP_VISIBLE) >= 0) {
			destroyWindow(windowName);
		}
	}
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

