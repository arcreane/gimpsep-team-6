#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

class Video {
private:
	VideoCapture capture;
	int frameCount;
	double fps;
	Size dimensions;
	vector<Mat> frames;

	void loadFrames();

public:
    Video(const string& path);
    Video(const vector<Mat>& frames, double fps);

    void save(const string& path);
    void display();
    int getFrameCount() const;
    double getFPS() const;
    Size getDimensions() const;
    vector<Mat> getFrames() const;
    Mat getFrame(int index) const;
};