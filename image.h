#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Image {
	private:
		Mat image;
		Size dimensions;
	public: 
		Image(const string& path);
		Image(const Mat& img);
		void save(const string& path);
		void display();
		Size getDimensions() const;
		Mat getImage() const;
};