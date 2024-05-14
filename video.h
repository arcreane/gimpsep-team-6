#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Video {
private:
	VideoCapture capture;
	Size dimensions;
public:
	Video(const string& path);
	void display();
	Size getDimensions() const;
	VideoCapture getVideoCapture() const;
};