#include "faceRecognition.h"
#include <iostream>

using namespace cv;
using namespace std;

FaceRecognizer::FaceRecognizer(const std::string& faceCascadePath) {
    loadCascade(faceCascadePath);
}

bool FaceRecognizer::loadCascade(const std::string& faceCascadePath) {
    if (!faceCascade.load(faceCascadePath)) {
        cerr << "Error loading face cascade" << endl;
        return false;
    }
    return true;
}

std::vector<cv::Rect> FaceRecognizer::detectFaces(const cv::Mat& image) {
    vector<Rect> faces;
    Mat gray;

    // Convert to grayscale
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    equalizeHist(gray, gray);

    // Detect faces
    faceCascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    return faces;
}
