#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class FaceRecognizer {
public:
    FaceRecognizer(const std::string& faceCascadePath);
    bool loadCascade(const std::string& faceCascadePath);
    std::vector<cv::Rect> detectFaces(const cv::Mat& image);

private:
    cv::CascadeClassifier faceCascade;
};
