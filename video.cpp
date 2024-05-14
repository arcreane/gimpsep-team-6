#include "video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

Video::Video(const string& path) {
	capture.open(path);
	if (!capture.isOpened()) {
		cout << "Error opening video stream file";
		exit(EXIT_FAILURE);
	}
	dimensions = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));
}

void Video::display() {
	namedWindow("Video", WINDOW_AUTOSIZE);
	Mat frame;

	while (true) {
		capture >> frame;
		if (frame.empty()) {
			break;
		}

		imshow("Video", frame);
		
		int key = waitKey(30);
		if (key != -1) {
			break;
		}
	}
	capture.release();
	destroyWindow("Video");
}

Size Video::getDimensions() const {
	return dimensions;
}

VideoCapture Video::getVideoCapture() const {
	return capture;
}