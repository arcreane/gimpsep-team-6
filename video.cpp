#pragma once
#include "video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

Video::Video(const string& path) {
	capture.open(path);
	if (!capture.isOpened()) {
		throw runtime_error("Error opening video file");
	}
	frameCount = static_cast<int>(capture.get(CAP_PROP_FRAME_COUNT));
	fps = capture.get(CAP_PROP_FPS);
	dimensions = Size(static_cast<int>(capture.get(CAP_PROP_FRAME_WIDTH)), static_cast<int>(capture.get(CAP_PROP_FRAME_HEIGHT)));
	loadFrames();
}

Video::Video(const vector<Mat>& frames, double fps) : frames(frames), fps(fps) {
	if (frames.empty()) {
		throw runtime_error("Frames vector is empty");
	}
	frameCount = static_cast<int>(frames.size());
	dimensions = frames[0].size();
}

void Video::loadFrames() {
	Mat frame;
	while (capture.read(frame)) {
		frames.push_back(frame.clone());
	}
	capture.release();
}


void Video::save(const string& path) {
	if (frames.empty()) {
		throw runtime_error("No frames to save");
	}

	VideoWriter writer(path, VideoWriter::fourcc('a', 'v', 'c', '1'), fps, dimensions);
	if (!writer.isOpened()) {
		throw runtime_error("Error opening video writer");
	}
	for (const Mat& frame : this->getFrames()) {
		writer.write(frame);
	}
	writer.release();
}


void Video::display() {
	namedWindow("Video", WINDOW_AUTOSIZE);
	Mat frame;
	int frameIndex = 0;

	while (true) {
		frame = frames[frameIndex];
		if (frame.empty()) {
			break;
		}

		imshow("Video", frame);

		int key = waitKey(1000 / fps);
		if (key != -1) {
			break;
		}

		frameIndex = (frameIndex + 1) % frames.size();
	}
	destroyWindow("Video");
}

int Video::getFrameCount() const {
	return frameCount;
}

double Video::getFPS() const {
	return fps;
}

Size Video::getDimensions() const {
	return dimensions;
}

vector<Mat> Video::getFrames() const {
	return frames;
}

Mat Video::getFrame(int index) const {
	if (index < 0 || index >= frameCount) {
		throw out_of_range("Frame index out of range");
	}
	return frames[index];
}